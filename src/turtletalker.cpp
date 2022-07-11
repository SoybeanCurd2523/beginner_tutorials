#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{ 

  ros::init(argc, argv, "turtletalker");

  ros::NodeHandle nh;

  ros::Publisher turtle_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(1);

  int count = 0;
  while (ros::ok())
  {

    geometry_msgs::Twist msg;
    msg.linear.x = 2.0;
    msg.angular.z = 1.8;
    ROS_INFO("linear.x : [%f]", msg.linear.x);
    ROS_INFO("angular.z : [%f]", msg.angular.z);

    turtle_pub.publish(msg); 
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
