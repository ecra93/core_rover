#include "ros/ros.h"
#include "std_msgs/String.h"

#include <nova_common/DriveCmd.h>
#include <nova_common/Goal.h>
#include <nova_common/DummyOdometry.h>

#include <sstream>

void calculateBearing(float lat1, float lon1, float lat2, float lon2) {

    float teta1 = radians(lat1);
    float teta2 = radians(lat2);
    float delta1 = radians(lat2-lat1);
    float delta2 = radians(lon2-lon1);

    float y = sin(delta2) * cos(teta2);
    float x = cos(teta1)*sin(teta2) - sin(teta1)*cos(teta2)*cos(delta2);
    float brng = atan2(y,x);

    brng = degrees(brng);// radians to degrees
    brng = ( ((int)brng + 360) % 360 ); 

    return brng;
}

void odometryCallback(const nova_common::DummyOdometry::ConstPtr& msg) {
    ROS_INFO("%f", msg->latitude);
}

void goalCallback(const nova_common::Goal::ConstPtr& msg) {
    ROS_INFO("1");
}

int main(int argc, char **argv)
{
    // init node "navigator"
    ros::init(argc, argv, "navigator");
    ros::NodeHandle n;

    // subscribe to <EKF Odometry>
    ros::Subscriber odometry_sub = n.subscribe("odometry_msg", 1000, odometryCallback);

    // subscribe to goal messages
    ros::Subscriber goal_sub = n.subscribe("goal_msg", 1000, goalCallback);

    // publish on "/core_rover/driver/drive_cmd", publisher capacity = 1000
    ros::Publisher driver_cmd_pub = n.advertise<nova_common::DriveCmd>("/core_rover/driver/driver_cmd", 1000);
   
    ros::spin();

    //while(ros::ok())
    //{
         // get odometry message
         
         // get the goal
         
         // compute required bearing
         
         // articulate drive command
         
         // send drive command
    //}
}
