## JetPack Setup

```
NOTE: Ubuntu 16.04 LTS recommended on the host computer
```
* Download the latest version of Nvidia JetPack (Jetson™ SDK) [here](https://developer.nvidia.com/embedded/jetpack)
    * If needed, make an Nvidia developer account
* Move the **JetPack-L4T-XX-linux-x64.run** file into any directory and run
```
bash ./JetPack-L4T-XX-linux-x64.run
```
(Replace the XX with the your version such as 3.1)

* A window should appear with the JetPack installer
![jet1](https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/jetpack1.png)

* Select the Jetson TX2
![jet2](https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/jetpack2.png)

* Enter your admin password
* Select the L4T OS and any other packages you want
![jet3](https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/jetpack3.png)

* After the download and installation are complete, close JetPack
```
Do NOT finish flashing the target Jetson 
```

## Connect Tech Support Package Setup
* Go this [this link](http://connecttech.com/product/orbitty-carrier-for-nvidia-jetson-tx2-tx1/) and download the L4T support package from Connect Tech
* Copy the CTI-L4T-V###.tgz package into <JetPack_install_dir>/64_TX2/Linux_for_Tegra_tx2/

* Extract the BSP:
```
tar -xzf CTI-L4T-V###.tgz
```
(replacing ### with your file name)

* Enter the CTI-L4T directory:
```
cd ./CTI-L4T
```

* Run the install script as root
```
sudo ./install.sh
```


## Flashing the Jetson
* Boot the Jetson into recovery mode by holding down the Force Recovery button on the Orbitty board and then pressing reset
    * You can check the status by typing **lsusb** in terminal and checking for an Nvidia device
* Open a terminal from the <JetPack_install_dir>/64_TX2/Linux_for_Tegra_tx2/ directory:
```
sudo ./flash.sh orbitty mmcblk0p1
```
(Replacing "orbitty" with whichever Connect Tech carrier board you have)
* Wait for the process to finish and reboot


## Installing CUDA and Other Dependencies
* Connect an HDMI display and a keyboard and mouse to the Orbitty carrier board.
* Boot unto Ubuntu using the following credentials:
```
Username: nvidia
Password: nvidia
```
* Connect the Jetson to your network via Ethernet (recommended) or wifi
* Write down the IP address of the Jetson
```
ifconfig
```
* Leave the Jetson at this point, do NOT reboot to recovery
* On the host computer, navigate to the JetPack install directory and launch JetPack
```
bash ./JetPack-L4T-XX-linux-x64.run
```
(Replace the XX with the your version such as 3.1)

* A window should appear with the JetPack installer
![jet1](https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/jetpack1.png)

* Select the Jetson TX2
![jet2](https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/jetpack2.png)

* Enter your admin password
* In the Component Manager window, make sure "Host-Ubuntu" is set to "no action"
* Change "Flash OS Image to Target" to "no action"
   * Only "Install on Target" should be selected
![jet5](https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/jetpack5.png)

* Accept License Terms
* Enter the IP address you found earlier and your Jetson credentials (default nvidia:nvidia)
![jet6](https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/jetpack6.png)

* A new terminal will appear. Once the process is completed, reboot the Jetson
<p align="center">
<b>Your Jetson is now ready</b>
</p>
