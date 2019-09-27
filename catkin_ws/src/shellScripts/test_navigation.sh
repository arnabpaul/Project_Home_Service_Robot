#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/world/my_wall.world " &
sleep 5
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/catkin_ws/src/world/wall_map2.yaml" &
sleep 5
xterm  -e  " roslaunch view_navigation.launch rviz_file:=/home/workspace/catkin_ws/src/rvizConfig/nav.rviz" 