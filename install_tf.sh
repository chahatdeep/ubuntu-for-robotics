#!/bin/bash

sudo apt-get install python-pip
sudo pip install tensorflow-gpu
echo "Installed tf-gpu."
echo "Updating tf-0.xx to tf-1.4..." && sleep 2

# Search for tf-upgrade list @ https://storage.googleapis.com/tensorflow/linux/gpu/tensorflow_gpu-1.4.1-cp36-cp36m-linux_x86_64.whl

# Updating tf-cpu to 1.4:
# sudo pip install --upgrade https://storage.googleapis.com/tensorflow/linux/cpu/tensorflow-1.4.0-cp34-cp34m-linux_x86_64.whl

# Updating tf-gpu to 1.4:
1
Fix: 
# export LD_LIBRARY_PATH=/usr/local/cuda-8.0/lib64/
# Download https://developer.nvidia.com/compute/machine-learning/cudnn/secure/v7.0.5/prod/8.0_20171129/Ubuntu16_04-x64/libcudnn7_7.0.5.15-1+cuda8.0_amd64
# sudo apt-get install libcupti-dev

