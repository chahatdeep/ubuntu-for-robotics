#!/bin/bash

#ROSBag LeftRect, pose and IMU
rosbag record /imu /pose /path /left_rgb_rect/image_rect_color

#ROSBag ALL:
#rosbag record /imu /pose /left_rgb/image /left_rgb_rect/image_rect_color /right_rgb/image /depth_map/image 
