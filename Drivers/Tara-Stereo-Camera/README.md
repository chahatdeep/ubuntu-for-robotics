Installing ROS and Tara Stereo Drivers and SDK:

```
sudo bash tara-and-ROS-setup.sh
```

- Publish at lower rate:

Example: `rosrun topic_tools throttle messages 'topic_name' 'frequency'`

```
rosrun topic_tools throttle messages /stereo/left/image_raw 4.0 &
rosrun topic_tools throttle messages /stereo/right/image_raw 4.0
```

***

- Changing the resolution:
[Documentation](https://github.com/econsystems/tara-cpu-sdk/blob/master/Documents/See3CAM_Stereo_TARA_SDK_User_Manual_Linux_Rev_1_6.pdf)

Supported Resolution:
```
ID: 0, 752x480
ID: 1, 640x480
ID: 2, 320x240
```

- Edit the resolution in `~/catkin_ws/src/see3cam/launch`:
  Change `width`, `height`. `fps` does not work.

- Edit the exposure in `~/catkin_ws/src/see3cam/src/xunit/xunit_lib_tara.h`
 `#define SEE3CAM_STEREO_EXPOSURE_DEF`. Default value is `8000` (in micro second). 
  Range is from 10 to 1000000 micro seconds.
- Change Min, max and auto exposure in the same file, line 82-85. 


- Edit brightness in `/stereo/set_brightness` by `rostopic pub`. Check the updated value in `/stereo/get_brightness`.
  `/stereo/set_brightness` doesn't work. 
