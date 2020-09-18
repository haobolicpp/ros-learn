// 本例程对应一个节点，将创建针对 turtle1/cmd_vel 话题的发布者，消息类型geomotry_msgs::Twist

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv){
    
    // ROS节点初始化
    ros::init(argc, argv, "velocity_publisher");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher,发布给/turtle1/cmd_vel主题topic，消息类型为geometry_msgs::Twist,设置队列缓冲长度为10
    // 当超过10时，会将队列中老的数据依次清除
    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // 设置循环的频率
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok()){
        //初始化Twist消息
        geometry_msgs::Twist msg;
        msg.linear.x = 2;
        msg.angular.z = 1;

        //发送消息
        turtle_vel_pub.publish(msg);
        ROS_INFO("publish node velocity_publisher command[%0.2f m/s, %0.2f rad/s]", 
            msg.linear.x, msg.linear.z);

        //循环延时
        loop_rate.sleep();
    }

    return 0;
}