#!/bin/bash
# Requires Python-2.7
# Requires cudnn


sudo apt-get install python-pip

echo "Cleaning the previous tensorflow installations"
sleep 1
sudo -H pip uninstall tensorflow
sudo -H pip uninstall tensorflow-gpu

sudo pip install tensorflow-gpu
echo "Installed tf-gpu."
echo "Updating tf-0.xx to tf-1.4..." && sleep 2

echo "Updating tensorflow to the latest version"
pip install --upgrade tensorflow # Removes libcudnn.so.6 bug.

# Search for tf-upgrade list @ https://storage.googleapis.com/tensorflow/

# Updating tf-cpu to 1.4:
# sudo pip install --upgrade https://storage.googleapis.com/tensorflow/linux/cpu/tensorflow-1.4.0-cp27-cp34m-linux_x86_64.whl

# Downgrade tf-gpu to 1.4 for python-2.7:
sudo pip install --upgrade https://storage.googleapis.com/tensorflow/linux/gpu/tensorflow_gpu-1.4.0-cp27-none-linux_x86_64.whl

# tf-gpu 1.2.1 (NEEDED for Flownet2); else Make error.
# sudo pip install --upgrade https://storage.googleapis.com/tensorflow/linux/gpu/tensorflow_gpu-1.2.1-cp27-none-linux_x86_64.whl


############ FALLBACK/ISSUES ####################
## Fix:
:'
export LD_LIBRARY_PATH=/usr/local/cuda-8.0/lib64/
wget http://developer.download.nvidia.com/compute/machine-learning/cudnn/secure/v5.1/prod_20161129/8.0/cudnn-8.0-linux-x64-v5.1.tgz?1wrboEB-UqGezuIqoJH6pbMYdG_IWWrQKSaGba-aoKvI592XB9CADIuyIJ32Xl9holF6QSmwTQOSZSmuNs5S_n4D0khUFhH7cEuWAZa_WHO3dvpgoqpaeuxkxEJFWAp65_y86-jq2KpwYUOzzjJdMOHPfgz1JcbnChbtLoo0AUWQXcoKdULTUAiMAml1CeWBkFysOZ_fKi0
tar xvzf cudnn-8.0-linux-x64-v5.1.tgz
sudo cp -P cuda/include/cudnn.h /usr/local/cuda/include
sudo cp -P cuda/lib64/libcudnn* /usr/local/cuda/lib64
sudo chmod a+r /usr/local/cuda/include/cudnn.h /usr/local/cuda/lib64/libcudnn*
'

## Fix 2:
:'
wget https://developer.nvidia.com/compute/machine-learning/cudnn/secure/v7.0.5/prod/8.0_20171129/Ubuntu16_04-x64/libcudnn7_7.0.5.15-1+cuda8.0_amd64
dpkg -i libcudnn7_7.0.5.15-1+cuda8.0_amd64.deb
'
