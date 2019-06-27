#!/usr/bin/env python3
'''
badcapture.py : illustrates failure to capture frames from Leopard Imaging LI-USB30-M021 using ordinary OpenCV
                cv2.VideoCapture method. Result: big green blobby image!

Copyright (C) 2016 Simon D. Levy

This file is part of M021_V4L2.

M021_V4L2 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

M021_V4L2 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with M021_V4L2.  If not, see <http://www.gnu.org/licenses/>.
'''

import cv2
from time import time

cap = cv2.VideoCapture(0)

start = time()

count = 0

while True:

    # Capture frame-by-frame
    ret, frame = cap.read()

    count += 1

    # Display the resulting frame
    cv2.imshow('Okay for normal webcam, green blobs for M021',frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

elapsed = time() - start
print('%d frames in %3.2f seconds = %3.2f fps' % (count, elapsed, count/elapsed))

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
