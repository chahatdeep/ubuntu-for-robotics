/*
  
   m021_v4l2_opencv.hpp - C++ headers for Leopard Imaging M021 camera capture using OpenCV on Linux.
  
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


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

class M021_Capture {

    private:

        int bcorrect;
        int gcorrect;
        int rcorrect;

    protected:

        M021_Capture(Mat & mat, int width, int height, int bcorrect, int gcorrect, int rcorrect);

        ~M021_Capture(void);

        void * data;

    public:

        unsigned long long getCount(void);
};

/**
  * A class for capturing 1280x720 images at 60 frames per second.
  */
class M021_1280x720_Capture : public M021_Capture{

    public:

        /**
          * Constructs an object for 1280x720 capture.
          * Launches a new thread for running the capture.
          * @param mat Empty Mat that will be allocated by this constructor and filled with successive image frames.
          * @param bcorrect correction offset for blue component
          * @param rcorrect correction offset for green component
          * @param gcorrect correction offset for red component
          */
        M021_1280x720_Capture(Mat & mat, int bcorrect=50, int gcorrect=0, int rcorrect=50) : 
            M021_Capture(mat, 1280, 720, bcorrect, gcorrect, rcorrect) {}

         /**
           * Returns the count of image frames captured thus far.
           * @return frame count
           */
         unsigned long long getCount(void) { return M021_Capture::getCount(); }
};

/**
  * A class for capturing 800x460 images at 90 frames per second.
  */
class M021_800x460_Capture : public M021_Capture{

    public:

        /**
          * Constructs an object for 800x460 capture.
          * Launches a new thread for running the capture.
          * @param mat Empty Mat that will be allocated by this constructor and filled with successive image frames.
          * @param bcorrect correction offset for blue component
          * @param rcorrect correction offset for green component
          * @param gcorrect correction offset for red component
          */
         M021_800x460_Capture(Mat & mat, int bcorrect=50, int gcorrect=0, int rcorrect=50): 
             M021_Capture(mat, 800, 460, bcorrect, gcorrect, rcorrect) {}

         /**
           * Returns the count of image frames captured thus far.
           * @return frame count
           */
        unsigned long long getCount(void) { return M021_Capture::getCount(); }
};

/**
  * A class for capturing 640x480 images at 30 frames per second.
  */
class M021_640x480_Capture : public M021_Capture{

    public:

        /**
          * Constructs an object for 640x480 capture.
          * Launches a new thread for running the capture.
          * @param mat Empty Mat that will be allocated by this constructor and filled with successive image frames.
          * @param bcorrect correction offset for blue component
          * @param rcorrect correction offset for green component
          * @param gcorrect correction offset for red component
          */
         M021_640x480_Capture(Mat & mat, int bcorrect=50, int gcorrect=0, int rcorrect=50) : 
             M021_Capture(mat, 640, 480, bcorrect, gcorrect, rcorrect) {}

         /**
           * Returns the count of image frames captured thus far.
           * @return frame count
           */
         unsigned long long getCount(void) { return M021_Capture::getCount(); }
};
