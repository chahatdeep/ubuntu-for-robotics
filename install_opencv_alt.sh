#!/usr/bin/env bash

# Alternative Installation script for Opencv3 on Ubuntu 16.04 only.
# Reference: http://www.pyimagesearch.com/2016/10/24/ubuntu-16-04-how-to-install-opencv/


#Step1: Install OpenCV3 dependencies on Ubuntu 16.04
echo "[Updating and upgrading before Installation] \n \n"
sudo apt-get update
sudo apt-get upgrade
echo "\n \n"
echo "[Installing essentials....this might take some time] \n \n".
sudo apt-get install build-essential cmake pkg-config libjpeg8-dev libtiff5-dev libjasper-dev libpng12-dev libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libgtk-3-dev libatlas-base-dev gfortran python2.7-dev python3.5-dev


#Step2: Download the OpenCV source
cd ~
echo "[Make sure you have enough space in /home] \n \n"
read -p "Press enter to continue"

echo "[Downloading OpenCV 3.1.0] \n \n"
wget -O opencv.zip https://github.com/Itseez/opencv/archive/3.1.0.zip
unzip opencv.zip

echo "[Download the contrib repo for SIFT/SURF features] \n \n"
wget -O opencv_contrib.zip https://github.com/Itseez/opencv_contrib/archive/3.1.0.zip
unzip opencv_contrib.zip
