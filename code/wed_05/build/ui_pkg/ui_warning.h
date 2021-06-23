/********************************************************************************
** Form generated from reading UI file 'warning.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNING_H
#define UI_WARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Warning
{
public:
    QAction *actionexit;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuexit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Warning)
    {
        if (Warning->objectName().isEmpty())
            Warning->setObjectName(QStringLiteral("Warning"));
        Warning->resize(800, 600);
        actionexit = new QAction(Warning);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralwidget = new QWidget(Warning);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 0, 782, 556));
        Warning->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Warning);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuexit = new QMenu(menubar);
        menuexit->setObjectName(QStringLiteral("menuexit"));
        Warning->setMenuBar(menubar);
        statusbar = new QStatusBar(Warning);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Warning->setStatusBar(statusbar);

        menubar->addAction(menuexit->menuAction());
        menuexit->addAction(actionexit);

        retranslateUi(Warning);

        QMetaObject::connectSlotsByName(Warning);
    } // setupUi

    void retranslateUi(QMainWindow *Warning)
    {
        Warning->setWindowTitle(QApplication::translate("Warning", "MainWindow", 0));
        actionexit->setText(QApplication::translate("Warning", "exit", 0));
        menuexit->setTitle(QApplication::translate("Warning", "exit", 0));
    } // retranslateUi

};

namespace Ui {
    class Warning: public Ui_Warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNING_H
