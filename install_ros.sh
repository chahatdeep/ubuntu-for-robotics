#!/bin/bash
# Installation script to install ROS-Kinetic-base in Ubuntu 16.04
# Configure your Ubuntu repositories: Configure your Ubuntu repositories to allow "restricted," "universe," and "multiverse."

echo "You are using"
echo $(lsb_release -d)
echo "This script is build for Ubuntu 16.04.x LTS"
read -p "Do you want to continue? If yes, press <ENTER>."
echo "Setup up the source list"
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

echo "Adding packages and key to apt" && sleep 1
sudo sh -c '. /etc/lsb-release && echo "deb http://mirror.umd.edu/packages.ros.org/ros/ubuntu xenial main" > /etc/apt/sources.list.d/ros-latest.list' 
wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | sudo apt-key add - 
sudo apt-get update 

echo "DO NOT Install any ros-desktop/ros-desktop-full, it will destroy your *OpenCV* by installing PCL."
echo "Thus, installing ros-kinetic-ros-base."
echo "Install the specific packages you want later."
read -p "Press <ENTER> to continue."
sudo apt install ros-kinetic-ros-base

echo "Initializing rosdep"
sudo rosdep init
rosdep update

echo "Sourcing..."
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc

echo "Printing ROS Environment:"
printenv | grep ROS
