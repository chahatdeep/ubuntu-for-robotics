'''
Python classes for Leopard Imaging LI-USB30-M021 on Linux

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
'''

import numpy as np
import libm021v4l2 as lib

# XXX This is kind of a sleazy implementation, partly in Python, partly in C extension.  
# XXX We probably should do the whole thing in C.

class _Capture(object):
    '''
    Abstract parent class; do not instantiate directly.
    '''

    def __init__(self, rows, cols, bcorrect, gcorrect, rcorrect):

        self.frame = np.zeros((rows,cols,3), dtype='uint8')

        lib.init(self.frame, bcorrect, gcorrect, rcorrect) 

    def read(self):
        '''
        Reads one frame of data from the camera.  Returns a pair (success,frame), where success is True or
        False, frame is an RxCx3 NumPy array of color image bytes.
        '''

        lib.acquire(self.frame)

        return True, self.frame

    def getCount(self):
        '''
        Returns the number of frames acquired since init. 
        '''

        return lib.count()

class Capture1280x720(_Capture):
    '''
    A class for capturing 1280x720 color images at 60 frames per second.
    Optional bcorrect, gcorrect, rcorrect values specify color-correction for
    red, green, and blue components, respectively.
    '''

    def __init__(self, bcorrect=50, gcorrect=0, rcorrect=50):

        _Capture.__init__(self, 720, 1280, bcorrect, gcorrect, rcorrect) 

class Capture800x460(_Capture):
    '''
    A class for capturing 800x460 color images at 90 frames per second
    Optional bcorrect, gcorrect, rcorrect values specify color-correction for
    red, green, and blue components, respectively.
    '''

    def __init__(self, bcorrect=50, gcorrect=0, rcorrect=50):

        _Capture.__init__(self, 460, 800, bcorrect, gcorrect, rcorrect) 

class Capture640x480(_Capture):
    '''
    A class for capturing 640x480 color images at 30 frames per second
    Optional bcorrect, gcorrect, rcorrect values specify color-correction for
    red, green, and blue components, respectively.
    '''

    def __init__(self, bcorrect=50, gcorrect=0, rcorrect=50):

        _Capture.__init__(self, 480, 640, bcorrect, gcorrect, rcorrect) 

class Capture1600x1200(_Capture):
    '''
    An experimental class for capturing 1600x1200 color images at 30 frames per
    second with the LI-C570 camera. Optional bcorrect, gcorrect, rcorrect values 
    specify color-correction for red, green, and blue components, respectively.
    '''

    def __init__(self, bcorrect=50, gcorrect=0, rcorrect=50):

        _Capture.__init__(self, 1200, 1600, bcorrect, gcorrect, rcorrect) 
