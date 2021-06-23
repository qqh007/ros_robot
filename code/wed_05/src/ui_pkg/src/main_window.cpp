/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <QKeyEvent>
#include <ros/ros.h>
#include <ros/network.h>


#include "../include/ui_pkg/main_window.hpp"
#include "../include/ui_pkg/signin.h"
#include "../include/ui_pkg/setmap.h"
#include "../include/ui_pkg/control.h"
#include "../include/ui_pkg/patrolroute.h"
#include "../include/ui_pkg/warning.h"

#include "ui_main_window.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace ui_pkg {

    using namespace Qt;

    /*****************************************************************************
    ** Implementation [MainWindow]
    *****************************************************************************/

    MainWindow::MainWindow(int argc, char **argv, QWidget *parent)
        : QMainWindow(parent)
        , qnode(argc, argv) {
        ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
        //ReadSettings();
        setWindowIcon(QIcon(":/images/icon.png"));
        QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
        qnode.init();
        //设置固定大小
        setFixedSize(800, 600);
        MoveToMid(this);
        //让窗口居中
        QDesktopWidget *desktop = QApplication::desktop();
        //move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);

        setWindowTitle("巡检机器人");

        //设置图片
        QPixmap *pixmap = new QPixmap("/home/robot/catkin_ws/src/2021_embedded/wed_05/src/ui_pkg/resources/images/patrolRobot.png");
        //pixmap->scaled(ui.photoLabel->size(), Qt::KeepAspectRatio);
        //ui.photoLabel->setScaledContents(true);
        ui.photoLabel->setPixmap(*pixmap);



        //设置icon
        QPixmap *pixmap1 = new QPixmap("/home/robot/catkin_ws/src/2021_embedded/wed_05/src/ui_pkg/resources/images//robot.png");
        pixmap1->scaled(ui.iconLabel->size(), Qt::KeepAspectRatio);
        ui.iconLabel->setScaledContents(true);
        ui.iconLabel->setPixmap(*pixmap1);

        //设置标题字体
        ui.titleLabel->setFont(QFont("Microsoft YaHei", 14, QFont::Bold));

        //    //点击exit回到登录界面
        //    connect(ui.actionexit, &QAction::triggered, [ = ]() {
        //        this->close();
        //        SignIn *s = new SignIn;
        //        s->setWindowTitle("登录");
        //        //w->setFixedSize(600,400);
        //        //s->move(this->x() + (this->width() - m->width()) / 2, this->y() + (this->height() - m->height()) / 2);
        //        SetRelaPos(s);
        //        s->show();
        //        //设置关闭时自动释放内存
        //        s->QWidget::setAttribute(Qt::WA_DeleteOnClose);
        //    });

        //点击tip启动提示
        const char *tipString = "这是一个自动巡逻机器人\n使用流程：\n地图建模、设置巡航点、自动巡航\n报警功能：\n机器人在巡逻过程中对火情和外来入侵人员报警";
        //    connect(ui.actiontip, &QAction::triggered, [ = ]() {

        //        QMessageBox::question(this, "使用提示", tipString, QMessageBox::Ok, QMessageBox::Ok);
        //        //this->close();
        //        //SignIn *s = new SignIn;
        //        //s->setWindowTitle("登录");
        //        //w->setFixedSize(600,400);
        //        //s->move(this->x() + (this->width() - m->width()) / 2, this->y() + (this->height() - m->height()) / 2);
        //        //SetRelaPos(s);
        //        //s->show();
        //        //设置关闭时自动释放内存
        //        //s->QWidget::setAttribute(Qt::WA_DeleteOnClose);
        //    });





        //设置巡逻路线界面
//        PatrolRoute *p = new PatrolRoute;
//        p->setWindowTitle("设置巡逻路线");
//        //w->setFixedSize(600,400);

//        connect(ui.routeBtn, &QPushButton::clicked, [ = ]() {
//            //this->close();

//            SetRelaPos(p);
//            p->show();
//            //设置关闭时自动释放内存
//            p->QWidget::setAttribute(Qt::WA_DeleteOnClose);
//        });

        //报警情况页面
//        connect(ui.warningBtn, &QPushButton::clicked, [ = ]() {
//            this->close();
//            Warning *w = new Warning;
//            w->setWindowTitle("设置报警情况");
//            //w->setFixedSize(600,400);
//            SetRelaPos(w);
//            w->show();
//            //设置关闭时自动释放内存
//            w->QWidget::setAttribute(Qt::WA_DeleteOnClose);
//        });

        //设置字体
        //设置标题字体
        // ui.label->setFont(QFont("Microsoft YaHei",14,QFont::Bold));
        // ui.label_2->setFont(QFont("Microsoft YaHei",14,QFont::Bold));
        //ui.label_3->setFont(QFont("Microsoft YaHei",14,QFont::Bold));
        //ui.label_4->setFont(QFont("Microsoft YaHei",14,QFont::Bold));



    }

    MainWindow::~MainWindow() {}

    /*****************************************************************************
    ** Implementation [Slots]
    *****************************************************************************/



    /*
     * These triggers whenever the button is clicked, regardless of whether it
     * is already checked or not.
     */


    /*****************************************************************************
    ** Implemenation [Slots][manually connected]
    *****************************************************************************/




    /*****************************************************************************
    ** Implementation [Menu]
    *****************************************************************************/



    /*****************************************************************************
    ** Implementation [Configuration]
    *****************************************************************************/

    void MainWindow::ReadSettings() {

    }

    void MainWindow::WriteSettings() {


    }

    void MainWindow::closeEvent(QCloseEvent *event) {
        WriteSettings();
        QMainWindow::closeEvent(event);
    }
}  // namespace ui_pkg


void ui_pkg::MainWindow::on_mapBtn_clicked() {
    this->hide();
    SetMap *s = new SetMap;
    s->setWindowTitle("地图建模");
    s->mainWindow = this;
    s->qnode = &this->qnode;
    //system("roslaunch wpb_home_tutorials nav.launch&");
    //SetRelaPos(s);
    s->show();
    //设置关闭时自动释放内存
    s->QWidget::setAttribute(Qt::WA_DeleteOnClose);
}

void ui_pkg::MainWindow::on_controlBtn_clicked() {
    this->hide();
    Control *c = new Control;
    c->setWindowTitle("手动控制");
    //w->setFixedSize(600,400);
    c->mainwindow = this;
    c->qnode = &this->qnode;
    //SetRelaPos(c);
    c->show();
    //设置关闭时自动释放内存
    c->QWidget::setAttribute(Qt::WA_DeleteOnClose);
}

void ui_pkg::MainWindow::on_exit_clicked() {

    QMessageBox:: StandardButton result = QMessageBox::information(NULL, tr("提示"), tr("确定要退出吗？"),  QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);

    if(result == QMessageBox::Yes) {
        SignIn *s = new SignIn;
        s->mainwindow = this;
        s->qnode = &this->qnode;
        this->hide();

        s->show();
        //设置关闭时自动释放内存
        s->QWidget::setAttribute(Qt::WA_DeleteOnClose);
    }
}

void ui_pkg::MainWindow::on_routeBtn_clicked() {
    PatrolRoute *p = new PatrolRoute;
    p->mainwindow = this;
    p->qnode = &this->qnode;
    this->hide();

    p->show();
    //设置关闭时自动释放内存
    p->QWidget::setAttribute(Qt::WA_DeleteOnClose);

}

void ui_pkg::MainWindow::on_warningBtn_clicked() {
system("gnome-terminal -x bash -c 'source ~/.bashrc;roslaunch alarm_package alarm.launch'&");
//ros::MultiThreadedSpinner s(4);
//ros::spin(s);

}
