/*
   m021_thread_support.c : Supports threading for LI-USB30-M021 camera with OpenCV

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

#include "m021_thread_support.h"
#include "m021_v4l2.h"

#include <stdio.h>

static void * loop(void * arg)
{

    m021_thread_data_t * data = (m021_thread_data_t *)arg;
    pthread_mutex_t lock = data->lock;

    m021_t cap;
    m021_init(0, &cap, data->cols, data->rows);

    data->count = 0;

    while (true) {

        pthread_mutex_lock(&lock);

        m021_grab_bgr(&cap, data->bytes, data->bcorrect, data->gcorrect, data->rcorrect);

        pthread_mutex_unlock(&lock);

        data->count++;
    }

    m021_free(&cap);

    return (void *)0;
}

void m021_thread_start(m021_thread_data_t * data, int rows, int cols, uint8_t * bytes, 
        int bcorrect, int gcorrect, int rcorrect)
{
    pthread_mutex_t lock;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init failed\n");
        return;
    }

    data->rows = rows;
    data->cols = cols;
    data->bytes = bytes;
    data->lock = lock;
    data->bcorrect = bcorrect;
    data->gcorrect = gcorrect;
    data->rcorrect = rcorrect;

    if (pthread_create(&data->video_thread, NULL, loop, data)) 
        printf("\nFailed to create thread\n");
}


