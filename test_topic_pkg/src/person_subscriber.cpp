// 本例程订阅/person_info话题，消息类型test_topic_pkg::Person

#include <ros/ros.h>
#include "../include/test_topic_pkg/Person.h"

//接收到消息后的处理函数
void poseCallback(const test_topic_pkg::Person::ConstPtr &msg){
    ROS_INFO("收到消息 %s, %d, %d", msg->name.c_str(), msg->sex, msg->age);
}

int main(int argc, char **argv){
    
    // ROS节点初始化
    ros::init(argc, argv, "person_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber订阅者，
    ros::Subscriber sub = n.subscribe("/person_info", 10, poseCallback);

    //Enter simple event loop 等待回调
    ros::spin();

    return 0;
}