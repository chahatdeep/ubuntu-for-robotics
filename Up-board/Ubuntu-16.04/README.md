# Up-Board 16.04 Setup Instructions

* Note that Up-board has x86 architecture. That means, everything will be installed the same way as your Laptop/PC.*
* Make sure you are connected to Internet, either through WiFi or LAN.

1. First: enable Main, Universe, Restricted and Multiverse repositories from 'Softwares & Updates'. If you are new to Ubuntu, refer this [link](https://help.ubuntu.com/community/Repositories/Ubuntu)
2. `sudo apt update`
3. `sudo apt upgrade`
- **DO NOT `sudo apt dist-upgrade`**

4. Download ros setup file from [here](https://chahatdeep.github.io/ubuntu-for-robotics/Up-board/Ubuntu-16.04/install_ros.sh) and do:
`sudo bash install_ros.sh`

5. Download ros setup file from [here](https://chahatdeep.github.io/ubuntu-for-robotics/Up-board/Ubuntu-16.04/install_cv.sh) and do:
`sudo bash install_cv.sh`
