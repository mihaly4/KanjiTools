#include "userdialog.h"
#include "ui_userdialog.h"
#include "core.h"
#include "connector_wraper.h"

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    connect(this,SIGNAL(user_loaded_signal(void*)),this,SLOT(user_loaded_slot(void*)));
}

UserDialog::~UserDialog()
{
    delete ui;
}

user_t UserDialog::GetUser()
{
    user_t u;
    u.name = ui->lineEdit->text().toStdString();
    u.surename = ui->lineEdit_2->text().toStdString();
    u.login = ui->lineEdit_3->text().toStdString();
    u.password = ui->lineEdit_4->text().toStdString();
    if(ui->radioButton->isChecked())
        u.account_type = ACCOUNT_TYPE_ADMIN;
    else if(ui->radioButton_2->isChecked())
        u.account_type = ACCOUNT_TYPE_TEACHER;
    else
        u.account_type = ACCOUNT_TYPE_STUDENT;
    u.id = user_id;
    return u;
}

void UserDialog::SetUser(std::string id)
{
    m_pCore->AddQuery("SELECT * FROM kanjitools.person WHERE `Person_ID` = "+id+";",user_loaded,this);
}

void UserDialog::SetCore(Core *core)
{
    m_pCore = core;
}

void UserDialog::user_loaded(void *obj, void *a)
{
    emit ((UserDialog*)obj)->user_loaded_signal(a);
}

void UserDialog::user_loaded_slot(void *a)
{
    sql::ResultSet *res=(sql::ResultSet *)a;
    while(res->next())
    {
        user_id = res->getString(1);
        ui->lineEdit->setText(res->getString(4).c_str());
        ui->lineEdit_2->setText(res->getString(5).c_str());
        ui->lineEdit_3->setText(res->getString(2).c_str());
        ui->lineEdit_4->setText(res->getString(3).c_str());
        if(res->getString(6)=="1")
            ui->radioButton->setChecked(true);
        else if(res->getString(6)=="2")
            ui->radioButton_2->setChecked(true);
        else
            ui->radioButton_3->setChecked(true);
    }
    delete res;
}

/*Ui::UserDialog * UserDialog::getUi(){
    return ui;
}*/

/*QWidget * UserDialog::FindWidgetByName(QString name){
    return //ui;// this->find("ui");
}*/
