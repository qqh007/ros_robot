#ifndef PATROLROUTE_H
#define PATROLROUTE_H

#include <QMainWindow>
#include "main_window.hpp"
#include "qnode.hpp"

namespace Ui {
    class PatrolRoute;
}

class PatrolRoute : public QMainWindow {
    Q_OBJECT

public:
    explicit PatrolRoute(QWidget *parent = 0);
    ui_pkg::MainWindow *mainwindow;
    ui_pkg::QNode *qnode;

    ~PatrolRoute();

private slots:
    void on_save_clicked();

    void on_begin_clicked();

    void on_return_2_clicked();

private:
    Ui::PatrolRoute *ui;
};

#endif // PATROLROUTE_H
