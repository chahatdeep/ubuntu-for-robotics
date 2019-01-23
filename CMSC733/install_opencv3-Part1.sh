#!/bin/bash

# version="$(wget -q -O - http://sourceforge.net/projects/opencvlibrary/files/opencv-unix | egrep -m1 -o '\"[0-9](\.[0-9]+)+' | cut -c2-)"
version=3.4.0
echo "Installing OpenCV: " $version
echo " in" $PWD
echo "Tested only on Ubuntu-16.04. It might not work with any other distro."
read -p "Press <ENTER> to continue"
mkdir OpenCV
cd OpenCV
echo "NOTE: Uninstallating ffmpeg and x264. They have issues with OpenCV."
read -p "Press <ENTER> to continue"
echo "Removing any pre-installed ffmpeg and x264"
sudo apt-get -qq remove ffmpeg x264 libx264-dev
echo "Installing Dependenices"
sudo apt-get -qq install libopencv-dev build-essential checkinstall cmake pkg-config yasm libjpeg-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev libxine2-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libv4l-dev python-dev python-numpy libtbb-dev libqt4-dev libgtk2.0-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev x264 v4l-utils ffmpeg cmake qt5-default checkinstall
echo "Downloading OpenCV: " $version
# wget -O OpenCV-$version.zip http://sourceforge.net/projects/opencvlibrary/files/opencv-unix/$version/opencv-"$version".zip/download
wget -O OpenCV-$version.zip https://astuteinternet.dl.sourceforge.net/project/opencvlibrary/opencv-unix/3.4.0/opencv-3.4.0.zip
echo "Installing OpenCV" $version
unzip OpenCV-$version.zip
cd opencv-$version
mkdir build
cd build

maxThreads=$(grep -c ^processor /proc/cpuinfo)
echo Enter the number of CPU threads you want to use. FYI: You have $maxThreads CPU Threads.
read nThreads

cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D CUDA_GENERATION=Kepler ..
# or try for cuda support:
make -j$nThreads
# if there is an error: cmake again with the following lines and then do make again:
# cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -D BUILD_TIFF=ON -D BUILD_EXAMPLES=ON -D CUDA_GENERATION=Auto -D BUILD_NEW_PYTHON_SUPPORT=ON  .. 
# and then do make -j$nThreads
# cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_QT=OFF -D WITH_OPENGL=ON ..
# ---------------------------------------------------------- #
