#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "logindialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //m_pCore = new Core();
    /*LoginDialog ldg;
    int res = -1;
    do
    {
        ldg.exec();
        res = m_pCore->Authenticate(ldg.GetLoginName().toStdString(),ldg.GetPassword().toStdString());
    }while(res==-1 && ldg.result() != QDialog::Rejected);*/
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete m_pCore;
}
