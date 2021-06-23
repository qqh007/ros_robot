#include "../include/ui_pkg/setmap.h"
#include "../include/ui_pkg/signin.h"
#include "../include/ui_pkg/main_window.hpp"

#include "ui_setmap.h"
#include <QMessageBox>

SetMap::SetMap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetMap) {
    ui->setupUi(this);

    //设置主界面参数


    //设置大小
    setFixedSize(800, 600);

    MoveToMid(this);

    //设置摄像头图片
//    QPixmap *pixmap = new QPixmap("/home/kidleyh/work_space/windows_ui/src/ui_pkg/resources/images/camera.png");
//    pixmap->scaled(ui->cameraLabel->size(), Qt::KeepAspectRatio);
//    ui->cameraLabel->setScaledContents(true);
//    ui->cameraLabel->setPixmap(*pixmap);

    //设置地图图片
//    QPixmap *mapPixmap = new QPixmap("/home/kidleyh/work_space/windows_ui/src/ui_pkg/resources/images//map.png");
//    mapPixmap->scaled(ui->mapLabel->size(), Qt::KeepAspectRatio);
//    ui->mapLabel->setScaledContents(true);
//    ui->mapLabel->setPixmap(*mapPixmap);


    ui->up->setFont(QFont("Microsoft YaHei", 12, QFont::Bold));
    ui->down->setFont(QFont("Microsoft YaHei", 12, QFont::Bold));
    ui->left->setFont(QFont("Microsoft YaHei", 12, QFont::Bold));
    ui->right->setFont(QFont("Microsoft YaHei", 12, QFont::Bold));
    ui->stop->setFont(QFont("Microsoft YaHei", 12, QFont::Bold));

    display_rviz();

}

SetMap::~SetMap() {
    delete ui;
}

void SetMap::on_up_clicked() {
    qnode->up();
    ui->up->setStyleSheet("color:red;");
    ui->down->setStyleSheet("color:black;");
    ui->left->setStyleSheet("color:black;");
    ui->right->setStyleSheet("color:black;");
}

void SetMap::on_down_clicked() {
    qnode->down();
    ui->up->setStyleSheet("color:black;");
    ui->down->setStyleSheet("color:red;");
    ui->left->setStyleSheet("color:black;");
    ui->right->setStyleSheet("color:black;");
}

void SetMap::on_left_clicked() {
    qnode->left();
    ui->up->setStyleSheet("color:black;");
    ui->down->setStyleSheet("color:black;");
    ui->left->setStyleSheet("color:red;");
    ui->right->setStyleSheet("color:black;");
}

void SetMap::on_right_clicked() {
    qnode->right();
    ui->up->setStyleSheet("color:black;");
    ui->down->setStyleSheet("color:black;");
    ui->left->setStyleSheet("color:black;");
    ui->right->setStyleSheet("color:red;");
}

void SetMap::on_stop_clicked() {
    qnode->stop();
    ui->up->setStyleSheet("color:black;");
    ui->down->setStyleSheet("color:black;");
    ui->left->setStyleSheet("color:black;");
    ui->right->setStyleSheet("color:black;");
}

void SetMap::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_W:
            on_up_clicked();
            break;
        case Qt::Key_S:
            on_down_clicked();
            break;
        case Qt::Key_A:
            on_left_clicked();
            break;
        case Qt::Key_D:
            on_right_clicked();
            break;
        case Qt::Key_X:
            on_stop_clicked();
            qnode->stop();
            break;
        default:
            break;
    }

}
void SetMap::keyReleaseEvent(QKeyEvent *event) {

}

void SetMap::on_begin_clicked() {
system("gnome-terminal -x bash -c 'source ~/.bashrc;roslaunch wpb_home_tutorials hector_mapping.launch'&");
}

void SetMap::on_finish_clicked() {
system("gnome-terminal -x bash -c 'source ~/.bashrc;rosrun map_server map_saver -f /home/robot/catkin_ws/src/wpb_home/wpb_home_tutorials/maps/map;'"); 
QMessageBox::information(this, tr("提示"), tr("地图已保存！"));
}
void SetMap::on_cancel_clicked() {
    //SetRelaPos(mainWindow);

    mainWindow->show();
    MoveToMid(mainWindow);
    this->close();
}

void SetMap::display_rviz() {

    //set up
    render_panel_ = new rviz::RenderPanel;
    ui->rvizLayout_->addWidget(render_panel_);
    manager_ = new rviz::VisualizationManager(render_panel_);
    render_panel_->initialize(manager_->getSceneManager(), manager_);
    manager_->initialize();
    manager_->startUpdate();



    rviz::Display *grid_ = manager_->createDisplay("rviz/Grid", "adjustable grid", true);
    ROS_ASSERT(grid_ != NULL);
    grid_->subProp("Line Style")->setValue("Billboards");

    // QProcess process;
    //process.execute("source devel/setup.bash");
    // process.execute("roslaunch rbx1_bringup fake_turtlebot.launch");
    //process.execute("roslaunch rbx1_nav fake_amcl.launch");

    //manager_->removeAllDisplays();

    //manager_->setFixedFrame("base_footprints");
    manager_->setFixedFrame("map");


    rviz::Display *map_ = manager_->createDisplay("rviz/Map", "adjustable map", true);
    ROS_ASSERT(map_ != NULL);
    //map_->subProp("")
    map_->subProp("Topic")->setValue("/map");

    manager_->setFixedFrame("base_footprint");

    rviz::Display *robot_ = manager_->createDisplay("rviz/RobotModel", "adjustable robot", true);
    ROS_ASSERT(robot_ != NULL);
    robot_->subProp("Robot Description")->setValue("robot_description");


    rviz::Display *laser_ = manager_->createDisplay("rviz/LaserScan", "adjustable scan", true);
    ROS_ASSERT(laser_ != NULL);
    laser_->subProp("Topic")->setValue("/scan");
    laser_->subProp("Size (m)")->setValue("0.1");


    rviz::Display *point_cloud_ = manager_->createDisplay("rviz/PointCloud2", "adjustable camera", true);
    ROS_ASSERT(point_cloud_ != NULL);
    point_cloud_->subProp("Topic")->setValue("/kinect2/sd/points");
    point_cloud_->subProp("Size (m)")->setValue("0.01");
    point_cloud_->subProp("Alpha")->setValue("1");

//    rviz::Display *image_ = manager_->createDisplay("rviz/Image", "adjustable camera", true);
//    ROS_ASSERT(image_ != NULL);
//    image_->subProp("Image Topic")->setValue("/kinect2/hd/image_color_rect");
    //test1->subProp("")
    //test1->subProp("Size (m)")->setValue("0.01");
    //test1->subProp("Alpha")->setValue("1");


    manager_->startUpdate();


}


