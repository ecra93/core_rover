#include "ros/ros.h"
#include <nova_common/Goal.h>
#include <sstream>

int main(int argc, char **argv)
{
    
    // init node "goal"
    ros::init(argc, argv, "goal");
    ros::NodeHandle n;

    // publish to goal message
    ros::Publisher goal_pub = n.advertise<nova_common::Goal>("goal_msg", 1000);
    ros::Rate loop_rate(10);

    while(ros::ok()) {
        nova_common::Goal msg;
        msg.longitude = 1.00;
        msg.latitude = -1.00;
        goal_pub.publish(msg);
    }

}
