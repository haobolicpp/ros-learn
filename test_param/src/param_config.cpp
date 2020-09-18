/*
*本例程设置/读取海龟例程中的参数
*/

#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "param_config_node"); //本节点

    ros::NodeHandle node;

    int r,g,b;
    //读取参数--背景颜色
    ros::param::get("/turtlesim/background_b", b);
    ros::param::get("/turtlesim/background_g", g);
    ros::param::get("/turtlesim/background_r", r);
    ROS_INFO("get background color:r%d, g%d. b%d", r,g,b);

    //设置参数-背景颜色
    ros::param::set("/turtlesim/background_g", 255);
    ros::param::set("/turtlesim/background_b", 0);
    ros::param::set("/turtlesim/background_r", 0);
    ROS_INFO("set background color.");

    //等待发现服务
    ros::service::waitForService("/clear");
    //调用服务，刷新背景色--
    std_srvs::Empty ser;
    ros::service::call("/clear", ser);
    ROS_INFO("clear background color.");

    ros::spin();

    return 0;
}