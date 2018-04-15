#!/bin/bash
# Takes about 100 mins to install pyTorch on a TX2
#
# pyTorch install script ONLY for NVIDIA Jetson TX2- Ubuntu 16.04-L4T, doesn't work on NVIDIA TX1
# from a fresh flashing of JetPack 2.3.1 / JetPack 3.0 / JetPack 3.1
#
# for the full source, see jetson-reinforcement repo:
# https://github.com/dusty-nv/jetson-reinforcement/blob/master/CMakePreBuild.sh
#
# Note:  pyTorch documentation calls for use of Anaconda,
#        however Anaconda isn't available for aarch64.
#        Instead, we install directly from source using setup.py

# Install Python-pip:
sudo apt-get install python-pip

# Upgrade pip:
pip install -U pip
pip --version
# pip 9.0.1 from /home/ubuntu/.local/lib/python2.7/site-packages (python 2.7)

# Clone pyTorch repo:
git clone http://github.com/pytorch/pytorch
cd pytorch
git submodule update --init

# Install prereqs
sudo pip install -U setuptools
sudo pip install -r requirements.txt

# Install cmake:
sudo apt install cmake

# Develop Mode:
python setup.py build_deps # Will take about an hour on TX2
sudo python setup.py develop

# Install Mode:  (substitute for Develop Mode commands) # Will take about 30 mins on TX2
sudo python setup.py install

# Install TorchVision:
sudo apt-get install libjpeg-dev zlib1g-dev libpng-dev python-matplotlib
sudo -H pip install Pillow
sudo -H pip install torchvision

# Verify CUDA (If this works, Torch is successfully installed)
python -c 'import torch; print(torch.__version__); print(torch.cuda.is_available()); a = torch.cuda.FloatTensor(2); \
print(a); b = torch.randn(2).cuda(); print(b); c = a + b; print(c)'
