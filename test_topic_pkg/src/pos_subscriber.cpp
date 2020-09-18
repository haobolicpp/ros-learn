// 本例程订阅/turtle1/pose话题，消息类型turtlesim::Pose

#include <ros/ros.h>
#include "turtlesim/Pose.h"

//接收到消息后的处理函数
void poseCallback(const turtlesim::Pose::ConstPtr &msg){
    ROS_INFO("pose x:%.6f, y:%0.6f", msg->x, msg->y);
}

int main(int argc, char **argv){
    
    // ROS节点初始化
    ros::init(argc, argv, "pose_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber订阅者，
    ros::Subscriber sub = n.subscribe("/turtle1/pose", 10, poseCallback);

    //Enter simple event loop 等待回调
    ros::spin();

    return 0;
}