#include "../include/ui_pkg/showwarning.h"
#include "../include/ui_pkg/main_window.hpp"
#include "cv_bridge/cv_bridge.h"

#include "ui_showwarning.h"

ShowWarning::ShowWarning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowWarning) {
    ui->setupUi(this);

    //设置固定大小
    setFixedSize(1200, 900);
    //让窗口居中
    MoveToMid(this);

    setWindowTitle("警报!");

    cv_bridge::CvImagePtr cv_ptr;

    //深拷贝转换为opencv类型
    //cv_ptr = cv_bridge::toCvCopy(msg, msg->encoding);
    //QImage image = Mat2QImage(cv_ptr->image);


//    QPixmap pixmap = QPixmap::fromImage(image);
//    pixmap.scaled(ui->titleLabel->size(), Qt::KeepAspectRatio);
//    ui->titleLabel->setScaledContents(true);
    //ui->titleLabel->setPixmap(pixmap);



}

ShowWarning::~ShowWarning() {
    delete ui;
}

void ShowWarning::on_close_clicked() {
    this->close();
}

QImage ShowWarning::Mat2QImage(cv::Mat &image) {
    QImage img;

    if (image.channels() == 3) {
        cvtColor(image, image, CV_BGR2RGB);
        img = QImage((const unsigned char *)(image.data), image.cols, image.rows,
                     image.cols * image.channels(), QImage::Format_RGB888);
    } else if (image.channels() == 1) {
        img = QImage((const unsigned char *)(image.data), image.cols, image.rows,
                     image.cols * image.channels(), QImage::Format_ARGB32);
    } else {
        img = QImage((const unsigned char *)(image.data), image.cols, image.rows,
                     image.cols * image.channels(), QImage::Format_RGB888);
    }

    return img;
}
