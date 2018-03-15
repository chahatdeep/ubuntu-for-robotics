#!/bin/bash
# Script for installing ROS
echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" &amp;amp;gt;ros-latest.list
sudo cp ros-latest.list /etc/apt/sources.list.d/







