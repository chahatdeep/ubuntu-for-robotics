/*
   m021_thread_support.h : Supports threading for LI-USB30-M021 camera with OpenCV

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

#include <pthread.h>
#include <stdint.h>

typedef struct {

    int rows;
    int cols;
    uint8_t * bytes;
    pthread_t video_thread;
    pthread_mutex_t lock;
    unsigned long long count;
    int bcorrect;
    int gcorrect;
    int rcorrect;

} m021_thread_data_t;

void m021_thread_start(m021_thread_data_t * data, int rows, int cols, uint8_t * bytes, 
        int bcorrect, int gcorrect, int rcorrect);
