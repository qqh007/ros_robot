#include "../include/ui_pkg/signin.h"
#include "../include/ui_pkg/signup.h"
#include "../include/ui_pkg/main_window.hpp"
#include "ui_signin.h"

#include <stdlib.h>

#include <QDebug>
#include <QDesktopWidget>
#include <QString>
#include <QMessageBox>
#include <iostream>

SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn) {
    ui->setupUi(this);

    setWindowTitle("登录");




    //设置固定大小
    setFixedSize(600, 400);

    MoveToMid(this);

    //设置icon
    QPixmap *pixmap = new QPixmap("/home/robot/catkin_ws/src/2021_embedded/wed_05/src/ui_pkg/resources/images/robot.png");
    //QPixmap *pixmap = new QPixmap(":/images/robot.png");
    pixmap->scaled(ui->iconLabel->size(), Qt::KeepAspectRatio);
    ui->iconLabel->setScaledContents(true);
    ui->iconLabel->setPixmap(*pixmap);

    //设置标题字体
    ui->titleLabel->setFont(QFont("Microsoft YaHei", 14, QFont::Bold));




}

SignIn::~SignIn() {
    delete ui;
}



void SignIn::setQnode(ui_pkg::QNode *q) {
    this->qnode = q;
}

void SignIn::on_loginBtn_clicked() {
    QString user = ui->username->text();
    QString password = ui->password->text();

    std::string answer = qnode->login(user.toStdString(), password.toStdString());

    if(user.isEmpty() || password.isEmpty()) {
        QMessageBox::information(NULL, tr("提示"), tr("用户名或密码不能为空！"));
        return;
    }
//    if(user == "qqq" && password == "s") {
//        QMessageBox::information(NULL, tr("提示"), tr("登陆成功！"));
//        this->close();
//        this->mainwindow->show();

//    } else {
//        QMessageBox::information(NULL, tr("提示"), tr("用户名或密码错误！"));
//        return;
//    }


    std::cout << "user:" + user.toStdString() + "   pswd:" + password.toStdString() << endl;


    if(answer == "code correct") {
        // QMessageBox::information(NULL, "提示", "登陆成功",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        QMessageBox::information(NULL, tr("提示"), tr("登陆成功！"));
        this->mainwindow->show();
        this->close();
    } else {
        QMessageBox::information(NULL, tr("提示"), tr("用户名或密码错误！"));
        return;
    }
}

void SignIn::on_signup_clicked() {

    SignUp *signUp = new SignUp;
    signUp->mainwindow = this->mainwindow;
    signUp->qnode = qnode;
    signUp->show();

    //设置关闭时自动释放内存
    signUp->QWidget::setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}
void SignIn::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        on_loginBtn_clicked();
    }
}



