#!/bin/bash
# If using usb 3.0 or above, should turn it down in BIOS(Advance->USB->xhci) disable xhci

# Install dependencies:
sudo apt-get install ros-kinetic-rgbd-launch ros-kinetic-openni2-camera ros-kinetic-openni2-launch

# Install package rqt and useful plugins:
sudo apt-get install ros-kinetic-rqt ros-kinetic-rqt-common-plugins ros-kinetic-rqt-robot-plugins

# Open Terminal 1
roscore

# Open Terminal 2
roslaunch openni2_launch openni2.launch

# Open Terminal 3
# In the “rqt” window select “Plugins” -> “Visualization” -> “Image View“
rqt
