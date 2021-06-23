/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QWidget *widget_2;
    QLabel *iconLabel;
    QLabel *titleLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *mapBtn;
    QPushButton *routeBtn;
    QPushButton *warningBtn;
    QPushButton *controlBtn;
    QPushButton *exit;
    QLabel *photoLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QStringLiteral("MainWindowDesign"));
        MainWindowDesign->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QStringLiteral("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(90, 10, 571, 101));
        iconLabel = new QLabel(widget_2);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));
        iconLabel->setGeometry(QRect(130, 10, 80, 80));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(iconLabel->sizePolicy().hasHeightForWidth());
        iconLabel->setSizePolicy(sizePolicy);
        titleLabel = new QLabel(widget_2);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(310, 30, 141, 51));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(430, 90, 311, 451));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mapBtn = new QPushButton(widget);
        mapBtn->setObjectName(QStringLiteral("mapBtn"));

        verticalLayout->addWidget(mapBtn);

        routeBtn = new QPushButton(widget);
        routeBtn->setObjectName(QStringLiteral("routeBtn"));

        verticalLayout->addWidget(routeBtn);

        warningBtn = new QPushButton(widget);
        warningBtn->setObjectName(QStringLiteral("warningBtn"));

        verticalLayout->addWidget(warningBtn);

        controlBtn = new QPushButton(widget);
        controlBtn->setObjectName(QStringLiteral("controlBtn"));

        verticalLayout->addWidget(controlBtn);

        exit = new QPushButton(widget);
        exit->setObjectName(QStringLiteral("exit"));

        verticalLayout->addWidget(exit);

        photoLabel = new QLabel(centralwidget);
        photoLabel->setObjectName(QStringLiteral("photoLabel"));
        photoLabel->setGeometry(QRect(50, 150, 331, 331));
        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", 0));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0));
        iconLabel->setText(QApplication::translate("MainWindowDesign", "\345\233\276\346\240\207", 0));
        titleLabel->setText(QApplication::translate("MainWindowDesign", "\345\267\241\346\243\200\346\234\272\345\231\250\344\272\272", 0));
        mapBtn->setText(QApplication::translate("MainWindowDesign", "\345\234\260\345\233\276\345\273\272\346\250\241", 0));
        routeBtn->setText(QApplication::translate("MainWindowDesign", "\345\267\241\351\200\273\345\257\274\350\210\252", 0));
        warningBtn->setText(QApplication::translate("MainWindowDesign", "\346\212\245\350\255\246\346\243\200\346\265\213", 0));
        controlBtn->setText(QApplication::translate("MainWindowDesign", "\346\211\213\345\212\250\346\216\247\345\210\266", 0));
        exit->setText(QApplication::translate("MainWindowDesign", "\351\200\200\345\207\272", 0));
        photoLabel->setText(QApplication::translate("MainWindowDesign", "\346\234\272\345\231\250\344\272\272\345\233\276\347\211\207", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
