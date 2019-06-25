/*
   m021_v4l2.h :  Header for LI-USB30-M021 V4L2 code

   Copyright (C) 2016 Simon D. Levy

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

#ifndef M021_H
#define M021_H

#include <linux/videodev2.h>
#include <libudev.h>
#include <pthread.h>
#include <stdint.h>
#include <stdbool.h>

// Error codes for reference
#define VDIN_OK                    0
#define VDIN_DEVICE_ERR           -1
#define VDIN_FORMAT_ERR           -2
#define VDIN_REQBUFS_ERR          -3
#define VDIN_ALLOC_ERR            -4
#define VDIN_RESOL_ERR            -5
#define VDIN_FBALLOC_ERR          -6
#define VDIN_UNKNOWN_ERR          -7
#define VDIN_DEQBUFS_ERR          -8
#define VDIN_DECODE_ERR           -9
#define VDIN_QUERYCAP_ERR        -10
#define VDIN_QUERYBUF_ERR        -11
#define VDIN_QBUF_ERR            -12
#define VDIN_MMAP_ERR            -13
#define VDIN_READ_ERR            -14
#define VDIN_STREAMON_ERR        -15
#define VDIN_STREAMOFF_ERR       -16
#define VDIN_DYNCTRL_ERR         -17

#define NB_BUFFER 4

typedef struct m021 {

    pthread_mutex_t mutex;

    struct   udev *udev;                  // pointer to a udev struct (lib udev)
    struct   udev_monitor *udev_mon;      // udev monitor
    int      udev_fd;                     // udev monitor file descriptor
    int      fd;                          // device file descriptor
    struct   v4l2_capability cap;         // v4l2 capability struct
    struct   v4l2_format fmt;             // v4l2 formar struct
    struct   v4l2_buffer buf;             // v4l2 buffer struct
    struct   v4l2_requestbuffers rb;      // v4l2 request buffers struct
    struct   v4l2_streamparm streamparm;  // v4l2 stream parameters struct
    void *   mem[NB_BUFFER];              // memory buffers for mmap driver frames
    uint32_t buff_length[NB_BUFFER];      // memory buffers length as set by VIDIOC_QUERYBUF
    uint32_t buff_offset[NB_BUFFER];      // memory buffers offset as set by VIDIOC_QUERYBUF
    int      isstreaming;                 // video stream flag (1- ON  0- OFF)
    int      available_exp[4];            // backward compatible (old v4l2 exposure menu interface)
    int      format;
    int      width;
    int      height;
    uint8_t * tmpbuffer;                  // temp buffer for decoding compressed data
    uint8_t * tmpbuffer1;                 // temp buffer for converting bayer16 to bayer8
    uint8_t * framebuffer;                // frame buffer (YUYV)

} m021_t;

/**
  * Initializes capture from M021 camera.
  * @param id numerical id of camera: 0 -> /dev/video0, etc.
  * @param m021 m021_t data structure to be initialized
  * @width image width
  * @height image height
  * @return 0 on success, nonzero on error (see error codes in m021_v4l2.h)
  * Width x Height possibilities are: 1280x720, 800x460, 640x480.
  * This routine should be called on its own thread, separate from the thread on which the
  * grab routines are called.
  */
int m021_init(int id, m021_t * m021, int width, int height);

/**
  * Grabs a YUYV image from the M021 camera.
  * @param m021 m021_t data structure intialized by m021_init
  * @param frame pre-allocated image frame buffer of appropriate size
  * @return 0 on success, nonzero on error (see error codes in m021_v4l2.h)
  * This routine should be called a separate thread from the thread on which m021_init was called.
  */
int m021_grab_yuyv(m021_t * m021, uint8_t * frame);

/**
  * Grabs a BGR image from the M021 camera.
  * @param m021 m021_t data structure intialized by m021_init
  * @param frame pre-allocated image frame buffer of appropriate size
  * @param bcorrect color correction for blue
  * @param gcorrect color correction for green
  * @param rcorrect color correction for red
  * @return 0 on success, nonzero on error (see error codes in m021_v4l2.h)
  * This routine should be called a separate thread from the thread on which m021_init was called.
  */
int m021_grab_bgr(m021_t * m021, uint8_t * frame, int8_t bcorrect, int8_t gcorrect, int8_t rcorrect);

/**
  * Frees storage allocated for m021 data structure.
  * @param m021 pointer to m021_t data structure to be freed
  * This routine should be called on its own thread, separate from the thread on which the
  * grab routines are called.
  */
void m021_free(m021_t * m021);

#endif

