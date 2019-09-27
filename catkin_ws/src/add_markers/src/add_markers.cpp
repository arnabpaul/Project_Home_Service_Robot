#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;
  // Stores which zone the object is in
  std::string zone = "";
  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;
	// Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.25;//1.0
    marker.scale.y = 0.25;//1.0
    marker.scale.z = 0.25;//1.0

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;//1.0
    marker.color.b = 1.0f;
    marker.color.a = 1.0;
    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = 3.42;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = -0.7;//0.0
    marker.pose.orientation.w = 0.71;//1.0
	

    //marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    
    // checking if object at pickup zone
    if (n.hasParam("objectAt"))
    {
      std::string s;
      n.getParam("objectAt", s);
      
      if (s == "pick" and zone != "pickup")
      {
        // Publish the marker
        sleep(1);
        marker_pub.publish(marker);
        zone = "pickup";
        ROS_INFO("Object located at Pickup point");
      }
      else if (s == "" and zone != "")
      {
        marker.action = visualization_msgs::Marker::DELETE;
        marker_pub.publish(marker);
        zone = "";
        ROS_INFO("Object pickup from the Pickup point");
      }
    }
    else
      ROS_INFO("objectAt parameter not found on server.");
    /*marker_pub.publish(marker);
    sleep(5);
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);*/
    
	marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = -0.6;
    marker.pose.position.y =  -0.05;
	//marker_pub.publish(marker);
    //sleep(5);
    marker.lifetime = ros::Duration();

	
    // checking if drop zone reached
    if (n.hasParam("objectAt"))
    {
      std::string s;
      n.getParam("objectAt", s);

      if (s == "drop" and zone != "drop")
      {
        // Publish the marker
        marker_pub.publish(marker);
        zone = "drop";
        ROS_INFO("Object dropped at Drop point");
      }
    }
    // Cycle between different shapes
    //switch (shape)
    //{
   // case visualization_msgs::Marker::CUBE:
      //shape = visualization_msgs::Marker::SPHERE;
    //  break;
    //case visualization_msgs::Marker::SPHERE:
      //shape = visualization_msgs::Marker::ARROW;
      //break;
    //case visualization_msgs::Marker::ARROW:
      //shape = visualization_msgs::Marker::CYLINDER;
      //break;
    //case visualization_msgs::Marker::CYLINDER:
     // shape = visualization_msgs::Marker::CUBE;
      //break;
    //}

    r.sleep();
  }
}