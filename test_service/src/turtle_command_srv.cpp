/*
*定义一个服务turtle_command_svr,其中传递的数据格式用系统的std_srvs/Trigger类型。
*在服务收到数据后，往话题 turtle1/cmd_vel 中传递一个数据，来控制海龟移动。
*/

#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <std_srvs/Trigger.h>
#include <geometry_msgs/Twist.h>

ros::Publisher g_pub;//全局发布对象

bool callback(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& res)
{
    geometry_msgs::Twist msg;
    msg.linear.x = 1;
    msg.angular.z = 1;

    //发送消息
    g_pub.publish(msg); 

    //返回消息赋值
    res.success = true;
    res.message = "ok";

    return true;
}

int main(int argc, char** argv){

    ros::init(argc, argv, "turtle_command_srv"); //本节点

    ros::NodeHandle node;

    //创建服务对象
    ros::ServiceServer srv = node.advertiseService("/turtle_command_svr", callback);

    //创建一个Publisher
    g_pub = node.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    //循环检测服务是否收到数据
    //ros::Rate loop_rate(10); //1s10次
    // while(ros::ok()){
    //     //查看一次就返回，如果有回调则会调用
    //     ros::spinOnce(); 

    //     loop_rate.sleep();
    // }

    //Enter simple event loop 等待回调
    ros::spin();

    return 0;
}