#!/usr/bin/env python3

'''
   flowcap.py - Optical Flow from image capture  using Leopard Imageing M021 camear on Linux.
  
   Copyright (C) 2016 Simon D. Levy

   This file is part of M021_V4L2.

   M021_V4L2 is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   BreezySTM32 is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with M021_V4L2.  If not, see <http://www.gnu.org/licenses/>.
'''

SCALEDOWN  = 2
PYRSCALE   = 0.5
LEVELS     = 3
WINSIZE    = 10
ITERATIONS = 2
POLY_N     = 2
POLY_SIGMA = 1.2
MOVESTEP   = 16
LINE_BGR   = 0,255,0

import cv2
from m021v4l2 import Capture800x460
from time import time

if __name__ == '__main__':

    cap = Capture800x460()

    start = time()
    flowcount = 0
    prev_gray = None
    flow = None

    newsize = 800>>SCALEDOWN, 460>>SCALEDOWN

    while True:

        # Capture frame-by-frame
        ret, frame = cap.read()

        frame2 = cv2.resize(frame, newsize)

        gray = cv2.cvtColor(frame2, cv2.COLOR_BGR2GRAY)

        if prev_gray is not None:

            flow = cv2.calcOpticalFlowFarneback(prev_gray, gray, flow,
                    pyr_scale=PYRSCALE, levels=LEVELS, winsize=WINSIZE, iterations=ITERATIONS, 
                    poly_n=POLY_N, poly_sigma=POLY_SIGMA, flags=0) 

            for y in range(0, flow.shape[0], MOVESTEP):
                for x in range(0, flow.shape[1], MOVESTEP):
                    fx, fy = flow[y, x]
                    cv2.line(frame2, (x,y), (int(x+fx),int(y+fy)), LINE_BGR)
                    cv2.circle(frame2, (x,y), 1, LINE_BGR, -1)

        cv2.imshow('LI-USB30-M021', frame2)
        if cv2.waitKey(1) & 0xFF == 27:
            break

        prev_gray = gray
        flowcount += 1

    duration = time() - start

    capcount = cap.getCount()

    count = flowcount if capcount > flowcount else capcount

    print('%d (%d) frames in %3.3f seconds = %3.3f frames /sec' % (count, flowcount, duration, count/duration))

