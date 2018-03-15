## For more videos visit https://www.youtube.com/c/SidsEClassroom

1. Open Wifi Configuration file
```
sudo nano /etc/network/interfaces
```

2. Paste the following lines
```
auto lo
iface lo inet loopback

auto eth0
allow-hotplug eth0
iface eth0 inet dhcp

allow-hotplug wlan0
iface wlan0 inet manual
wpa-roam /etc/wpa_supplicant/wpa_supplicant.conf
iface default inet dhcp
```



3. Open WIFI Config File
```
sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```

4. Copy and paste the following and set your SSID and PASSWORD
```
network={
ssid="Your_Wifi_SSID"
psk="Your_wifi_password"
}
```

5. Turn Wifi ON
```
sudo ifup wlan0
```

6. Update Time Zone
```
sudo dpkg-reconfigure tzdata
```
