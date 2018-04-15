# Welcome to the Jetson™ TX2 Setup! 
### Recommended host machine is freshly installed 16.04 LTS. DO NOT USE Ubuntu 14.04.

1. [Hardware Setup Guide](Hardware.md)

2. [Jetson Carrier Board Flashing Guide](Flashing-and-Setup-Guide-for-a-Connect-Tech-Carrier-Board.md)

3. [Reconfiguring the Jetson Kernel to Support USB AMC](Re-configuring-the-Jetson-TX2-Kernel.md)

***

### Extras:
- [Single and Multi-Class Object Detection](Single-and-Multi-Class-Object-Detection.md)
- [Reference](https://github.com/NVIDIA-Jetson/jetson-trashformers)



***

- To install pyTorch, do:
```
sudo bash ./install_pytorch_tx2.sh
```

*Note: `pyTorch` installation on NVIDIA TX2 takes about an hour to install.*

- Check GPU/RAM/CPU Stats: 
```
sudo ~/tegrastats
```
`tegrastats` Legend:
```
EMC – memory controller
AVP – audio/video processor
VDE – video decoder engine
GR3D – GPU
```

*Note: `nvidia-smi` is not available for Jetson platform.*
