#!/usr/bin/env python3

'''
lic570_capture.py : capture frames from Leopard Imaging LI-USB30-C570 camera and display them using OpenCV

Copyright (C) 2017 Simon D. Levy

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
'''

import cv2
from m021v4l2 import Capture1600x1200
from time import time

cap = Capture1600x1200()

start = time()

while True:

    # Capture frame-by-frame
    ret, frame = cap.read()

    # Display the resulting frame
    cv2.imshow('LI-USB30-M021',frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

count = cap.getCount()
elapsed = time() - start
print('%d frames in %3.2f seconds = %3.2f fps' % (count, elapsed, count/elapsed))

# When everything done, release the capture
cv2.destroyAllWindows()
