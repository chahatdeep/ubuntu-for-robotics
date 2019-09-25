#!/bin/bash
# Script for Installing ROS Kinetic Base Only. Can be adapted for other versions as well.
# Author: Chahat Deep Singh
# Date: Sep 25, 2019
########################################

# Configure your Ubuntu repositories: Configure your Ubuntu repositories to allow "restricted," "universe," and "multiverse."

echo "You are using"
echo $(lsb_release -d)
echo "This script is build for Ubuntu 16.04.x LTS"
read -p "Do you want to continue? If yes, press <ENTER>."
sleep 2
echo "Installing ROS-Kinetic..."
echo "Setting up the source list"
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

# Add Keys:
# echo "Adding keys..."
# sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654

# Or use this to add keys:
echo "Adding packages and keys to apt manager" && sleep 1
sudo sh -c '. /etc/lsb-release && echo "deb http://mirror.umd.edu/packages.ros.org/ros/ubuntu xenial main" > /etc/apt/sources.list.d/ros-latest.list' 
wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | sudo apt-key add - 
sudo apt-get update 

# Installing ROS-Kinetic-ROS-Base
echo "DO NOT Install any ros-desktop/ros-desktop-full, it will destroy your *OpenCV* by installing PCL."
sleep 1
echo "Thus, installing ros-kinetic-ros-base."
echo "Install the specific packages you want later."
read -p "Press <ENTER> to continue."
sudo apt install ros-kinetic-ros-base

# Initializing and updating rosdep
echo "Initializing rosdep"
sudo rosdep init
rosdep update

# Installing RVIZ and RQT
echo "Installing rviz and rqt"
sleep 1
sudo apt install ros-kinetic-rviz
sudo apt install ros-kinetic-rqt

echo "Sourcing to bashrc file..."
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc

echo "Printing ROS Environment:"
printenv | grep ROS
