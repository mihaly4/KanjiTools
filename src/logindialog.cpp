#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
QString LoginDialog::GetLoginName()
{
    return ui->lineEdit->text();
}
QString LoginDialog::GetPassword()
{
    return ui->lineEdit_2->text();
}
