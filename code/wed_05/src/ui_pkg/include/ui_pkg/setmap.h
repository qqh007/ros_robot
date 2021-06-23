#ifndef SETMAP_H
#define SETMAP_H

#include <QMainWindow>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include<rviz/tool_manager.h>
#include "main_window.hpp"
#include "qnode.hpp"
namespace Ui {
    class SetMap;
}

class SetMap : public QMainWindow {
    Q_OBJECT

public:
    explicit SetMap(QWidget *parent = 0);
    ~SetMap();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    ui_pkg::MainWindow *mainWindow;
    ui_pkg::QNode *qnode;


private slots:
    void on_cancel_clicked();

    void on_up_clicked();

    void on_down_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_stop_clicked();

    void on_begin_clicked();

    void on_finish_clicked();

private:
    Ui::SetMap *ui;

    rviz::VisualizationManager *manager_;
    rviz::RenderPanel *render_panel_;

    rviz::Display *map_;

    void display_rviz();
};

#endif // SETMAP_H
