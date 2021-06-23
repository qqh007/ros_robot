/**
 * @file /include/ui_pkg/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef ui_pkg_QNODE_HPP_
#define ui_pkg_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
    #include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include <std_msgs/String.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace ui_pkg {

    /*****************************************************************************
    ** Class
    *****************************************************************************/

    class QNode : public QThread {
        Q_OBJECT
    public:
        QNode(int argc, char **argv );
        virtual ~QNode();
        bool init();
        bool init(const std::string &master_url, const std::string &host_url);
        //void run();
        std::string login(std::string user_name, std::string code);
        std::string reg(std::string user_name, std::string code);
        void rec_img(const sensor_msgs::ImageConstPtr& msg);
        void sendPosition(std:: vector<float> pos);
        void up();
        void down();
        void left();
        void right();
        void stop();


        /*********************
        ** Logging
        **********************/
        enum LogLevel {
            Debug,
            Info,
            Warn,
            Error,
            Fatal
        };

        QStringListModel *loggingModel() {
            return &logging_model;
        }
        void log( const LogLevel &level, const std::string &msg);

    Q_SIGNALS:
        void loggingUpdated();
        void rosShutdown();

    private:
        int init_argc;
        char **init_argv;
        ros::Publisher  chatter_publisher;
        ros::Publisher user_publisher ;
        ros::Publisher position_publisher;
        ros::Subscriber user_res_sub;
        ros::Subscriber img_warn_sub;
        ros::ServiceClient log_client;
        ros::ServiceClient reg_client;
        ros::ServiceClient pos_client;
        QStringListModel logging_model;
    };

}  // namespace ui_pkg

#endif /* ui_pkg_QNODE_HPP_ */
