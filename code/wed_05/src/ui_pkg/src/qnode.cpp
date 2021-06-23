/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include "../include/ui_pkg/Greeting.h"
#include <sstream>

#include "../include/ui_pkg/qnode.hpp"

#include<iostream>
#include <geometry_msgs/Twist.h>  //add
#include<std_msgs/Float32MultiArray.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include<ctime>
#include<std_srvs/Trigger.h>
/*****************************************************************************
** Namespaces
*****************************************************************************/
using namespace std;
using namespace cv;
namespace ui_pkg {

    /*****************************************************************************
    ** Implementation
    *****************************************************************************/

    QNode::QNode(int argc, char **argv ) :
        init_argc(argc),
        init_argv(argv)
    {}

    QNode::~QNode() {
        if(ros::isStarted()) {
            ros::shutdown(); // explicitly needed since we use ros::start();
            ros::waitForShutdown();
        }
        wait();
    }

    bool QNode::init() {
        ros::init(init_argc, init_argv, "ui_pkg");
        if ( ! ros::master::check() ) {
            return false;
        }
        ROS_INFO("qnode init");
        ros::start(); // explicitly needed since our nodehandle is going out of scope.
        ros::NodeHandle n;
        // Add your ros communications here.
//        chatter_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);   //add
        chatter_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);   //add
        img_warn_sub=n.subscribe("/img_warn",1000,&QNode::rec_img,this);
        log_client = n.serviceClient<service_demo::Greeting>("loggin");
        reg_client = n.serviceClient<service_demo::Greeting>("register");
        pos_client = n.serviceClient<std_srvs::Trigger>("pos_data");
        position_publisher = n.advertise<std_msgs::Float32MultiArray>("position", 1000);
        return true;
    }

    bool QNode::init(const std::string &master_url, const std::string &host_url) {
        std::map<std::string, std::string> remappings;
        remappings["__master"] = master_url;
        remappings["__hostname"] = host_url;
        ros::init(remappings, "ui_pkg");
        if ( ! ros::master::check() ) {
            return false;
        }
        ros::start(); // explicitly needed since our nodehandle is going out of scope.
        ros::NodeHandle n;
        // Add your ros communications here.
        //chatter_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
//        chatter_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);   //add
        user_publisher = n.advertise<std_msgs::String>("user_info",1);
        start();

        return true;
    }

//void QNode::run() {
//	ros::Rate loop_rate(1);
//	int count = 0;
//	while ( ros::ok() ) {

//		std_msgs::String msg;
//		std::stringstream ss;
//		ss << "hello world " << count;
//		msg.data = ss.str();
//		chatter_publisher.publish(msg);
//		log(Info,std::string("I sent: ")+msg.data);
//		ros::spinOnce();
//		loop_rate.sleep();
//		++count;
//	}
//	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
//	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
//}

    string QNode::login(std::string user_name, std::string code) {
        service_demo::Greeting srv;
        srv.request.name = user_name;
        srv.request.name += " ";
        srv.request.name += code;
        log_client.call(srv);
        return srv.response.feedback;
    }

    string QNode::reg(std::string user_name, std::string code) {
        service_demo::Greeting srv;
        srv.request.name = user_name;
        srv.request.name += " ";
        srv.request.name += code;
        reg_client.call(srv);
        return srv.response.feedback;
    }

    void QNode::sendPosition(vector<float> pos) {
        std_msgs::Float32MultiArray msg;
        msg.data = pos;
        position_publisher.publish(msg);
        ROS_INFO("pos sent");
    }
//    void QNode::res_handle(const std_msgs::String::ConstPtr &msg) {
//        ROS_INFO("res_handle success");
//        cout << msg->data << endl;
//        if (ros::ok()) {
//            if(msg->data == "none user") {
//                cout << "none user" << endl;
//            } else if(msg->data == "code correct") {
//                cout << "code correct" << endl;
//            } else if(msg->data == "code wrong") {
//                cout << "code wrong" << endl;
//            }
//        }
//    }


//add
    void QNode::up() {
        //ros::Rate loop_rate(1);

        //if(ros::ok()) {
        geometry_msgs::Twist msg;
//        msg.linear.x = 1.0;
        msg.linear.x = 0.15;
        msg.angular.z = 0.0;

        chatter_publisher.publish(msg);

//        ros::Duration(0.1).sleep();


//        geometry_msgs::Twist msg1;
//        chatter_publisher.publish(msg1);

        ros::spinOnce();
//        loop_rate.sleep();
        //}
        log(Info, std::string("up"));
    }

//add
    void QNode::down() {
        //ros::Rate loop_rate(1);

        //if(ros::ok()) {
        geometry_msgs::Twist msg;
//        msg.linear.x = -1.0;
        msg.linear.x = -0.15;
        msg.angular.z = 0.0;

        chatter_publisher.publish(msg);


//        ros::Duration(0.1).sleep();
//        geometry_msgs::Twist msg1;
//        chatter_publisher.publish(msg1);

        ros::spinOnce();
//        loop_rate.sleep();
        //}
        log(Info, std::string("down"));
    }

//add
    void QNode::left() {
        //ros::Rate loop_rate(1);

        //if(ros::ok()) {
        geometry_msgs::Twist msg;
        msg.linear.x = 0.0;
//        msg.angular.z = 1.0;
        msg.angular.z = 0.2;

        chatter_publisher.publish(msg);

//        ros::Duration(0.1).sleep();
//        geometry_msgs::Twist msg1;
//        chatter_publisher.publish(msg1);


        ros::spinOnce();
//        loop_rate.sleep();
//        }
        log(Info, std::string("left"));
    }

//add
    void QNode::right() {
//        ros::Rate loop_rate(1);

//        if(ros::ok()) {
        geometry_msgs::Twist msg;
        msg.linear.x = 0.0;
//        msg.angular.z = -1.0;
        msg.angular.z = -0.2;


        chatter_publisher.publish(msg);

//        ros::Duration(0.1).sleep();
//        geometry_msgs::Twist msg1;
//        chatter_publisher.publish(msg1);


        ros::spinOnce();
//        loop_rate.sleep();
//        }
        log(Info, std::string("right"));
    }

    void QNode::stop() {
//        ros::Rate loop_rate(1);

//        if(ros::ok()) {
        geometry_msgs::Twist msg;
        chatter_publisher.publish(msg);

        ros::spinOnce();
//        loop_rate.sleep();
//        }
        log(Info, std::string("right"));
    }

    void QNode::rec_img(const sensor_msgs::ImageConstPtr& msg){
        cv_bridge::CvImagePtr cv_ptr;
        ROS_WARN("rec_img");
        log(Info, std::string("receive img"));
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        time_t nowtime;
        struct tm* p;
        time(&nowtime);
        p=localtime(&nowtime);
        ROS_INFO("%d:%d;%d",p->tm_hour,p->tm_min,p->tm_sec);
        cv::imshow("sw",cv_ptr->image);
        cv::waitKey(10);
        std_srvs::Trigger srv;
        pos_client.call(srv);
        string pos = srv.response.message;
        cout<<pos<<endl;
    }


    void QNode::log( const LogLevel &level, const std::string &msg) {
        logging_model.insertRows(logging_model.rowCount(), 1);
        std::stringstream logging_model_msg;
        switch ( level ) {
            case(Debug) : {
                    ROS_DEBUG_STREAM(msg);
                    logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
                    break;
                }
            case(Info) : {
                    ROS_INFO_STREAM(msg);
                    logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                    break;
                }
            case(Warn) : {
                    ROS_WARN_STREAM(msg);
                    logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                    break;
                }
            case(Error) : {
                    ROS_ERROR_STREAM(msg);
                    logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
                    break;
                }
            case(Fatal) : {
                    ROS_FATAL_STREAM(msg);
                    logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
                    break;
                }
        }
        QVariant new_row(QString(logging_model_msg.str().c_str()));
        logging_model.setData(logging_model.index(logging_model.rowCount() - 1), new_row);
        Q_EMIT loggingUpdated(); // used to readjust the scrollbar
    }

}  // namespace ui_pkg
