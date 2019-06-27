#!/usr/bin/env python

'''
capture.py : capture frames from Leopard Imaging LI-USB30-M021 camera and display them using OpenCV

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

import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Image
import std_msgs.msg
import sys
# sys.path.remove('/opt/ros/kinetic/lib/python2.7/dist-packages')
import cv2
from m021v4l2 import Capture800x460
from time import time
from cv_bridge import CvBridge, CvBridgeError

def talker():
	cap = Capture800x460()
	start = time()
	bridge = CvBridge()

	image_pub = rospy.Publisher('image_raw', Image,queue_size=10)
	rospy.init_node('LeopardImg', anonymous=True)
	rate = rospy.Rate(60) #60hz
	while not rospy.is_shutdown():
		# hello_str = "hello world %s" % rospy.get_time()

		h = std_msgs.msg.Header()
		h.stamp = rospy.Time.now()

		# Capture frame-by-frame
		ret, frame = cap.read()

		# converting it to CvBridge format
		img_bridge_format = bridge.cv2_to_imgmsg(frame, "bgr8")
		#publish opencv image after 
		try:
			image_pub.publish(img_bridge_format)
		except CvBridgeError as e:
			print(e)


		# Display the resulting frame
		# cv2.imshow('LI-USB30-M021',frame)
		# if cv2.waitKey(1) & 0xFF == 27:
		#     break
		rate.sleep()

	count = cap.getCount()
	elapsed = time() - start
	print('%d frames in %3.2f seconds = %3.2f fps' % (count, elapsed, count/elapsed))

	# When everything done, release the capture
	# cv2.destroyAllWindows()

if __name__ == '__main__':
	try:
		talker()
	except rospy.ROSInterruptException:
		pass
