/*
*定义一个服务person_srv，数据格式为Person，收到请求数据后简单应答
*/

#include <ros/ros.h>
#include <test_service/Person.h>

ros::Publisher g_pub;//全局发布对象

bool callback(test_service::Person::Request& req, test_service::Person::Response& res)
{
    //打印请求消息
    ROS_INFO("request: name:%s, age:%d, sex:%d", req.name.c_str(), req.age, req.sex);

    //返回消息赋值
    res.result = req.name;

    return true;
}

int main(int argc, char** argv){

    ros::init(argc, argv, "person_srv_node"); //本节点

    ros::NodeHandle node;

    //创建服务对象
    ros::ServiceServer srv = node.advertiseService("/person_srv", callback);
   
    //Enter simple event loop 等待回调
    ros::spin();

    return 0;
}