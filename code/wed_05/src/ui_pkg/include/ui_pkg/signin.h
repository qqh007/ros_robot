#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include "main_window.hpp"
#include "qnode.hpp"

namespace Ui {
    class SignIn;
}

class SignIn : public QWidget {
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();
    void setQnode(ui_pkg::QNode *);
    void keyPressEvent(QKeyEvent *event);

    ui_pkg::QNode *qnode;
    ui_pkg::MainWindow *mainwindow;

private slots:
    void on_loginBtn_clicked();

    void on_signup_clicked();

private:
    Ui::SignIn *ui;

};

#endif // SIGNIN_H
