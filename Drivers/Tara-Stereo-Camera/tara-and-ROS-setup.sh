sudo apt update
sudo apt upgrade
sudo apt install vim
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo sh -c '. /etc/lsb-release && echo "deb http://mirror.umd.edu/packages.ros.org/ros/ubuntu xenial main" > /etc/apt/sources.list.d/ros-latest.list' 
wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | sudo apt-key add - 
sudo apt update
sudo apt install ros-kinetic-ros-base 
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
sudo apt update
sudo apt upgrade
sudo apt autoremove
sudo apt install ros-kinetic-rviz
sudo rosdep init
rosdep update
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
sudo apt install python-rosinstall
printenv | grep ROS
mkdir -p ~/catkin_ws/src
cd ~
git clone https://github.com/econsystems/tara-cpu-sdk
cd tara-cpu-sdk/Prebuilts
sudo ./dependencies.sh
sudo bash install.sh
source ~/.bashrc
cd catkin_ws/src/
git clone https://github.com/dilipkumar25/see3cam
git checkout tara_v1.2
sudo apt-get install ros-kinetic-camera-info-manager
sudo apt-get install libudev-dev
cd ~/catkin_ws
catkin_make
source ~/catkin_ws/devel/setup.bash
source ~/.bashrc
roslaunch uvc_camera tara_launch.launch & rviz

# Optional udev rules:
# cd ~/catkin_make/src/see3cam
# sudo cp udev/99-uvc.rules /etc/udev/rules.d/
# sudo udevadm trigger


