# Up Core Ubuntu 16.04 Setup

The Intel Up Core board does NOT support legacy setting in BIOS. It ONLY has UEFI mode so do not use tools like `rufus` or `PowerISO` to create the Ubuntu Bootable disk. You can install Ubuntu with `rufus` but the bootloader (GRUB) won't be installed.


- Download `Ubuntu 16.04.6` `iso` file from the Ubuntu download page ([link](http://releases.ubuntu.com/16.04/ubuntu-16.04.6-desktop-amd64.iso))
- Create a USB disk (minimum 8GB space) using `etcher` tool which creates UEFI bootable disk. You can download `etcher` from [here](https://etcher.io).
- Install Ubuntu the regular way and everything should work.

*Note:* In BIOS settings, make sure you have OS type selected as `Android/Linux`, not `Windows`.

***

## Update Ubuntu Kernel for Up Core

1. After the reboot you need to add our repository:
```
sudo add-apt-repository ppa:ubilinux/up
```

2. Update the repository list
```
sudo apt update
```

3. Remove all the generic installed kernel
```
sudo apt-get autoremove --purge 'linux-.*generic'
```

4. Install our kernel
```
sudo apt-get install linux-image-generic-hwe-16.04-upboard
```

5. Install the updates (please make sure to not upgrade the system to Ubuntu 18.04)
```
sudo apt dist-upgrade -y
sudo reboot
```

6. Reboot
```
sudo reboot
```

7. After the reboot you can verify that the kernel is indeed installed by typing
```
$ uname -a
Linux upsquared-UP-APL01 4.15.0-37-generic #40~upboard03-Ubuntu SMP Wed Dec 12 16:21:24 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux
```

## Install the Ampak firmware for WiFi and Bluetooth
This firmware is available for UP Core (AP6214A chipset) and UP Core Plus (AP6355 chipset).

Just run the next command
```
sudo apt install firmware-ampak
```

Reboot your machine to get the firmware working:
```
sudo reboot
```

**WiFi**
First at all, you may need to connect a WiFi antenna to your UP Core board [ANT1 connector].
Check the UP Core connectors in https://downloads.up-community.org/download/up-core-connectors-description/.

Scan your available WiFi networks:
```
sudo iwlist wlan0 scan
```
You will see all the WiFi interfaces in your area.

**Bluetooth**
Check your Bluetooth devices in your area:
```
hcitool scan
```


For other Kernel level and Networking changes, please follow [these](https://wiki.up-community.org/Ubuntu) instructions.
