#!/bin/bash

sudo checkinstall
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
echo "OpenCV is installed"
sudo make install

# Do NOT uncomment the following lines, it installs OpenCV-4:
# echo "Installing Opencv support for Python 3"
# sudo apt install python3-pip
# pip3 install opencv-python
# echo "OpenCV" $version "is ready to use."
