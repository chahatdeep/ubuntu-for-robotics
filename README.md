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

### Download and install `cudnn` for cuda-8.0 (cudnn-6.0) is not supported for cudnn-5.1:
- Download [cudnn-5.1](https://drive.google.com/open?id=1PHPS2EdUyIt9GSsidKA92OeNiaYhFJqM0)
- `tar -zxvf cudnn-8.0-linux-x64-v5.1.tgz`
- Check the file: 
``
cd cuda/lib64/
ls -l
``
- You should see something like this:
```
total 150908
lrwxrwxrwx 1 doom doom       13 Nov  7  2016 libcudnn.so -> libcudnn.so.5
lrwxrwxrwx 1 doom doom       18 Nov  7  2016 libcudnn.so.5 -> libcudnn.so.5.1.10
-rwxr-xr-x 1 doom doom 84163560 Nov  7  2016 libcudnn.so.5.1.10
-rw-r--r-- 1 doom doom 70364814 Nov  7  2016 libcudnn_static.a
```
- Here you will see 2 symbolic link files, and just copy `libcudnn.so.5.1.10` and `libcudnn_static.a` to `/usr/local/cuda-8.0/lib64`
- Make symbolic link files:
```
cd /usr/local/cuda-8.0/lib64/
sudo ln -s libcudnn.so.5.1.10 libcudnn.so.5
sudo ln -s libcudnn.so.5 libcudnn.so
```

- Check for libcudnn: `ls -l libcudnn*`
You should see:
```
lrwxrwxrwx 1 root root       13 May 24 09:24 libcudnn.so -> libcudnn.so.5
lrwxrwxrwx 1 root root       18 May 24 09:24 libcudnn.so.5 -> libcudnn.so.5.1.10
-rwxr-xr-x 1 root root 84163560 May 24 09:23 libcudnn.so.5.1.10
-rw-r--r-- 1 root root 70364814 May 24 09:23 libcudnn_static.a
```
- Copy `cudnn.h` in include directory to `/usr/local/cuda/include`
`sudo cp cudnn.h /usr/local/cuda-8.0/include/`

- [Reference](https://stackoverflow.com/questions/42013316/after-building-tensorflow-from-source-seeing-libcudart-so-and-libcudnn-errors)
