#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "main_window.hpp"
#include "qnode.hpp"

namespace Ui {
    class SignUp;
}

class SignUp : public QWidget {
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();

    void keyPressEvent(QKeyEvent *event);

    ui_pkg::MainWindow *mainwindow;
    ui_pkg::QNode *qnode;

private slots:
    void on_siginup_clicked();

    void on_goLogin_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
