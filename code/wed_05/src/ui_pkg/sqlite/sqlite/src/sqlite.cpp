#include<ros/ros.h>
#include <std_msgs/String.h>
#include "sqlite3.h"
#include "../include/sqlite.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "../include/Greeting.h"
using namespace std;

sqlite3 *pDB = NULL;


namespace ui_pkg {

    class my_sqlite {

    public:
        my_sqlite() {
            //res_pub = n.advertise<std_msgs::String>("user_res", 1000);
            //user_sub = n.subscribe("user_info", 1000, &ui_pkg::my_sqlite::checkCode, this);
            log_server = n.advertiseService("loggin", &ui_pkg::my_sqlite::checkCode, this);
            register_server = n.advertiseService("register", &ui_pkg::my_sqlite::AddUser, this);
        }

        bool  AddUser(service_demo::Greeting::Request &req, service_demo::Greeting::Response &res) {
            string sName;
            string code;
            sName = req.name.substr(0,  req.name.find(" "));
            code = req.name.substr( req.name.find(" ") + 1,  req.name.size());

//add user
            string strSql = "";
            strSql += "insert into user(name,code)";
            strSql += "values('";
            strSql += sName;
            strSql += "',";
            strSql += code;
            strSql += ");";
            cout << strSql << endl;
            char *cErrMsg;
            int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
            if (nRes != SQLITE_OK) {
                cout << "add user fail: " << cErrMsg << endl;
                res.feedback = cErrMsg;
                return false;
            } else {
                cout << "add user success: " << sName.c_str() << "\t" << code.c_str() << endl;
                res.feedback = "add user success";
            }
            return true;
        }

        //    void checkCode(const std_msgs::String::ConstPtr &msg) {

        bool checkCode(service_demo::Greeting::Request &req, service_demo::Greeting::Response &res) {
            std_msgs::String rel_msg;
            //ros::Rate loop_rate(1);
            ROS_INFO("callback success");

            string sName;
            string code;


            //sName = msg->data.substr(0, msg->data.find(" "));
            //code = msg->data.substr(msg->data.find(" ") + 1, msg->data.size());
            sName = req.name.substr(0,  req.name.find(" "));
            code = req.name.substr(req.name.find(" ") + 1,  req.name.size());

            string strSql = "";
            string true_code;
            strSql += "select * from user where name='";
            strSql += sName;
            strSql += "';";
            sqlite3_stmt *stmt = NULL;

            int nRes = sqlite3_prepare_v2(pDB, strSql.c_str(), -1, &stmt, NULL);
            cout << nRes << endl;
            if (nRes != SQLITE_OK) {
                //  rel_msg.data = "select failed";
                res.feedback = "select failed";
                cout << "select failed: " << endl;
            } else {
                if (sqlite3_step(stmt) == SQLITE_DONE) {
                    res.feedback = "no user";
                } else {
                    true_code = (char *)sqlite3_column_blob(stmt, 1);
                    if (code == true_code) {
                        cout <<  "code correct" << endl;
                        //rel_msg.data = "code correct";
                        res.feedback = "code correct";
                    } else {
                        cout <<  "code wrong" << endl;
                        //rel_msg.data = "code wrong";
                        res.feedback = "code wrong";
                    }
                }
            }

            // res_pub.publish(rel_msg);
            //ros::spinOnce();
        }

        bool DeleteUser(const string &sName) {
            string strSql = "";
            strSql += "delete from user where name='";
            strSql += sName;
            strSql += "';";

            char *cErrMsg;
            int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
            if (nRes != SQLITE_OK) {
                cout << "delete user fail: " << cErrMsg << endl;
                return false;
            } else {
                cout << "delete user success: " << sName.c_str() << endl;
            }

            return true;
        }

        bool ModifyUser(const string &sName, const string &code) {
            string strSql = "";
            strSql += "update user set code =";
            strSql += code;
            strSql += " where name='";
            strSql += sName;
            strSql += "';";

            char *cErrMsg;
            int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
            if (nRes != SQLITE_OK) {
                cout << "modify user fail: " << cErrMsg << endl;
                return false;
            } else {
                cout << "modify user success: " << sName.c_str() << "\t" << code.c_str() << endl;
            }

            return true;
        }


    private:
        ros::NodeHandle n;
        ros::Publisher res_pub ;
        ros::Subscriber user_sub;
        ros::ServiceServer log_server;
        ros::ServiceServer register_server;
    };



}

int main(int argc, char **argv) {
    ros::init(argc, argv, "sqlite_node");
    ROS_INFO("sqlite init");
    int nRes = sqlite3_open("/home/robot/catkin_ws/src/2021_embedded/wed_05/src/test.db", &pDB);
    if (nRes != SQLITE_OK) {
        cout << "Open database fail: " << sqlite3_errmsg(pDB);
        exit(0);
    }
    ui_pkg::my_sqlite mk;
    ros::spin();
    ROS_INFO("sqlite quit");
}







