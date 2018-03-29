#!/bin/bash
# Installation script for Pytorch (Linux Only)

# Define Python and Cuda version here;
py_version=3.5 # Use Python 3.5 (Default)
cuda_version=8.0 # Cuda 8.0 recommended

py_ver=`python -c "print(int($py_version*10))"`
cuda_ver=`python -c "print(int($cuda_version*10))"`
echo $py_ver
echo $cuda_ver

pip3 install http://download.pytorch.org/whl/cu$(py_ver)/torch-0.3.1-cp$(cuda_ver)-cp$(cuda_ver)m-linux_x86_64.whl 
pip3 install torchvision
