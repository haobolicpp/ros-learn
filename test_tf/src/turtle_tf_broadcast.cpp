/*
* 【原理】首先启动小乌龟节点 rosrun turtlesim turtlesim_node，此时利用rostopic list可以看到/turtle1/pose主题，
* 我们订阅该主题，将收到的坐标数据相对于world坐标系广播出去。
* 【注意】本节点实际上监听了turtle1和turtle2两个得主题，这里本节点得到了复用，节点名称是通过调用时指令修改的。执行方式：rosrun test_tf turtle_tf_broadcast __name:=turtle1_b /turtle1
* 【实验】可以实验一下，方法二：直接创建两个订阅者
                      方法三：本节点名称由输入参数动态修改（应该不行）
*/

#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <tf/transform_broadcaster.h>

std::string strTurtlename;

//收到数据后，广播出去
void callback(const turtlesim::Pose::ConstPtr &msg){
    //创建广播器
    static tf::TransformBroadcaster tfb;

    //初始化广播的数据,相对于world坐标系的平移+旋转
    tf::Transform tr;
    tf::Quaternion q;
    tr.setOrigin(tf::Vector3(msg->x, msg->y, 0.0)); //平移
    q.setRPY(0, 0, msg->theta);//RPY角(Roll, Pitch, Yaw)， 即先绕X转R，再绕Y转P，再绕Z转Y 参考 https://www.cnblogs.com/marty86/p/7868223.html
    tr.setRotation(q); //旋转

    //广播出去 后两个参数分别代表“基于的坐标系”、“当前坐标系”的名称。
    tfb.sendTransform(tf::StampedTransform(tr, ros::Time::now(), "world", strTurtlename));
}

int main(int argc, char** argv){

    ros::init(argc, argv, "turtle_tf_broadcast_node"); //节点名，这里会被创建时强行修改，写什么不重要了

    ros::NodeHandle node;

    if (argc == 1){
        return 0;
    }

    strTurtlename = argv[1]; //第0个是执行程序的名称

    //创建订阅者，订阅指定小乌龟的pose
    ros::Subscriber sub = node.subscribe(strTurtlename+"/pose", 10, callback);

    //等待
    ros::spin();

    return 0;
}