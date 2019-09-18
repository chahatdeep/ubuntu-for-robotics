# Setting up Ubuntu on OrangePiZero: (Tested on `H2+` and currently testing on `H5`):
1. Download Ubuntu from my [Google Drive](https://drive.google.com/open?id=1PTAUiLsKnaTycR-OhpVvJZWLVYmhNN8D) or search for required version to download from the Orange Pi's [official website](http://www.orangepi.org/downloadresources/).
- Or download armbian from [here](https://www.armbian.com/orange-pi-zero-2-h5/).
***
# Powering orangepi
Provide power through **5V/GND** pins on the **26 pin** header. Voltage drops affecting stability are likely to happen if you are powering through USB
***
# After Installation:
## Installing Tensorflow-1.1.0 on Orange Pi Zero:

```
sudo apt install python-pip
wget https://github.com/samjabrahams/tensorflow-on-raspberry-pi/releases/download/v1.1.0/tensorflow-1.1.0-cp27-none-linux_armv7l.whl
sudo pip install tensorflow-1.1.0-cp27-none-linux_armv7l.whl
```

- [x] Source: [Tf on arm](https://github.com/samjabrahams/tensorflow-on-raspberry-pi)

## Installing Opencv:
```
sudo apt install python-opencv libopencv-dev
```
