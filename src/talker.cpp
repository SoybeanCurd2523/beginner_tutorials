#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <time.h>
// #include <dynamixel_sdk/dynamixel_sdk.h>
// #include <dxl_serial/dxl_serial.h>

int main(int argc, char **argv)
{ 

  ros::init(argc, argv, "talker");


  // dynamixel::GroupSyncRead gsr;

  
  ros::NodeHandle nh;

  
  ros::Publisher chatter_pub = nh.advertise<std_msgs::Int32>("chatter", 1000);

  ros::Rate loop_rate(1);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::Int32 msg;
    msg.data = count;
    ROS_INFO("I speak : [%d]", msg.data);
    chatter_pub.publish(msg); 
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
