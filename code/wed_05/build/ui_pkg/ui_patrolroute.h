/********************************************************************************
** Form generated from reading UI file 'patrolroute.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATROLROUTE_H
#define UI_PATROLROUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatrolRoute
{
public:
    QAction *actionexit;
    QWidget *centralwidget;
    QPushButton *return_2;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLabel *label;
    QPushButton *save;
    QPushButton *begin;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *x1;
    QLineEdit *y1;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *x2;
    QLineEdit *y2;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *x3;
    QLineEdit *y3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatrolRoute)
    {
        if (PatrolRoute->objectName().isEmpty())
            PatrolRoute->setObjectName(QStringLiteral("PatrolRoute"));
        PatrolRoute->resize(800, 600);
        actionexit = new QAction(PatrolRoute);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralwidget = new QWidget(PatrolRoute);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        return_2 = new QPushButton(centralwidget);
        return_2->setObjectName(QStringLiteral("return_2"));
        return_2->setGeometry(QRect(530, 380, 161, 61));
        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(90, 150, 289, 41));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label);

        save = new QPushButton(centralwidget);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(530, 150, 161, 61));
        begin = new QPushButton(centralwidget);
        begin->setObjectName(QStringLiteral("begin"));
        begin->setGeometry(QRect(530, 270, 161, 61));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 100, 231, 41));
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 160, 291, 301));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        x1 = new QLineEdit(widget);
        x1->setObjectName(QStringLiteral("x1"));

        horizontalLayout_3->addWidget(x1);

        y1 = new QLineEdit(widget);
        y1->setObjectName(QStringLiteral("y1"));

        horizontalLayout_3->addWidget(y1);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        x2 = new QLineEdit(widget);
        x2->setObjectName(QStringLiteral("x2"));

        horizontalLayout_5->addWidget(x2);

        y2 = new QLineEdit(widget);
        y2->setObjectName(QStringLiteral("y2"));

        horizontalLayout_5->addWidget(y2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        x3 = new QLineEdit(widget);
        x3->setObjectName(QStringLiteral("x3"));

        horizontalLayout_7->addWidget(x3);

        y3 = new QLineEdit(widget);
        y3->setObjectName(QStringLiteral("y3"));

        horizontalLayout_7->addWidget(y3);


        verticalLayout->addLayout(horizontalLayout_7);

        PatrolRoute->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(PatrolRoute);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PatrolRoute->setStatusBar(statusbar);

        retranslateUi(PatrolRoute);

        QMetaObject::connectSlotsByName(PatrolRoute);
    } // setupUi

    void retranslateUi(QMainWindow *PatrolRoute)
    {
        PatrolRoute->setWindowTitle(QApplication::translate("PatrolRoute", "MainWindow", 0));
        actionexit->setText(QApplication::translate("PatrolRoute", "exit", 0));
        return_2->setText(QApplication::translate("PatrolRoute", "\350\277\224\345\233\236", 0));
        label_2->setText(QApplication::translate("PatrolRoute", "X\345\235\220\346\240\207", 0));
        label->setText(QApplication::translate("PatrolRoute", "Y\345\235\220\346\240\207", 0));
        save->setText(QApplication::translate("PatrolRoute", "\344\277\235\345\255\230\350\210\252\347\202\271", 0));
        begin->setText(QApplication::translate("PatrolRoute", "\345\274\200\345\247\213\345\257\274\350\210\252", 0));
        label_3->setText(QApplication::translate("PatrolRoute", "\350\256\276\347\275\256\350\210\252\347\202\271\357\274\232\347\233\270\345\257\271\344\272\216\346\234\272\345\231\250\344\272\272\357\274\210m\357\274\211", 0));
    } // retranslateUi

};

namespace Ui {
    class PatrolRoute: public Ui_PatrolRoute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATROLROUTE_H
