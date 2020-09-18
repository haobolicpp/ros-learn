/*
*对已有的/spawn服务，创建请求和应答进行测试。/spawn 服务用来在指定位置创建一个turtle乌龟
*服务的数据类型turtlesim::Spawn
*/

#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "turtle_spawn"); //本节点

    ros::NodeHandle node;

    // 等待发现/spawn服务
    ros::service::waitForService("/spawn");
    
    //客户端通信对象
    ros::ServiceClient client = node.serviceClient<turtlesim::Spawn>("/spawn");

    //创建请求数据,在哪个坐标创建海龟
    turtlesim::Spawn msg;
    msg.request.name = "turtle_request";
    msg.request.x = 10;
    msg.request.y = 10;

    //调用--阻塞等待
    client.call(msg);

    //显示调用结果
    ROS_INFO("reponse name %s", msg.response.name.c_str());

    return 0;
}