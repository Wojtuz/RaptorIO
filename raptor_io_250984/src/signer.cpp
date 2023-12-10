#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Header.h"

ros::Subscriber RaptorIN_sub;
ros::Publisher RaptorOUT_pub;


void RaptorCallback(const std_msgs::String::ConstPtr& msg)
{
    std_msgs::String sign_msg;
    
    ros::Time timestamp = ros::Time::now();

    sign_msg.data = "<Wojciech Murlikiewicz / "+ std::to_string(timestamp.toSec()) +">"
    " Input z RaptorIN: " + msg->data;

    RaptorOUT_pub.publish(sign_msg);

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "signer");
    ros::NodeHandle n;

    RaptorIN_sub = n.subscribe("RaptorIN", 1000, RaptorCallback);
    RaptorOUT_pub = n.advertise<std_msgs::String>("RaptorOUT", 1000);

    ros::spin();
}
/*
*/