#ifndef WARNING_H
#define WARNING_H

#include <QMainWindow>

namespace Ui {
class Warning;
}

class Warning : public QMainWindow
{
  Q_OBJECT

public:
  explicit Warning(QWidget *parent = 0);
  ~Warning();

private:
  Ui::Warning *ui;
};

#endif // WARNING_H
