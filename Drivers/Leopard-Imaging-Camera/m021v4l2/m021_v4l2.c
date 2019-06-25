/*
   m021_v4l2.c :  Read from LI-USB30-M021 using V4L2

   Copyright (C) 2016 Simon D. Levy

   Adapted from v4l2uvc.c and colorspaces.c, downloaded from
   https://www.dropbox.com/s/uuujlt5rju0pgpj/guvcview_20160204.zip

   This file is part of M021_V4L2.

   M021_V4L2 is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   BreezySTM32 is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with M021_V4L2.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <libv4l2.h>
#include <sys/mman.h>
#include <errno.h>

#include "m021_v4l2.h"

#define G_NSEC_PER_SEC 1000000000LL

#define VDIN_SELETIMEOUT_ERR       2
#define VDIN_SELEFAIL_ERR          1

#define CLIP(value) (uint8_t)(((value)>0xFF)?0xff:(((value)<0)?0:(value)))

//set ioctl retries to 4 - linux uvc as increased timeout from 1000 to 3000 ms
#define IOCTL_RETRY 4

uint64_t s_ns_time_monotonic()
{
	static struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ((uint64_t) ts.tv_sec * G_NSEC_PER_SEC + (unsigned long long) ts.tv_nsec);
}


/*------------------------------- Color space conversions --------------------*/

// raw bayer functions 
// from libv4l bayer.c, (C) 2008 Hans de Goede <j.w.r.degoede@hhs.nl>
//Note: original bayer_to_bgr24 code from :
//  1394-Based Digital Camera Control Library
// 
//  Bayer pattern decoding functions
// 
//  Written by Damien Douxchamps and Frederic Devernay
static void convert_border_bayer_line_to_bgr24( uint8_t* bayer, uint8_t* adjacent_bayer,
	uint8_t *bgr, int width, bool start_with_green, bool blue_line)
{
	int t0, t1;

	if (start_with_green) 
	{
	/* First pixel */
		if (blue_line) 
		{
			*bgr++ = bayer[1];
			*bgr++ = bayer[0];
			*bgr++ = adjacent_bayer[0];
		} 
		else 
		{
			*bgr++ = adjacent_bayer[0];
			*bgr++ = bayer[0];
			*bgr++ = bayer[1];
		}
		/* Second pixel */
		t0 = (bayer[0] + bayer[2] + adjacent_bayer[1] + 1) / 3;
		t1 = (adjacent_bayer[0] + adjacent_bayer[2] + 1) >> 1;
		if (blue_line) 
		{
			*bgr++ = bayer[1];
			*bgr++ = t0;
			*bgr++ = t1;
		} 
		else 
		{
			*bgr++ = t1;
			*bgr++ = t0;
			*bgr++ = bayer[1];
		}
		bayer++;
		adjacent_bayer++;
		width -= 2;
	} 
	else 
	{
		/* First pixel */
		t0 = (bayer[1] + adjacent_bayer[0] + 1) >> 1;
		if (blue_line) 
		{
			*bgr++ = bayer[0];
			*bgr++ = t0;
			*bgr++ = adjacent_bayer[1];
		} 
		else 
		{
			*bgr++ = adjacent_bayer[1];
			*bgr++ = t0;
			*bgr++ = bayer[0];
		}
		width--;
	}

	if (blue_line) 
	{
		for ( ; width > 2; width -= 2) 
		{
			t0 = (bayer[0] + bayer[2] + 1) >> 1;
			*bgr++ = t0;
			*bgr++ = bayer[1];
			*bgr++ = adjacent_bayer[1];
			bayer++;
			adjacent_bayer++;

			t0 = (bayer[0] + bayer[2] + adjacent_bayer[1] + 1) / 3;
			t1 = (adjacent_bayer[0] + adjacent_bayer[2] + 1) >> 1;
			*bgr++ = bayer[1];
			*bgr++ = t0;
			*bgr++ = t1;
			bayer++;
			adjacent_bayer++;
		}
	} 
	else 
	{
		for ( ; width > 2; width -= 2) 
		{
			t0 = (bayer[0] + bayer[2] + 1) >> 1;
			*bgr++ = adjacent_bayer[1];
			*bgr++ = bayer[1];
			*bgr++ = t0;
			bayer++;
			adjacent_bayer++;

			t0 = (bayer[0] + bayer[2] + adjacent_bayer[1] + 1) / 3;
			t1 = (adjacent_bayer[0] + adjacent_bayer[2] + 1) >> 1;
			*bgr++ = t1;
			*bgr++ = t0;
			*bgr++ = bayer[1];
			bayer++;
			adjacent_bayer++;
		}
	}

	if (width == 2) 
	{
		/* Second to last pixel */
		t0 = (bayer[0] + bayer[2] + 1) >> 1;
		if (blue_line) 
		{
			*bgr++ = t0;
			*bgr++ = bayer[1];
			*bgr++ = adjacent_bayer[1];
		} 
		else 
		{
			*bgr++ = adjacent_bayer[1];
			*bgr++ = bayer[1];
			*bgr++ = t0;
		}
		/* Last pixel */
		t0 = (bayer[1] + adjacent_bayer[2] + 1) >> 1;
		if (blue_line) 
		{
			*bgr++ = bayer[2];
			*bgr++ = t0;
			*bgr++ = adjacent_bayer[1];
		}
		else 
		{
			*bgr++ = adjacent_bayer[1];
			*bgr++ = t0;
			*bgr++ = bayer[2];
		}
	} 
	else 
	{
		/* Last pixel */
		if (blue_line) 
		{
			*bgr++ = bayer[0];
			*bgr++ = bayer[1];
			*bgr++ = adjacent_bayer[1];
		} 
		else 
		{
			*bgr++ = adjacent_bayer[1];
			*bgr++ = bayer[1];
			*bgr++ = bayer[0];
		}
	}
}

/* From libdc1394, which on turn was based on OpenCV's Bayer decoding */
static void bayer_to_rgbbgr24(uint8_t *bayer,
	uint8_t *bgr, int width, int height,
	bool start_with_green, bool blue_line)
{
	/* render the first line */
	convert_border_bayer_line_to_bgr24(bayer, bayer + width, bgr, width,
		start_with_green, blue_line);
	bgr += width * 3;

	/* reduce height by 2 because of the special case top/bottom line */
	for (height -= 2; height; height--) 
	{
		int t0, t1;
		/* (width - 2) because of the border */
		uint8_t *bayerEnd = bayer + (width - 2);

		if (start_with_green) 
		{
			/* OpenCV has a bug in the next line, which was
			t0 = (bayer[0] + bayer[width * 2] + 1) >> 1; */
			t0 = (bayer[1] + bayer[width * 2 + 1] + 1) >> 1;
			/* Write first pixel */
			t1 = (bayer[0] + bayer[width * 2] + bayer[width + 1] + 1) / 3;
			if (blue_line) 
			{
				*bgr++ = t0;
				*bgr++ = t1;
				*bgr++ = bayer[width];
			} 
			else 
			{
				*bgr++ = bayer[width];
				*bgr++ = t1;
				*bgr++ = t0;
			}

			/* Write second pixel */
			t1 = (bayer[width] + bayer[width + 2] + 1) >> 1;
			if (blue_line) 
			{
				*bgr++ = t0;
				*bgr++ = bayer[width + 1];
				*bgr++ = t1;
			} 
			else 
			{
				*bgr++ = t1;
				*bgr++ = bayer[width + 1];
				*bgr++ = t0;
			}
			bayer++;
		} 
		else 
		{
			/* Write first pixel */
			t0 = (bayer[0] + bayer[width * 2] + 1) >> 1;
			if (blue_line) 
			{
				*bgr++ = t0;
				*bgr++ = bayer[width];
				*bgr++ = bayer[width + 1];
			} 
			else 
			{
				*bgr++ = bayer[width + 1];
				*bgr++ = bayer[width];
				*bgr++ = t0;
			}
		}

		if (blue_line) 
		{
			for (; bayer <= bayerEnd - 2; bayer += 2) 
			{
				t0 = (bayer[0] + bayer[2] + bayer[width * 2] +
					bayer[width * 2 + 2] + 2) >> 2;
				t1 = (bayer[1] + bayer[width] +
					bayer[width + 2] + bayer[width * 2 + 1] +
					2) >> 2;
				*bgr++ = t0;
				*bgr++ = t1;
				*bgr++ = bayer[width + 1];

				t0 = (bayer[2] + bayer[width * 2 + 2] + 1) >> 1;
				t1 = (bayer[width + 1] + bayer[width + 3] +
					1) >> 1;
				*bgr++ = t0;
				*bgr++ = bayer[width + 2];
				*bgr++ = t1;
			}
		} 
		else 
		{
			for (; bayer <= bayerEnd - 2; bayer += 2) 
			{
				t0 = (bayer[0] + bayer[2] + bayer[width * 2] +
					bayer[width * 2 + 2] + 2) >> 2;
				t1 = (bayer[1] + bayer[width] +
					bayer[width + 2] + bayer[width * 2 + 1] +
					2) >> 2;
				*bgr++ = bayer[width + 1];
				*bgr++ = t1;
				*bgr++ = t0;

				t0 = (bayer[2] + bayer[width * 2 + 2] + 1) >> 1;
				t1 = (bayer[width + 1] + bayer[width + 3] +
					1) >> 1;
				*bgr++ = t1;
				*bgr++ = bayer[width + 2];
				*bgr++ = t0;
			}
		}

		if (bayer < bayerEnd) 
		{
			/* write second to last pixel */
			t0 = (bayer[0] + bayer[2] + bayer[width * 2] +
				bayer[width * 2 + 2] + 2) >> 2;
			t1 = (bayer[1] + bayer[width] +
				bayer[width + 2] + bayer[width * 2 + 1] +
				2) >> 2;
			if (blue_line) 
			{
				*bgr++ = t0;
				*bgr++ = t1;
				*bgr++ = bayer[width + 1];
			} 
			else 
			{
				*bgr++ = bayer[width + 1];
				*bgr++ = t1;
				*bgr++ = t0;
			}
			/* write last pixel */
			t0 = (bayer[2] + bayer[width * 2 + 2] + 1) >> 1;
			if (blue_line) 
			{
				*bgr++ = t0;
				*bgr++ = bayer[width + 2];
				*bgr++ = bayer[width + 1];
			} 
			else 
			{
				*bgr++ = bayer[width + 1];
				*bgr++ = bayer[width + 2];
				*bgr++ = t0;
			}
			bayer++;
		} 
		else
		{
			/* write last pixel */
			t0 = (bayer[0] + bayer[width * 2] + 1) >> 1;
			t1 = (bayer[1] + bayer[width * 2 + 1] + bayer[width] + 1) / 3;
			if (blue_line) 
			{
				*bgr++ = t0;
				*bgr++ = t1;
				*bgr++ = bayer[width + 1];
			} 
			else 
			{
				*bgr++ = bayer[width + 1];
				*bgr++ = t1;
				*bgr++ = t0;
			}
		}

		/* skip 2 border pixels */
		bayer += 2;

		blue_line = !blue_line;
		start_with_green = !start_with_green;
	}

	/* render the last line */
	convert_border_bayer_line_to_bgr24(bayer + width, bayer, bgr, width,
		!start_with_green, !blue_line);
}

static void 
bayer_to_rgb24(uint8_t *pBay, uint8_t *pRGB24, int width, int height)
{
    bayer_to_rgbbgr24(pBay, pRGB24, width, height, true, true);
}

static void 
bayer_to_bgr24(uint8_t *pBay, uint8_t *pRGB24, int width, int height)
{
    bayer_to_rgbbgr24(pBay, pRGB24, width, height, true, false);
}

static void
rgb2yuyv(uint8_t *prgb, uint8_t *pyuv, int width, int height) 
{

	int i=0;
	for(i=0;i<(width*height*3);i=i+6) 
	{
		/* y */ 
		*pyuv++ =CLIP(0.299 * (prgb[i] - 128) + 0.587 * (prgb[i+1] - 128) + 0.114 * (prgb[i+2] - 128) + 128);
		/* u */
		*pyuv++ =CLIP(((- 0.147 * (prgb[i] - 128) - 0.289 * (prgb[i+1] - 128) + 0.436 * (prgb[i+2] - 128) + 128) +
			(- 0.147 * (prgb[i+3] - 128) - 0.289 * (prgb[i+4] - 128) + 0.436 * (prgb[i+5] - 128) + 128))/2);
		/* y1 */ 
		*pyuv++ =CLIP(0.299 * (prgb[i+3] - 128) + 0.587 * (prgb[i+4] - 128) + 0.114 * (prgb[i+5] - 128) + 128); 
		/* v*/
		*pyuv++ =CLIP(((0.615 * (prgb[i] - 128) - 0.515 * (prgb[i+1] - 128) - 0.100 * (prgb[i+2] - 128) + 128) +
			(0.615 * (prgb[i+3] - 128) - 0.515 * (prgb[i+4] - 128) - 0.100 * (prgb[i+5] - 128) + 128))/2);
	}
}



/* ioctl with a number of retries in the case of failure
* args:
* fd - device descriptor
* IOCTL_X - ioctl reference
* arg - pointer to ioctl data
* returns - ioctl result
*/
static int xioctl(int fd, int IOCTL_X, void *arg)
{
	int ret = 0;
	int tries= IOCTL_RETRY;
	do
	{
		ret = v4l2_ioctl(fd, IOCTL_X, arg);
	}
	while (ret && tries-- &&
			((errno == EINTR) || (errno == EAGAIN) || (errno == ETIMEDOUT)));

	if (ret && (tries <= 0)) fprintf(stderr, "ioctl (%i) retried %i times - giving up: %s)\n", IOCTL_X, IOCTL_RETRY, strerror(errno));

	return ret;
}

static int check_videoIn(const char * devicename, m021_t *vd)
{
	if (vd == NULL)
		return VDIN_ALLOC_ERR;

	memset(&vd->cap, 0, sizeof(struct v4l2_capability));

	if ( xioctl(vd->fd, VIDIOC_QUERYCAP, &vd->cap) < 0 )
	{
		perror("VIDIOC_QUERYCAP error");
		return VDIN_QUERYCAP_ERR;
	}

	if ( ( vd->cap.capabilities & V4L2_CAP_VIDEO_CAPTURE ) == 0)
	{
		fprintf(stderr, "Error opening device %s: video capture not supported.\n", devicename);
		return VDIN_QUERYCAP_ERR;
	}
	if (!(vd->cap.capabilities & V4L2_CAP_STREAMING))
	{
		fprintf(stderr, "%s does not support streaming i/o\n", devicename);
		return VDIN_QUERYCAP_ERR;
	}

	printf("Init. %s (location: %s)\n", vd->cap.card, vd->cap.bus_info);

	struct v4l2_frmivalenum fival;
	memset(&fival, 0, sizeof(fival));
	fival.index = 0;
	fival.pixel_format = 1448695129;
	fival.width = 800;
	fival.height = 460;

    while (xioctl(vd->fd, VIDIOC_ENUM_FRAMEINTERVALS, &fival) == 0) {
        fival.index++;
        printf("%u/%u, ", fival.discrete.numerator, fival.discrete.denominator);
        fflush(stdout);
    }

    return VDIN_OK;
}

static int unmap_buff(m021_t *vd)
{
    int i=0;
    int ret=0;

    for (i = 0; i < NB_BUFFER; i++)
    {
        // unmap old buffer
        if((vd->mem[i] != MAP_FAILED) && vd->buff_length[i])
            if((ret=v4l2_munmap(vd->mem[i], vd->buff_length[i]))<0)
            {
                perror("couldn't unmap buff");
            }
    }
    return ret;
}

static int map_buff(m021_t *vd)
{
    int i = 0;
    // map new buffer
    for (i = 0; i < NB_BUFFER; i++)
    {
        vd->mem[i] = v4l2_mmap( NULL, // start anywhere
			vd->buff_length[i],
			PROT_READ | PROT_WRITE,
			MAP_SHARED,
			vd->fd,
			vd->buff_offset[i]);
		if (vd->mem[i] == MAP_FAILED)
		{
			perror("Unable to map buffer");
			return VDIN_MMAP_ERR;
		}
	}

	return (0);
}

static int query_buff(m021_t *vd)
{
    int i=0;
    int ret=0;

    for (i = 0; i < NB_BUFFER; i++)
    {
        memset(&vd->buf, 0, sizeof(struct v4l2_buffer));
        vd->buf.index = i;
        vd->buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        vd->buf.memory = V4L2_MEMORY_MMAP;
        ret = xioctl(vd->fd, VIDIOC_QUERYBUF, &vd->buf);
        if (ret < 0)
        {
            perror("VIDIOC_QUERYBUF - Unable to query buffer");
            if(errno == EINVAL)
            {
                fprintf(stderr, "trying with read method instead\n");
            }
            return VDIN_QUERYBUF_ERR;
        }
        if (vd->buf.length <= 0)
            fprintf(stderr, "WARNING VIDIOC_QUERYBUF - buffer length is %d\n",
                    vd->buf.length);

        vd->buff_length[i] = vd->buf.length;
        vd->buff_offset[i] = vd->buf.m.offset;
    }

    // map the new buffers
    return map_buff(vd);
}

static int queue_buff(m021_t *vd)
{
    int i=0;
    int ret=0;
    for (i = 0; i < NB_BUFFER; ++i)
    {
        memset(&vd->buf, 0, sizeof(struct v4l2_buffer));
        vd->buf.index = i;
        vd->buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        vd->buf.memory = V4L2_MEMORY_MMAP;
        ret = xioctl(vd->fd, VIDIOC_QBUF, &vd->buf);
        if (ret < 0)
        {
            perror("VIDIOC_QBUF - Unable to queue buffer");
            return VDIN_QBUF_ERR;
        }
    }
    return VDIN_OK;
}

static int video_enable(m021_t *vd)
{
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    int ret=0;
    ret = xioctl(vd->fd, VIDIOC_STREAMON, &type);
    if (ret < 0)
    {
        perror("VIDIOC_STREAMON - Unable to start capture");
        return VDIN_STREAMON_ERR;
    }
    vd->isstreaming = 1;
    return 0;
}

static int init_v4l2(m021_t *vd, int *format, int width, int height)
{
	int ret = 0;

	// set format
	vd->fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	vd->fmt.fmt.pix.width = width;
	vd->fmt.fmt.pix.height = height;
	vd->fmt.fmt.pix.pixelformat = *format;
	vd->fmt.fmt.pix.field = V4L2_FIELD_ANY;

	ret = xioctl(vd->fd, VIDIOC_S_FMT, &vd->fmt);
	if (ret < 0)
	{
		perror("VIDIOC_S_FORMAT - Unable to set format");
        return VDIN_FORMAT_ERR;
    }
    if (((int)vd->fmt.fmt.pix.width != width) ||
            ((int)vd->fmt.fmt.pix.height != height))
    {
        fprintf(stderr, "Requested Format unavailable: get width %d height %d \n",
                vd->fmt.fmt.pix.width, vd->fmt.fmt.pix.height);
    }

    // request buffers
    memset(&vd->rb, 0, sizeof(struct v4l2_requestbuffers));
    vd->rb.count = NB_BUFFER;
    vd->rb.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    vd->rb.memory = V4L2_MEMORY_MMAP;

    ret = xioctl(vd->fd, VIDIOC_REQBUFS, &vd->rb);
    if (ret < 0)
    {
        perror("VIDIOC_REQBUFS - Unable to initte buffers");
        return VDIN_REQBUFS_ERR;
    }
    // map the buffers
    if (query_buff(vd))
    {
        //delete requested buffers
        //no need to unmap as mmap failed for sure
        memset(&vd->rb, 0, sizeof(struct v4l2_requestbuffers));
        vd->rb.count = 0;
        vd->rb.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        vd->rb.memory = V4L2_MEMORY_MMAP;
        if(xioctl(vd->fd, VIDIOC_REQBUFS, &vd->rb)<0)
            perror("VIDIOC_REQBUFS - Unable to delete buffers");
        return VDIN_QUERYBUF_ERR;
    }
    // Queue the buffers
    if (queue_buff(vd))
    {
        //delete requested buffers
        unmap_buff(vd);
        memset(&vd->rb, 0, sizeof(struct v4l2_requestbuffers));
        vd->rb.count = 0;
        vd->rb.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        vd->rb.memory = V4L2_MEMORY_MMAP;
        if(xioctl(vd->fd, VIDIOC_REQBUFS, &vd->rb)<0)
            perror("VIDIOC_REQBUFS - Unable to delete buffers");
        return VDIN_QBUF_ERR;
    }

    return VDIN_OK;
}

static void frame_init(uint8_t *framebuffer, int width, int height)
{
    size_t framebuf_size = (width * height << 1); //2 bytes per pixel

    unsigned i = 0;

    // set framebuffer to black (y=0x00 u=0x80 v=0x80) by default
    for (i=0; i<(framebuf_size-4); i+=4)
    {
        framebuffer[i]=0x00;  //Y
        framebuffer[i+1]=0x80;//U
        framebuffer[i+2]=0x00;//Y
        framebuffer[i+3]=0x80;//V
    }
}

static void clear_v4l2(m021_t *videoIn)
{
	v4l2_close(videoIn->fd);
	videoIn->fd=0;

    pthread_mutex_destroy(&videoIn->mutex);
}

static void bayer16_convert_bayer8(int16_t *inbuf, uint8_t *outbuf, int width, int height, int shift)
{
	int i = 0, j = 0;

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			outbuf[i * width + j] = (inbuf[i * width + j] >> shift);
		}
	}
}

static int check_frame_available(m021_t *vd)
{
    int ret = VDIN_OK;
    fd_set rdset;
	struct timeval timeout;
	//make sure streaming is on
	if (!vd->isstreaming)
		if (video_enable(vd))
		{
			return VDIN_STREAMON_ERR;
		}

	FD_ZERO(&rdset);
	FD_SET(vd->fd, &rdset);
	timeout.tv_sec = 1; // 1 sec timeout
	timeout.tv_usec = 0;
	// select - wait for data or timeout
	ret = select(vd->fd + 1, &rdset, NULL, NULL, &timeout);
	if (ret < 0)
	{
		perror(" Could not grab image (select error)");
		return VDIN_SELEFAIL_ERR;
	}
	else if (ret == 0)
	{
		perror(" Could not grab image (select timeout)");
		return VDIN_SELETIMEOUT_ERR;
	}
	else if ((ret > 0) && (FD_ISSET(vd->fd, &rdset)))
		return VDIN_OK;
	else
		return VDIN_UNKNOWN_ERR;

}


int m021_grab(m021_t * common)
{
    int ret = check_frame_available(common);

    if (ret < 0)
        return ret;

    /* dequeue the buffers */
    memset(&common->buf, 0, sizeof(struct v4l2_buffer));
    common->buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    common->buf.memory = V4L2_MEMORY_MMAP;

    ret = xioctl(common->fd, VIDIOC_DQBUF, &common->buf);
    if (ret < 0)
    {
        perror("VIDIOC_DQBUF - Unable to dequeue buffer ");
        ret = VDIN_DEQBUFS_ERR;
        return ret;
    }

    ret = xioctl(common->fd, VIDIOC_QBUF, &common->buf);
    if (ret < 0)
    {
        perror("VIDIOC_QBUF - Unable to queue buffer");
        ret = VDIN_QBUF_ERR;
    }

    return ret;
}

static void add(uint8_t * val, int8_t inc)
{
    int16_t newval = *val + inc;

    if (newval < 0)
       *val = 0;

    else if (newval > 255)
        *val = 255;

    else 
        * val = newval;
}

static void color_correct(uint8_t * bgr, int width, int height, int8_t bcorrect, int8_t gcorrect, int8_t rcorrect)
{
    int k;
    for (k=0; k<width*height*3; k+=3) {
        add(&bgr[k],   bcorrect);
        add(&bgr[k+1], gcorrect);
        add(&bgr[k+2], rcorrect);
    }
}

// =============================================================================================

int m021_init(int id, m021_t * vd, int width, int height)
{
    int ret = VDIN_OK;

    vd->width = width;
    vd->height = height;

    vd->framebuffer = (uint8_t *)malloc(width*height*2);
    vd->tmpbuffer   = (uint8_t *)malloc(width*height*3);
    vd->tmpbuffer1  = (uint8_t *)malloc(width*height*3);

    vd->udev = udev_new();

    pthread_mutex_init(&vd->mutex, NULL);

	vd->available_exp[0]=-1;
	vd->available_exp[1]=-1;
	vd->available_exp[2]=-1;
	vd->available_exp[3]=-1;

    /*start udev device monitoring*/
    /* Set up a monitor to monitor v4l2 devices */
    if(vd->udev)
    {
        vd->udev_mon = udev_monitor_new_from_netlink(vd->udev, "udev");
        udev_monitor_filter_add_match_subsystem_devtype(vd->udev_mon, "video4linux", NULL);
        udev_monitor_enable_receiving(vd->udev_mon);
        vd->udev_fd = udev_monitor_get_fd(vd->udev_mon);
    }

    char devname[20];
    sprintf(devname, "/dev/video%d", id);

    if ((vd->fd = v4l2_open(devname, O_RDWR | O_NONBLOCK, 0)) < 0)
    {
        perror("ERROR opening V4L interface");
        ret = VDIN_DEVICE_ERR;
        clear_v4l2(vd);
        return ret;
    }

	//reset v4l2_format
	memset(&vd->fmt, 0, sizeof(struct v4l2_format));

	// populate video capabilities structure array
	// should only be called after all m021 struct elements
	// have been initialized
	if((ret = check_videoIn(devname, vd)) != VDIN_OK)
	{
		clear_v4l2(vd);
		return ret;
	}

	ret = 0; //clean ret code

    vd->format = 0x56595559;

    if ((ret=init_v4l2(vd, &vd->format, width, height)) < 0)
    {
        fprintf(stderr, "Init v4L2 failed !! \n");
        clear_v4l2(vd);
    }


    if (!ret)
        frame_init(vd->framebuffer, width, height);

    return ret;
}

int m021_grab_yuyv(m021_t * vd, uint8_t * frame)
{
    int ret = m021_grab(vd);

    if (!ret) {
        bayer16_convert_bayer8((int16_t *)vd->mem[vd->buf.index], vd->tmpbuffer1, vd->width, vd->height, 4);
        bayer_to_rgb24 (vd->tmpbuffer1, vd->tmpbuffer, vd->width, vd->height);
        rgb2yuyv (vd->tmpbuffer, vd->framebuffer, vd->width, vd->height);
        memcpy(frame, vd->framebuffer, vd->width * vd->height * 2);
    }

    return ret;
}

int m021_grab_bgr(m021_t * vd, uint8_t * frame, int8_t bcorrect, int8_t gcorrect, int8_t rcorrect)
{
    int ret = m021_grab(vd);

    if (!ret) {
        bayer16_convert_bayer8((int16_t *)vd->mem[vd->buf.index], vd->tmpbuffer1, vd->width, vd->height, 4);
        bayer_to_bgr24(vd->tmpbuffer1, vd->tmpbuffer, vd->width, vd->height);
        color_correct(vd->tmpbuffer, vd->width, vd->height, bcorrect, gcorrect, rcorrect);
        memcpy(frame, vd->tmpbuffer, vd->width * vd->height * 3);
    }

    return ret;
}

void m021_free(m021_t * vd)
{
    free(vd->framebuffer);
    free(vd->tmpbuffer);
    free(vd->tmpbuffer1);
}
