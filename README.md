# ubuntu-setup
This repository is for setting-up cuda-8.0, nvidia-384/387 driver, OpenCV-3.3, ROS Kinetic, Tensorflow1.4, MATLAB R2017b

## Order of Installation:
- Cuda
- OpenCV
- ROS

First do:
```
sudo apt update
sudo apt upgrade
```

### nvidia-384 setup:
`sudo apt install nvidia-smi nvidia-384`
***
### Cuda 8-0 setup:
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

### Installation OpenCV-3.3:
``bash install_opencv.sh``

### Download and install `cudnn`:
- Download [cudnn-6.0](https://drive.google.com/open?id=1PHPS2EdUyIt9GSsidKA92OeNiaYhFJqM0)
- 
