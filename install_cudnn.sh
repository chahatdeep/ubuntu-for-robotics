#!/bin/bash

# Install CUDA Toolkit v9.0/8.0
# Instructions from https://developer.nvidia.com/cuda-downloads (linux -> x86_64 -> Ubuntu -> 16.04 -> deb (network))

# CUDA_REPO_PKG="cuda-repo-ubuntu1604_8.0.61-1_amd64.deb"
# wget http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1604/x86_64/${CUDA_REPO_PKG}
# sudo dpkg -i ${CUDA_REPO_PKG}
# sudo apt-get update
# sudo apt-get -y install cuda

echo "Installing cudnn"
echo "Install cudnn v6.0 or lower if you have CUDA 8.0 with Tensorflow v1.4 or below"
echo "Else Install cudnn v7.0 or above (Recommended) with Tensorflow v1.7 or higher"
echo "1. 6.0 \n2. 7.3"
read -p 'cudnn version to install: ' version

if [ "$version" = "1" ]; then
  # install cuDNN v6.0
  CUDNN_TAR_FILE="cudnn-8.0-linux-x64-v6.0.tgz"
  wget http://developer.download.nvidia.com/compute/redist/cudnn/v6.0/${CUDNN_TAR_FILE}
  tar -xzvf ${CUDNN_TAR_FILE}
  sudo cp -P cuda/include/cudnn.h /usr/local/cuda-8.0/include
  sudo cp -P cuda/lib64/libcudnn* /usr/local/cuda-8.0/lib64/
  sudo chmod a+r /usr/local/cuda-8.0/lib64/libcudnn*
  # set environment variables
  export PATH=/usr/local/cuda-8.0/bin${PATH:+:${PATH}}
  export LD_LIBRARY_PATH=/usr/local/cuda-8.0/lib64\${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
  ########################################################################################


## OR ##

elif [ "$version" = "2" ]; then

  # install cuDNN v7.3
  CUDNN_TAR_FILE="cudnn-9.0-linux-x64-v7.3.1.20.tgz"
  wget http://developer.download.nvidia.com/compute/redist/cudnn/v7.0/${CUDNN_TAR_FILE}
  tar -xzvf ${CUDNN_TAR_FILE}
  sudo cp -P cuda/include/cudnn.h /usr/local/cuda-9.0/include
  sudo cp -P cuda/lib64/libcudnn* /usr/local/cuda-9.0/lib64/
  sudo chmod a+r /usr/local/cuda-9.0/lib64/libcudnn*

  # set environment variables
  export PATH=/usr/local/cuda-9.0/bin${PATH:+:${PATH}}
  export LD_LIBRARY_PATH=/usr/local/cuda-9.0/lib64:$LD_LIBRARY_PATH
  export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH

else 
  
  echo "Invalid version"
  
fi
