/**
 * @file /src/main.cpp
 *
 * @brief Qt based gui.
 *
 * @date November 2010
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QApplication>
#include "../include/ui_pkg/main_window.hpp"
#include "../include/ui_pkg/signin.h"
#include "../include/ui_pkg/signup.h"
#include "../include/ui_pkg/control.h"
#include "../include/ui_pkg/showwarning.h"


#include <stdlib.h>

#include <QDebug>

/*****************************************************************************
** Main
*****************************************************************************/

int main(int argc, char **argv) {

    /*********************
    ** Qt
    **********************/
    QApplication app(argc, argv);
    ui_pkg::MainWindow *w = new ui_pkg::MainWindow(argc, argv);
    w->show();
    //w->show();
    //system("rospack list");

    ShowWarning *s = new ShowWarning;
    s->show();

//    SignIn *s = new SignIn;
//    s->mainwindow = w;
//    s->qnode = &w->qnode;
//    s->show();

//    SignUp *signUp = new SignUp;
//    signUp->show();

    //s->setGeometry(0, 0, s->width(), s->height());
    //system("gnome-terminal -x bash -c 'echo OK1|less'&");
    //system("gnome-terminal -x bash -c 'echo OK2|less'&");

    //system("roscore&");
    //system("rosrun turtlesim turtlesim_node&");
    //system("rviz&");


//    Control *c = new Control;
//    c->qnode = &w->qnode;
//    c->show();
    qDebug() << 1;
    //Control c;
    //c.show();

    //app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));



    int result = app.exec();

    return result;
}
