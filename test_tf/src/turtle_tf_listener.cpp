/*
* 该节点查询两个坐标系之间的转换关系（ros通过tf树自动计算得到），利用转换关系中的平移向量，来控制小乌龟的速度（线速度和角速度）
*/

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <turtlesim/Spawn.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv){

    ros::init(argc, argv, "turtle_tf_listener_node"); //本节点

    ros::NodeHandle node;

    //创建turtle2小乌龟
    ros::service::waitForService("/spawn");
    turtlesim::Spawn spawn;
    ros::service::call("/spawn", spawn);

    //创建发布者，控制turtle2的速度
    ros::Publisher pub_vel = node.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);

    //创建tr的监听器，获取turtle2相对于turtle1的坐标转换transform
    tf::TransformListener listener;

    ros::Rate rate(10);
    while (node.ok())
    {
        tf::StampedTransform tr;
        try
        {
            listener.waitForTransform("/turtle2", "/turtle1", ros::Time(0), ros::Duration(3.0)); //从当前时间开始，等待一段时间3s，没有数据应该会异常（猜的），有数据返回
            listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), tr); //获取转换关系
        }
        catch(tf::TransformException &e)
        {
            std::cerr << e.what() << '\n';
            ros::Duration(1.0).sleep();
            continue;
        }

        //根据坐标关系，发布turtle2速度控制
        geometry_msgs::Twist vel;

        //旋转角速度，绕z旋转
        vel.angular.z = atan2(tr.getOrigin().y(), tr.getOrigin().x()); //向量的角度 
        
        // 线速度，沿x方向
        vel.linear.x = 0.5 * sqrt(pow(tr.getOrigin().x(), 2) + pow(tr.getOrigin().y(), 2));//距离越近越慢
        
        //投递数据
        pub_vel.publish(vel);

        rate.sleep();
    }
    

    return 0;
}