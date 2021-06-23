#include "../include/ui_pkg/warning.h"
#include "../include/ui_pkg/signin.h"
#include "../include/ui_pkg/main_window.hpp"

#include "ui_warning.h"

Warning::Warning(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Warning) {
    ui->setupUi(this);

    //设置大小
    setFixedSize(800, 600);

    //设置表格
    ui->tableWidget->setColumnCount(2);

    QStringList list;
    list << "报警情况" << "选择";
    ui->tableWidget->setHorizontalHeaderLabels(list);
    //设置行数
    ui->tableWidget->setRowCount(3);
    //设置每一行的高度
    for(int i = 0; i < 3; i++) {
        ui->tableWidget->setRowHeight(i, 60);
    }


    ui->tableWidget->setColumnWidth(0, 610);
    //自动调整最后一列的宽度使它和表格的右边界对齐
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //设置表格内容
    QTableWidgetItem *item00, *item01, *item10, *item11, *item20, *item21;
    item00 = new QTableWidgetItem;
    item01 = new QTableWidgetItem;
    item10 = new QTableWidgetItem;
    item11 = new QTableWidgetItem;
    item20 = new QTableWidgetItem;
    item21 = new QTableWidgetItem;

    item00->setText("发现火情！");
    ui->tableWidget->setItem(0, 0, item00);
    item01->setText("是");
    ui->tableWidget->setItem(0, 1, item01);

    item10->setText("发现外来人员！");
    ui->tableWidget->setItem(1, 0, item10);
    item11->setText("是");
    ui->tableWidget->setItem(1, 1, item11);

    item20->setText("其他报警情况！");
    ui->tableWidget->setItem(2, 0, item20);
    item21->setText("否");
    ui->tableWidget->setItem(2, 1, item21);

    //点击exit回到登录界面
    connect(ui->actionexit, &QAction::triggered, [ = ]() {
        this->close();
        SignIn *s = new SignIn;
        s->setWindowTitle("登录");
        //w->setFixedSize(600,400);
        SetRelaPos(s);
        s->show();
        //设置关闭时自动释放内存
        s->QWidget::setAttribute(Qt::WA_DeleteOnClose);
    });

}

Warning::~Warning() {
    delete ui;
}
