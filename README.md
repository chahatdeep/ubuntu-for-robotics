# ubuntu-for-robotics

## News: 
- October 25: Added Support for Tensorflow v1.11, CUDA v9.0 and cudnn v7.3

## About:

This repository is for setting-up cuda-9/8, nvidia-396/387/384 driver, OpenCV-3.3, ROS Kinetic, Tensorflow-1.11/1.7/1.4/1.2.1, Pytorch-0.4; maintained for settting-up the step-zero Deep Learning framework (Tensorflow), especially for Robotics application.

*Install fresh ubuntu 16.04 (x86-64) and follow:*
*(Tested on Intel i7-6700K, 32GB DDR4 RAM, nvidia Titan X)*

## Order of Installation:
- Cuda
- OpenCV
- ROS
- Tensorflow
- CuDNN

First do:
```
sudo apt update
sudo apt upgrade
```

***

## nvidia-384 setup:
`sudo apt install nvidia-smi nvidia-384`
***

## Cuda 9-0 setup:
- Download Cuda for Ubuntu 16.04 x86_64: ([deb-local](https://developer.nvidia.com/cuda-90-download-archive?target_os=Linux&target_arch=x86_64&target_distro=Ubuntu&target_version=1604&target_type=deblocal))
or simply do, 
```
wget https://developer.nvidia.com/compute/cuda/9.0/Prod/local_installers/cuda-repo-ubuntu1604-9-0-local_9.0.176-1_amd64-deb
```

- Do: 
```
sudo dpkg -i cuda-repo-ubuntu1604-9-0-local_9.0.176-1_amd64.deb 
sudo apt-get update
sudo apt-get install cuda
```



## Cuda 8-0 setup:
- Download Cuda for Ubuntu 16.04 x86_64: (deb-local)
https://developer.nvidia.com/cuda-80-ga2-download-archive
or simply do, `wget https://developer.nvidia.com/compute/cuda/8.0/Prod2/local_installers/cuda-repo-ubuntu1604-8-0-local-ga2_8.0.61-1_amd64-deb`
- Do: 
```
sudo dpkg -i cuda-repo-ubuntu1604-8-0-local-ga2_8.0.61-1_amd64.deb
sudo apt-get update
sudo apt-get install cuda
```

- Check for cuda version:
```
sudo apt install nvidia-cuda-toolkit
nvcc --version
```

- If you see `Cuda compilation tools, release 7.5` instead of `cuda-8.0`, do:
``
echo 'export PATH=/usr/local/cuda-8.0/bin${PATH:+:${PATH}}' >> ~/.bashrc
``
- Check `nvcc --version` again (on a fresh terminal window). It should show you `cuda-8.0`.
***


## Install OpenCV-3.3:
``bash install_opencv.sh``

## Install ROS-Kinetic-base:
``bash install_ros.sh``

## Install Tensorflow:
``bash install_tf.sh``

## Install CuDNN:
``bash install_cudnn.sh``


## FAQ(s):
- [Installing cuda for Quadro series GPU](https://github.com/chahatdeep/ubuntu-for-robotics/issues/3)
