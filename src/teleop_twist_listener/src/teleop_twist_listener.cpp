#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>


void msgCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
  float x = msg->linear.x;
  float y = msg->linear.y;
  float z = msg->linear.z;

  if ( x > 0 && y == 0 && z == 0 )
    {
      ROS_INFO("go straight");
    }
  if ( x < 0 && y == 0 && z == 0 )
    {
      ROS_INFO("go back");
    }
  if ( x == 0 && y == 0 && z == 0 )
    {
      ROS_INFO("stop");
    }
  if ( x == 0 && y > 0 && z == 0 )
    {
      ROS_INFO("go right");
    }
  if ( x == 0 && y < 0 && z == 0 )
    {
      ROS_INFO("go left");
    }
  if ( x == 0 && y == 0 && z > 0 )
    {
      ROS_INFO("go up");
    }
  if ( x == 0 && y == 0 && z < 0 )
    {
      ROS_INFO("go down");
    }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv,"teleop_listener");
  ros::NodeHandle nh;

  ros::Subscriber teleop_sub = nh.subscribe("cmd_vel", 1000, msgCallback);

  ros::spin();
  return 0;
}

