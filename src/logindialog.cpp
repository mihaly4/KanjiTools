#include "logindialog.h"
#include "ui_logindialog.h"
#include "core.h"
#include "kanjitoolswindow.h"

LoginDialog * LoginDialog::current_dialog =NULL;

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    current_dialog = this;
    m_pCore = NULL;
}
void LoginDialog::SetCore(Core * core)
{
    m_pCore = core;
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

void LoginDialog::on_buttonBox_accepted()
{
    KanjiToolsWindow * ktw = (KanjiToolsWindow*)this->parent();
    m_pCore->Authenticate(GetLoginName().toStdString(),
                          GetPassword().toStdString(),ktw->authentication,ktw);
}

void LoginDialog::on_buttonBox_rejected()
{
    exit(0);
}
