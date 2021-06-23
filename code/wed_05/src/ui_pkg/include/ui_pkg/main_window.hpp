/**
 * @file /include/ui_pkg/main_window.hpp
 *
 * @brief Qt based gui for ui_pkg.
 *
 * @date November 2010
 **/
#ifndef ui_pkg_MAIN_WINDOW_H
#define ui_pkg_MAIN_WINDOW_H


#define SetRelaPos(posSon) {\
        posSon->move(this->x() + (this->width() - posSon->width()) / 2, this->y() + (this->height() - posSon->height()) / 2);}

#include <QDesktopWidget>



#define MoveToMid(w) {\
        QDesktopWidget* desktop = QApplication::desktop();\
        w->move ((QApplication::desktop()->width() - w->width())/2,(QApplication::desktop()->height() - w->height())/2);}
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>

#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace ui_pkg {

    /*****************************************************************************
    ** Interface [MainWindow]
    *****************************************************************************/
    /**
     * @brief Qt central, all operations relating to the view part here.
     */
    class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        MainWindow(int argc, char **argv, QWidget *parent = 0);
        ~MainWindow();

        void ReadSettings(); // Load up qt program settings at startup
        void WriteSettings(); // Save qt program settings when closing

        QNode qnode;


    Q_SIGNALS:



    public Q_SLOTS:
        /******************************************
        ** Auto-connections (connectSlotsByName())
        *******************************************/



    private:
        Ui::MainWindowDesign ui;


    protected:

        void closeEvent(QCloseEvent *event); // Overloaded function
    private slots:
        void on_mapBtn_clicked();
        void on_controlBtn_clicked();
        void on_exit_clicked();
        void on_routeBtn_clicked();
        void on_warningBtn_clicked();
    };

}  // namespace ui_pkg

#endif // ui_pkg_MAIN_WINDOW_H
