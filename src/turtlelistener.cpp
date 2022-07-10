#include "ros/ros.h"
#include "turtlesim/Pose.h"

void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
  ROS_INFO("x: [%f]", msg->x);
  ROS_INFO("y: [%f]", msg->y);
  ROS_INFO("theta : [%lf", (*msg).theta);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlelistener");

  ros::NodeHandle nh;

  ros::Subscriber turtlesub = nh.subscribe("/turtle1/pose", 1000, poseCallback);

  ros::spin();

  return 0;
}
