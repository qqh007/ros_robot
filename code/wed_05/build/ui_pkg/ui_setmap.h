/********************************************************************************
** Form generated from reading UI file 'setmap.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETMAP_H
#define UI_SETMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetMap
{
public:
    QAction *actionexit;
    QWidget *centralwidget;
    QPushButton *up;
    QPushButton *left;
    QPushButton *cancel;
    QPushButton *down;
    QPushButton *stop;
    QPushButton *right;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *rvizLayout_;
    QPushButton *begin;
    QPushButton *finish;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SetMap)
    {
        if (SetMap->objectName().isEmpty())
            SetMap->setObjectName(QStringLiteral("SetMap"));
        SetMap->resize(800, 600);
        actionexit = new QAction(SetMap);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralwidget = new QWidget(SetMap);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        up = new QPushButton(centralwidget);
        up->setObjectName(QStringLiteral("up"));
        up->setGeometry(QRect(580, 139, 50, 50));
        left = new QPushButton(centralwidget);
        left->setObjectName(QStringLiteral("left"));
        left->setGeometry(QRect(520, 200, 50, 50));
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(560, 440, 161, 61));
        down = new QPushButton(centralwidget);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(580, 260, 50, 50));
        stop = new QPushButton(centralwidget);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setGeometry(QRect(580, 200, 50, 50));
        right = new QPushButton(centralwidget);
        right->setObjectName(QStringLiteral("right"));
        right->setGeometry(QRect(640, 200, 50, 50));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 90, 301, 281));
        rvizLayout_ = new QVBoxLayout(verticalLayoutWidget);
        rvizLayout_->setObjectName(QStringLiteral("rvizLayout_"));
        rvizLayout_->setContentsMargins(0, 0, 0, 0);
        begin = new QPushButton(centralwidget);
        begin->setObjectName(QStringLiteral("begin"));
        begin->setGeometry(QRect(80, 440, 161, 61));
        finish = new QPushButton(centralwidget);
        finish->setObjectName(QStringLiteral("finish"));
        finish->setGeometry(QRect(320, 440, 161, 61));
        SetMap->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SetMap);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SetMap->setStatusBar(statusbar);

        retranslateUi(SetMap);

        QMetaObject::connectSlotsByName(SetMap);
    } // setupUi

    void retranslateUi(QMainWindow *SetMap)
    {
        SetMap->setWindowTitle(QApplication::translate("SetMap", "MainWindow", 0));
        actionexit->setText(QApplication::translate("SetMap", "exit", 0));
        up->setText(QApplication::translate("SetMap", "\342\206\221", 0));
        left->setText(QApplication::translate("SetMap", "\342\206\220", 0));
        cancel->setText(QApplication::translate("SetMap", "\345\217\226\346\266\210", 0));
        down->setText(QApplication::translate("SetMap", "\342\206\223", 0));
        stop->setText(QApplication::translate("SetMap", "O", 0));
        right->setText(QApplication::translate("SetMap", "\342\206\222", 0));
        begin->setText(QApplication::translate("SetMap", "\345\274\200\345\247\213\345\273\272\345\233\276", 0));
        finish->setText(QApplication::translate("SetMap", "\345\256\214\346\210\220\345\273\272\345\233\276", 0));
    } // retranslateUi

};

namespace Ui {
    class SetMap: public Ui_SetMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETMAP_H
