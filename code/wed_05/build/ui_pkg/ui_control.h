/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

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

class Ui_Control
{
public:
    QAction *actionexit;
    QWidget *centralwidget;
    QPushButton *finishBtn;
    QPushButton *up;
    QPushButton *left;
    QPushButton *right;
    QPushButton *down;
    QPushButton *stop;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *rvizLayout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Control)
    {
        if (Control->objectName().isEmpty())
            Control->setObjectName(QStringLiteral("Control"));
        Control->resize(800, 600);
        actionexit = new QAction(Control);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralwidget = new QWidget(Control);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        finishBtn = new QPushButton(centralwidget);
        finishBtn->setObjectName(QStringLiteral("finishBtn"));
        finishBtn->setGeometry(QRect(530, 390, 161, 61));
        up = new QPushButton(centralwidget);
        up->setObjectName(QStringLiteral("up"));
        up->setGeometry(QRect(590, 139, 50, 50));
        left = new QPushButton(centralwidget);
        left->setObjectName(QStringLiteral("left"));
        left->setGeometry(QRect(530, 200, 50, 50));
        right = new QPushButton(centralwidget);
        right->setObjectName(QStringLiteral("right"));
        right->setGeometry(QRect(650, 200, 50, 50));
        down = new QPushButton(centralwidget);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(590, 260, 50, 50));
        stop = new QPushButton(centralwidget);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setGeometry(QRect(590, 200, 50, 50));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 110, 331, 331));
        rvizLayout = new QVBoxLayout(verticalLayoutWidget);
        rvizLayout->setObjectName(QStringLiteral("rvizLayout"));
        rvizLayout->setContentsMargins(0, 0, 0, 0);
        Control->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Control);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Control->setStatusBar(statusbar);

        retranslateUi(Control);

        QMetaObject::connectSlotsByName(Control);
    } // setupUi

    void retranslateUi(QMainWindow *Control)
    {
        Control->setWindowTitle(QApplication::translate("Control", "MainWindow", 0));
        actionexit->setText(QApplication::translate("Control", "exit", 0));
        finishBtn->setText(QApplication::translate("Control", "\351\200\200\345\207\272", 0));
        up->setText(QApplication::translate("Control", "\342\206\221", 0));
        left->setText(QApplication::translate("Control", "\342\206\220", 0));
        right->setText(QApplication::translate("Control", "\342\206\222", 0));
        down->setText(QApplication::translate("Control", "\342\206\223", 0));
        stop->setText(QApplication::translate("Control", "O", 0));
    } // retranslateUi

};

namespace Ui {
    class Control: public Ui_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
