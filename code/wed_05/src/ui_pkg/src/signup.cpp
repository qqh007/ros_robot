#include "../include/ui_pkg/signup.h"
#include "../include/ui_pkg/signin.h"
#include "../include/ui_pkg/main_window.hpp"
#include "ui_signup.h"


#include <QDesktopWidget>
#include <QString>
#include <QMessageBox>


SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp) {
    ui->setupUi(this);

    //设置窗口标题
    setWindowTitle("注册");

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

SignUp::~SignUp() {
    delete ui;
}

void SignUp::on_siginup_clicked() {
    QString user = ui->username->text();
    QString password = ui->password->text();

    std::string answer = qnode->reg(user.toStdString(), password.toStdString());

    if(user.isEmpty() || password.isEmpty()) {
        QMessageBox::information(NULL, tr("提示"), tr("用户名或密码不能为空！"));
        return;
    }
    if(answer == "add user success") {
        // QMessageBox::information(NULL, "提示", "登陆成功",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        QMessageBox::information(NULL, tr("提示"), tr("注册成功！"));

        //      m->move(550,200);
        //      m->show();
        //this->close();
    } else {
        QMessageBox::information(NULL, tr("提示"), tr("用户名已存在！"));
        return;
    }
}

void SignUp::on_goLogin_clicked() {

    SignIn *s = new SignIn;
    s->mainwindow = this->mainwindow;
    s->qnode = qnode;
    s->show();
    //设置关闭时自动释放内存
    s->QWidget::setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}

void SignUp::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        on_siginup_clicked();
    }
}
