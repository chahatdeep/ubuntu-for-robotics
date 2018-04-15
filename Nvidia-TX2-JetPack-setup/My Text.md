# My TX2 Setup with Connect-Tech-Carrier-Board

### Ubuntu 16.04 LTS recommended on the host computer!


***
[Ref: https://github.com/chahatdeep/ubuntu-for-robotics/blob/master/Nvidia-TX2-JetPack-setup/Flashing-and-Setup-Guide-for-a-Connect-Tech-Carrier-Board.md]
Download the latest version of Nvidia JetPack (Jetson™ SDK) [here](https://developer.nvidia.com/embedded/jetpack)

bash ./JetPack-L4T-XX-linux-x64.run # Don't use sudo

Select TX2

Enter admin password

Select the L4T OS and any other packages you want 

After the download and installation are complete, close JetPack

*Do NOT finish flashing the target Jetson*

Kill Jetson Installer once you see this:

--[Image]--

***


## Connect Tech Support Package Setup:
- Go this this [link](http://connecttech.com/product/orbitty-carrier-for-nvidia-jetson-tx2-tx1/) and download the L4T support package from Connect Tech
Copy the CTI-L4T-V###.tgz package into <JetPack_install_dir>/64_TX2/Linux_for_Tegra_tx2/

Extract the BSP:

tar -xzf CTI-L4T-V###.tgz
(replacing ### with your file name)

Enter the CTI-L4T directory:
cd ./CTI-L4T
Run the install script as root
sudo ./install.sh


Boot the Jetson into recovery mode by holding down the Force Recovery button on the Orbitty board and then pressing *power button*

You can check the status by typing lsusb in terminal and checking for an Nvidia device

Open a terminal from the <JetPack_install_dir>/64_TX2/Linux_for_Tegra_tx2/ or simply do `cd ..` :

sudo ./flash.sh orbitty mmcblk0p1 # It should be mmcblk0p1 everytime unless you have multiple Linux board connected to your host machine.

(Replacing "orbitty" with whichever Connect Tech carrier board you have)

Wait for the process to finish and reboot.

Expect Outputs like [this](https://github.com/chahatdeep/ubuntu-for-robotics/blob/master/Nvidia-TX2-JetPack-setup/Terminal-Output.md)

Ubuntu will be installed on the TX2 and it'll reboot with Unity interface on Ubuntu-16.04-L4T

Mouse and Keyboard should work now!!!

### Installing CUDA and Other Dependencies

On TX2, do 
```
sudo apt update
sudo apt upgrade
```


Connect an HDMI display and a keyboard and mouse to the Orbitty carrier board.
Boot unto Ubuntu using the following credentials:
Username: nvidia
Password: nvidia
Connect the Jetson to your network via Ethernet (recommended) or wifi
Write down the IP address of the Jetson
ifconfig
Leave the Jetson at this point, do NOT reboot to recovery
On the host computer, navigate to the JetPack install directory and launch JetPack
bash ./JetPack-L4T-XX-linux-x64.run

(Replace the XX with the your version such as 3.1)





Enter your admin password

In the Component Manager window, make sure "Host-Ubuntu" is set to "no action"

Change "Flash OS Image to Target" to "no action"

Only "Install on Target" should be selected 

--[Image here]--

Accept License Terms

Do `ifconfig` and check Device IP of TX2 machine! It should be the `inet addr` under `eth0` if you are connected to Ethernet or under `wlan0` if you are connected to Wireless LAN. (For example: `192.168.0.28`)
Enter username and password as `nvidia`.

Enter the IP address you found earlier and your Jetson credentials (default nvidia:nvidia) 


If you get error like this:
```
Return Code: 1
Error: Cannot connect to device with given information. Please check your input and try again.

Detailed info: 
/bin/bash: sshpass: command not found
```

You need to install `sshpass`, do `sudo apt install sshpass` on the host machine.

Now, click on Next and let it install




