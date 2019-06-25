/*
   flowcap.cpp - Optical Flow from image capture  using Leopard Imageing M021 camear on Linux.
  
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

#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace cv;
using namespace std;

#include "m021_v4l2_opencv.hpp"

#include <stdio.h>
#include <sys/timeb.h>

static const int   SCALEDOWN   = 1;

static const double PYRSCALE   = 0.5;
static const int    LEVELS     = 3;
static const int    WINSIZE    = 10;
static const int    ITERATIONS = 2;
static const int    POLY_N     = 2;
static const double POLY_SIGMA = 1.2;

// http://codepad.org/qPsNtwzp
static int getMilliCount(void){

    timeb tb;
    ftime(&tb);
    int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
    return nCount;
}

static void drawOptFlowMap(const Mat& flow, Mat& cflowmap, int step, const Scalar& color)
{
    double fx = 0;
    double fy = 0;

    for(int y = 0; y < cflowmap.rows; y += step)
        for(int x = 0; x < cflowmap.cols; x += step)
        {
            const Point2f& fxy = flow.at<Point2f>(y, x);
            fx += fxy.x;
            fy += fxy.y;
            line(cflowmap, Point(x,y), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)), color);
            circle(cflowmap, Point(x,y), 2, color, -1);
        }

    printf("%4d %4d\r", (int)fx, (int)fy);
    fflush(stdout);
}

int main(int argc, char** argv)
{
    Mat flow, frame, frame2, gray, prevgray;
    
    //M021_800x460_Capture cap(frame);
    M021_800x460_Capture cap(frame);

    int start = getMilliCount();
    int flowcount = 0;

    while (true) {

        resize(frame, frame2, Size(frame.cols>>SCALEDOWN, frame.rows>>SCALEDOWN));

        cvtColor(frame2, gray, COLOR_BGR2GRAY);

        if(!prevgray.empty() ) {
        
            calcOpticalFlowFarneback(prevgray, gray, flow, 
                PYRSCALE, LEVELS, WINSIZE, ITERATIONS, POLY_N, POLY_SIGMA, 0);
            drawOptFlowMap(flow, frame2, 16, Scalar(0, 255, 0));
            imshow("flow", frame2);
            flowcount++;
        }

        if(waitKey(1)>=0)
            break;

        std::swap(prevgray, gray);
    }

    double duration = (getMilliCount() - start) / 1000.;

    int capcount = cap.getCount();

    int count = capcount > flowcount ? flowcount : capcount;

    printf("%d (%d) frames in %3.3f seconds = %3.3f frames /sec \n", count, flowcount, duration, count/duration);

    return 0;
}
