# Robotics_Home_Service_Robot

In this project following steps are completed to simulate a home service robot

1. Design a simple environment with the Building Editor in Gazebo.

2. Teleoperate robot and manually test SLAM.

3. Create a wall_follower node that autonomously drives the robot to map your environment.

4. Use the ROS navigation stack and manually command robot using the 2D Nav Goal arrow in rviz to move to 2 different desired positions 
and orientations.

5. Write a pick_objects node that commands robot to move to the desired pickup and drop off zones.

6. Write an add_markers node that subscribes to robot odometry, keeps track of robot pose, and publishes markers to rviz.

The submission files are:

catkin_ws/src directory which includes:
1. The official ROS packages that downloaded
2. New C++ packages and nodes
3. World files: gazebo world, pgm, and yaml files
4. Shell scripts

Package Tree

Here's a high level overview of how catkin_ws/src directory look like:

   ├──                                (Official ROS packages)
   
    |
    
    ├── slam_gmapping                 (gmapping_demo.launch file)   
    
    │   ├── gmapping
    
    │   ├── ...
    
    ├── turtlebot                      (keyboard_teleop.launch file)
    
    │   ├── turtlebot_teleop
    
    │   ├── ...
    
    ├── turtlebot_interactions         (view_navigation.launch file ) 
    
    │   ├── turtlebot_rviz_launchers
    
    │   ├── ...
    
    ├── turtlebot_simulator            (turtlebot_world.launch file )
    
    │   ├── turtlebot_gazebo
    
    │   ├── ...
    
    ├──                                 (packages and direcotries)
    
    |
    
    ├── world                           (world files)
    
    │   ├── ...
    
    ├── shellScripts                    (shell scripts files)
    
    │   ├── ...
    
    ├──rvizConfig                       (rviz configuration files)
    
    │   ├── ...
    
    ├──wall_follower                   ( wall_follower C++ node)
    
    │   ├── src/wall_follower.cpp
    
    │   ├── ...
    
    ├──pick_objects                    (pick_objects C++ node)
    
    │   ├── src/pick_objects.cpp
    
    │   ├── ...
    
    ├──add_markers                     (add_marker C++ node)
    
    │   ├── src/add_markers.cpp
    
    │   ├── ...
    
    └──
