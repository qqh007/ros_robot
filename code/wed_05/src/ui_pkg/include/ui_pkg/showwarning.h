#ifndef SHOWWARNING_H
#define SHOWWARNING_H

#include <QWidget>
#include <cv_bridge/cv_bridge.h>  //cv_bridge
#include <image_transport/image_transport.h>  //image_transport


namespace Ui {
    class ShowWarning;
}

class ShowWarning : public QWidget {
    Q_OBJECT

public:
    explicit ShowWarning(QWidget *parent = 0);
    ~ShowWarning();

    QImage Mat2QImage(cv::Mat &image);

private slots:
    void on_close_clicked();

private:
    Ui::ShowWarning *ui;
};

#endif // SHOWWARNING_H
