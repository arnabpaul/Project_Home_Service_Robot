#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/world/my_wall.world " &
sleep 5
xterm  -e  " roslaunch turtlebot_teleop keyboard_teleop.launch" & 
sleep 5
xterm  -e  " rosrun gmapping slam_gmapping" &
sleep 5
xterm  -e  " roslaunch view_navigation.launch rviz_file:=/home/workspace/catkin_ws/src/rvizConfig/slam_rviz.rviz"
