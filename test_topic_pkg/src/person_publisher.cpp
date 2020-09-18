// 本例程对应一个节点，将创建针对/person_info话题的发布者，消息类型test_topic_pkg::Person

#include <ros/ros.h>
#include "../include/test_topic_pkg/Person.h"

int main(int argc, char **argv){
    
    // ROS节点初始化,节点名称person_publisher
    ros::init(argc, argv, "person_publisher");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher,发布给/person_info主题topic
    // 当超过10时，会将队列中老的数据依次清除
    ros::Publisher person_pub = n.advertise<test_topic_pkg::Person>("/person_info", 10);

    // 设置循环的频率
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok()){
        //初始化消息
        test_topic_pkg::Person msg;
        msg.name = "bob";
        msg.sex = test_topic_pkg::Person::male;
        msg.age = 30;

        //发送消息
        person_pub.publish(msg);
        ROS_INFO("publish node person_publisher: %s, %d, %d", 
            msg.name.c_str(), msg.sex, msg.age);

        //循环延时
        loop_rate.sleep();
    }

    return 0;
}