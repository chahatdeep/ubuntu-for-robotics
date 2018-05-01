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
# wget http://developer.download.nvidia.com/compute/machine-learning/cudnn/secure/v5.1/prod_20161129/8.0/cudnn-8.0-linux-x64-v5.1.tgz?1wrboEB-UqGezuIqoJH6pbMYdG_IWWrQKSaGba-aoKvI592XB9CADIuyIJ32Xl9holF6QSmwTQOSZSmuNs5S_n4D0khUFhH7cEuWAZa_WHO3dvpgoqpaeuxkxEJFWAp65_y86-jq2KpwYUOzzjJdMOHPfgz1JcbnChbtLoo0AUWQXcoKdULTUAiMAml1CeWBkFysOZ_fKi0
wget -O cudnn-8.0-linux-x64-v5.1.tgz https://public.boxcloud.com/d/1/1dpYQMCVITA7ac4qv9ykWinouq6LRkpe7pA4jSLyN6gb9fy7-9paFn3wznGbKFJMDiTn72gbWrYVe65Mibtk2Wq4NvFgl7bHMogocsNSjPDV3-at68YnMD00ncMyoqIa00LCAZ36_dLwOwU6PVywuOHJJxb-gqI7pHU_M5bHl3svjFqX8WiqmoNqwmwT3Qi3RoKfjNhi2DauHgPSxWiTUMj_j_75Xu9n6YUVfs-JEn1IEyHNX7V3kk-ibfGfGt6j2AideqhWSCPTUX2qusKJ3vXwEEX4_--T4uzEk0vQqdXqO_CLgpe6Aivj2Zn-i4SlogMvSbXP4RVWgs0P9jMlj_7eCZV3Sg4OtTit0C-zTnx2A1IkuTYu01uKaW0I3kOFGTgfWAUthQ5IycXpgaYfEWpJ9rKRUAaDRXSK-gZOl2QCEhG2Ek8oEMYZqRVbEWizaBVOQQ1YmpGo5TVTRLZT0mgkvsSBUctZnTVthcH_2r6RXNTvSE2o4qmmh1Qm8lIqGQLbzpULLtM9pOzsBXYCXgfa4amJe-gb_slPc44u378cgmsX4U98TAewH-O-vN9_u0334wqWF_WdD9TxuAf5mAtxMjlV3BGPxbNNDatoa2E2EumA40ssnb1nnd97jPi1FQhFJhw-RWNLtRgclssFZs4Lu8kbc4rzuU-2lmKZKfxXOR5K6qAq1hGWqdHICPDGkyAS3w0fBEG5phe3Th8QibbDNUYP5Uba6o17MSFGA2CL118Q1JUKKMGK0Ek34vT4FvGX_nvWIS_qLOdl_-ifYQDV59SohAMNuU8khF1IgIfXwOF6OjDBu6_PemiukD0gu5hG7CZcxIH-SpLdqmZ4j3TzT7uL7pw2TueiXkG8Ebi08AmZuWp-FCGVPiosweNsHqHYfOgcqrVGho_tegIK5u4zbjell3tPNoTwLS1IBbHhNX8hsYXEKygOC-MXP9q5tlvkCAyZqJgA_VR8qD4KFQ9h06F4CCLnjO319IhbCyOlZXXmmpEQsKMRkjdYhGlbSVMQEZ_Qno3CQ4Tn0iyVC4YRnaR-_peBqMxLiu1bRI27myD9SqFyGRd20xCrpSLwMjBV2kOqextTm5MG2hx_apebfW2olvKxHxqfXkysxTu8jTuyMNiXBIrHQoQfVNoGEFHFyppNmyXpIlBUoBHkfheMvG-3X9qj168tIDM6vCffrT4VjpjHklGmQrIJlgW-BF6v9_Fd85vT6GTTAIu4UyZIGCfhZJgZvQKAkQG9RDy1Yw../download
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
