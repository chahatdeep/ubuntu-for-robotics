/*
  
   m021_v4l2_opencv.cpp - C++ source for Leopard Imaging M021 camera capture using OpenCV on Linux.
  
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

#include "m021_v4l2.h"
#include "m021_v4l2_opencv.hpp"
#include "m021_thread_support.h"

#include <stdio.h>

M021_Capture::M021_Capture(Mat & mat, int width, int height, int bcorrect, int gcorrect, int rcorrect)
{
    this->bcorrect = bcorrect;
    this->gcorrect = gcorrect;
    this->rcorrect = rcorrect;

    mat = Mat(height, width, CV_8UC3);

    m021_thread_data_t * thread_data = new m021_thread_data_t;

    m021_thread_start(thread_data, mat.rows, mat.cols, mat.data, bcorrect, gcorrect, rcorrect);

   this->data = thread_data;
}
        
M021_Capture::~M021_Capture(void)
{
    free(this->data);
}

unsigned long long M021_Capture::getCount(void) 
{
    m021_thread_data_t * data = (m021_thread_data_t *)this->data;

    return data->count;
}
