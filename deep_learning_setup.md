## This script is for setting up `CUDA`, `cuDNN`, `Python 2` or `3`, `Tensorflow`, `Keras`, `Pytorch`, `OpenCV` with `Dlib` and `Theano` on `Ubuntu 16.04`.

1. Prerequisites:
```
sudo apt-get update
sudo apt-get upgrade
```

2. Install Dependencies:
```
sudo apt-get install -y build-essential cmake gfortran git pkg-config 
sudo apt-get install -y python-dev software-properties-common wget vim
sudo apt-get autoremove
```

3. Cuda Installation: (for `cuda-8.0`):
```
sudo dpkg -i cuda-repo-ubuntu1604-8-0-local-ga2_8.0.61-1_amd64.deb
sudo apt-get update
sudo apt-get install -y cuda-8.0
```
To check the status, do `nvidia-smi`
If it is a different version of `cuda`, download `cuda` from [here](https://developer.nvidia.com/cuda-downloads) and follow step 3.

4. `cuDNN-6.0` setup:
Go to [NVIDIA cuDNN](https://developer.nvidia.com/rdp/cudnn-download) and download the required `cuDNN` file (6.0 recommended with `cuda-8.0`)
```
tar xvf cudnn-8.0-linux-x64-v6.0.tgz
sudo cp -P cuda/lib64/* /usr/local/cuda/lib64/
sudo cp cuda/include/* /usr/local/cuda/include/
```

Update the cuDNN Paths:
```
echo 'export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/local/cuda/lib64:/usr/local/cuda/extras/CUPTI/lib64"' >> ~/.bashrc
echo 'export CUDA_HOME=/usr/local/cuda' >> ~/.bashrc
echo 'export PATH="/usr/local/cuda/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

5. Install DL Frameworks requirements:
```
sudo apt-get update
sudo apt-get install -y libprotobuf-dev libleveldb-dev libsnappy-dev libhdf5-serial-dev protobuf-compiler libopencv-dev
```

If you see any warning such as: `/usr/lib/nvidia-375/libEGL.so.1 not a symbolic link`, setup the symbolic links using:
```
sudo mv /usr/lib/nvidia-375/libEGL.so.1 /usr/lib/nvidia-375/libEGL.so.1.org
sudo mv /usr/lib32/nvidia-375/libEGL.so.1 /usr/lib32/nvidia-375/libEGL.so.1.org
sudo ln -s /usr/lib/nvidia-375/libEGL.so.375.82 /usr/lib/nvidia-375/libEGL.so.1
sudo ln -s /usr/lib32/nvidia-375/libEGL.so.375.82 /usr/lib32/nvidia-375/libEGL.so.1
```

6. Install `Python` packages:
```
sudo apt-get install -y --no-install-recommends libboost-all-dev doxygen
sudo apt-get install -y libgflags-dev libgoogle-glog-dev liblmdb-dev libblas-dev 
sudo apt-get install -y libatlas-base-dev libopenblas-dev libgphoto2-dev libeigen3-dev libhdf5-dev 
 
sudo apt-get install -y python-dev python-pip python-nose python-numpy python-scipy
sudo apt-get install -y python3-dev python3-pip python3-nose python3-numpy python3-scipy
```

***

## Installing Different Deep Learning Frameworks:
1. `Tensorflow`, `Theano`, `Keras`, `dlib` and `PyTorch`:
- *Python 2*:

```
pip install numpy scipy matplotlib scikit-image scikit-learn ipython protobuf jupyter
 
# If you do not have CUDA installed
pip install tensorflow
# If you have CUDA installed
pip install tensorflow-gpu 
pip install Theano 
pip install keras
pip install http://download.pytorch.org/whl/cu80/torch-0.2.0.post3-cp27-cp27mu-manylinux1_x86_64.whl
pip install dlib
deactivate
```

- *Python 3*:
``` 
pip install numpy scipy matplotlib scikit-image scikit-learn ipython protobuf jupyter
 
# If you do not have CUDA installed
pip install tensorflow
# If you have CUDA installed
pip install tensorflow-gpu 
 
pip install Theano 
pip install keras
pip install http://download.pytorch.org/whl/cu80/torch-0.2.0.post3-cp35-cp35m-manylinux1_x86_64.whl
pip install dlib
 
deactivate
```

*Recheck all the frameworks installation in `python2` or `python3` shell using*:
```
import numpy
numpy.__version__
import theano
theano.__version__
import tensorflow
tensorflow.__version__
import keras
keras.__version__
import torch
torch.__version__
import cv2
cv2.__version__
```

## Install `OpenCV-3.4` from [here](https://github.com/chahatdeep/ubuntu-for-robotics/blob/master/install_opencv.sh).
