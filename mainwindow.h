#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"qextserialport/win_qextserialport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Win_QextSerialPort *myCom;

private slots:
    void  readMyCom();
};

#endif // MAINWINDOW_H
