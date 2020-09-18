/*
*对接服务/person_srv，传递的自定义数据类型Person
*/

#include <ros/ros.h>
#include <test_service/Person.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "person_client_node"); //本节点

    ros::NodeHandle node;

    // 等待发现/spawn服务
    ros::service::waitForService("/person_srv");
    
    //客户端通信对象
    ros::ServiceClient client = node.serviceClient<test_service::Person>("/person_srv");

    //创建请求数据
    test_service::Person p;
    p.request.age = 30;
    p.request.sex = test_service::PersonRequest::male;
    p.request.name = "bob";

    //调用--阻塞等待
    client.call(p);

    //显示调用结果
    ROS_INFO("reponse result: %s", p.response.result.c_str());

    return 0;
}