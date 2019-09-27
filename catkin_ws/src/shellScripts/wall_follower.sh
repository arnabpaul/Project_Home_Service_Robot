#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/world/my_wall.world " &
sleep 5
xterm  -e  " roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 5
xterm  -e  " roslaunch view_navigation.launch rviz_file:=/home/workspace/catkin_ws/src/rvizConfig/slam_rviz.rviz" 
#sleep 5
#xterm  -e  " rosrun wall_follower wall_follower_node"