# Setting up Ubuntu on OrangePiZero: (Tested on `H2+` and currently testing on `H5`):
1. Download Ubuntu from my [Google Drive](https://doc-14-b4-docs.googleusercontent.com/docs/securesc/diuhiier8f3lbm44v9p44d1n6o10ft4n/dqfq2jsosmvcs3n3h62uatgqh35a3nbe/1522879200000/18093896044146087554/18093896044146087554/1PTAUiLsKnaTycR-OhpVvJZWLVYmhNN8D?e=download&h=09221738537919217220&nonce=juqlt50v9b5mo&user=18093896044146087554&hash=8g6kju4q1gls94a7kab031qvfqnhu393) or search for required version to download from the Orange Pi's [official website](http://www.orangepi.org/downloadresources/).
- Or download armbian from [here](https://www.armbian.com/orange-pi-zero-2-h5/).

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
