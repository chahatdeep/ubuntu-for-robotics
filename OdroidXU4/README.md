## Odroid-XU4 Setup
### Download Ubuntu-16.04 for XU4 from: `https://odroid.in/ubuntu_16.04lts/`

1. Un-xz your image file: 
`unxz ubuntu-16.04-mate-odroid-xu3-20160708.img.xz`

2. Insert your micro-SD Card to your host PC. Make sure that it's more than 8GB. *Minimum 16GB is recommended.*
*(The size of Ubuntu mate image is around 4GB and Opencv requires around 2.5GB)*

3. Copy the Image into SD card. 
Replace `sdX` to your SD card device name in your host machine.
* **Note**: Recheck your SD Card partition. Do not enter any other HDD partition by mistake, else you'll lose the HDD data. Check `lsblk` to confirm your partition.*
```
sudo dd if=ubuntu-16.04-mate-odroid-xu4-$version.img of=/dev/sdX bs=1M conv=fsync
sync
```

4. Install Gparted on your host and run
(Resize `rootfs` partition as it is just 4GB in the image)
```
sudo apt-get install gparted
sudo gparted
```
Now, select `/dev/sdX` on `gparted` and in the `rootfs`. Right-Click, `Resize/Move` to maximum possible size. **Leave a couple of GB spare (unallocated), if possible.**

6. Insert this SD Card on the Odroid XU4 and turn the power on.
*Make sure the Odroid switch is pointing towards microSD (not eMMC). 
Log-in credentials:

```
username: odroid
password: odroid
```

8. Download `opencv_install_odroid.sh` from `git`

-or-

Copy-Paste the following script to a new file named: `opencv_install_to_ubuntu_mate_16.04.sh`
```
#!/bin/bash

version="$(wget -q -O - http://sourceforge.net/projects/opencvlibrary/files/opencv-unix | egrep -m1 -o '\"[0-9](\.[0-9]+)+' | cut -c2-)"
echo "Installing OpenCV: " $version
echo " in" $PWD
echo "Tested only on Ubuntu-16.04 (MATE). It might not work with any other distro."
read -p "Press <ENTER> to continue"
mkdir OpenCV
cd OpenCV
echo "Removing any pre-installed ffmpeg and x264"
sudo apt-get -qq remove ffmpeg x264 libx264-dev
echo "Installing Dependenices"
sudo apt-get -qq install libopencv-dev build-essential checkinstall cmake pkg-config yasm libjpeg-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev libxine2-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libv4l-dev python-dev python-numpy libtbb-dev libqt4-dev libgtk2.0-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev x264 v4l-utils ffmpeg cmake qt5-default checkinstall
echo "Downloading OpenCV: " $version
wget -O OpenCV-$version.zip http://sourceforge.net/projects/opencvlibrary/files/opencv-unix/$version/opencv-"$version".zip/download
echo "Installing OpenCV" $version
unzip OpenCV-$version.zip
cd opencv-$version
mkdir build
cd build

maxThreads=$(grep -c ^processor /proc/cpuinfo)
echo Enter the number of CPU threads you want to use. FYI: You have $maxThreads CPU Threads.
read nThreads

cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_QT=OFF -D WITH_OPENGL=ON ..
make -j$nThreads
sudo checkinstall
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
echo "OpenCV" $version "is ready to use."
```

9. Install `opencv_install_odroid.sh`

```
source opencv_install_to_ubuntu_mate_16.04.sh
```

10. Sample Test:
```
cd opcv-2.13.xx/samples/c
./facedetect lena.jpg
```
***
### ROS Installation:
#### Installing ROS Kinetic (Ubuntu 16.04): ([Reference](http://wiki.ros.org/kinectic/Installation/Ubuntu))
1. Setup your sources.list 
```
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
```

2. Install the `ros-kinetic` package:
```
sudo sh -c '. /etc/lsb-release && echo "deb http://mirror.umd.edu/packages.ros.org/ros/ubuntu xenial main" > /etc/apt/sources.list.d/ros-latest.list' 
wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | sudo apt-key add - 
sudo apt-get update 
```
Then do- 
```sudo apt-get install ros-kinetic-desktop-full```
or 
```sudo apt-get install ros-kinetic-desktop```

3. Set up your keys
```
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
```

4. Installation
Make sure your packages are up to date:
```
sudo apt-get update
```

5. Initialize rosdep:
```
sudo rosdep init
rosdep update
```

6. Environment setup:
- Adding ROS environment variables to your bash session:
```
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
```
7. Getting rosinstall:
- It enables you to easily download many source trees for ROS packages with one command:
```
sudo apt-get install python-rosinstall
```

**Note**: *If you are not able to open `rviz`, check the Rviz in the [issue](#rviz-issue) section

***

### Issues:
#### Rviz-issue ([Reference](http://indilib.org/forum/general/2402-solved-problem-with-libglesv2-so-2-on-odroid-xu4.html))

- `odroid@odroid:~$ rviz`, you might face this issue:
```
rviz: error while loading shared libraries: libGLESv2.so.2: cannot open shared object file: No such file or directory
```
It can be resolved by:
```
sudo ln -s /usr/lib/arm-linux-gnueabihf/mesa-egl/libGLESv2.so.2 /usr/lib/arm-linux-gnueabihf/libGLESv2.so.2
```

