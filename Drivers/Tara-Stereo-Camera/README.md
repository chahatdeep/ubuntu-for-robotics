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
