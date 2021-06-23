#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include<rviz/tool_manager.h>

#include "qnode.hpp"
#include "main_window.hpp"


class QNode;

namespace Ui {
    class Control;
}

class Control : public QMainWindow {
    Q_OBJECT

public:
    explicit Control(QWidget *parent = 0);
    ~Control();
    ui_pkg::QNode *qnode;
    ui_pkg::MainWindow *mainwindow;


    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);




public Q_SLOTS:
    void on_up_clicked(); //add
    void on_down_clicked(); //add
    void on_left_clicked(); //add
    void on_right_clicked();  //add

private slots:
    void on_stop_clicked();

    void on_finishBtn_clicked();

private:
    Ui::Control *ui;
    rviz::VisualizationManager *manager_;
    rviz::RenderPanel *render_panel_;

    rviz::Display *map_;

    void display_rviz();
};

#endif // CONTROL_H
