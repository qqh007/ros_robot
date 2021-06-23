#include "../include/ui_pkg/patrolroute.h"
#include "../include/ui_pkg/signin.h"
#include "../include/ui_pkg/main_window.hpp"

#include "ui_patrolroute.h"
#include <QMessageBox>

PatrolRoute::PatrolRoute(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PatrolRoute) {
    ui->setupUi(this);

    //设置大小
    setFixedSize(800, 600);

    setWindowTitle("设置巡逻路线");

    MoveToMid(this);

    //设置地图图片
//    QPixmap *mapPixmap = new QPixmap("/home/kidleyh/work_space/windows_ui/src/ui_pkg/resources/images//map.png");
//    mapPixmap->scaled(ui->mapLabel->size(), Qt::KeepAspectRatio);
//    ui->mapLabel->setScaledContents(true);
//    ui->mapLabel->setPixmap(*mapPixmap);


//    //点击exit回到登录界面
//    connect(ui->actionexit, &QAction::triggered, [ = ]() {
//        this->close();
//        SignIn *s = new SignIn;
//        s->setWindowTitle("登录");
//        //w->setFixedSize(600,400);
//        SetRelaPos(s);
//        s->show();
//        //设置关闭时自动释放内存
//        s->QWidget::setAttribute(Qt::WA_DeleteOnClose);
//    });
}

PatrolRoute::~PatrolRoute() {
    delete ui;
}


void PatrolRoute::on_save_clicked() {
    float x1 = ui->x1->text().toFloat();
    float y1 = ui->y1->text().toFloat();
    float x2 = ui->x2->text().toFloat();
    float y2 = ui->y2->text().toFloat();
    float x3 = ui->x3->text().toFloat();
    float y3 = ui->y3->text().toFloat();
    std::vector<float> positions = {x1, y1, x2, y2, x3, y3};
    qnode->sendPosition(positions);
    QMessageBox::information(NULL, tr("提示"), tr("航点保存成功！"));
}

void PatrolRoute::on_begin_clicked() {
//system("gnome-terminal -x bash -c 'echo OK1|less'&");
    system("gnome-terminal -x bash -c 'source ~/.bashrc;roslaunch nav_pkg nav.launch'&");
}

void PatrolRoute::on_return_2_clicked() {
    mainwindow->show();
    MoveToMid(mainwindow);
    this->close();
}
