#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    struct PortSettings myComSetting={BAUD115200,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,500};
    myCom = new Win_QextSerialPort("com7",myComSetting,QextSerialBase::EventDriven);
    myCom->open(QIODevice::ReadWrite);
    connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::readMyCom()
{
    QByteArray temp=myCom->readAll();
    ui->textBrowser->insertPlainText(temp);


}
