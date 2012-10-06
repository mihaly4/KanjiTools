#include "kanjitoolswindow.h"
#include "ui_kanjitoolswindow.h"
#include "logindialog.h"
#include "core.h"
#include <QDebug>
#include <cppconn/resultset.h>

KanjiToolsWindow::KanjiToolsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KanjiToolsWindow)
{
    ui->setupUi(this);

    m_pCore = new Core();
    LoginDialog ldg;
    int res = -1;
    do
    {
        ldg.exec();
        res = m_pCore->Authenticate(ldg.GetLoginName().toStdString(),ldg.GetPassword().toStdString());
    }while(res==-1 && ldg.result() != QDialog::Rejected);
    if(res == -1)
        close();
    //else
    {
        HideUnusedTabs(m_pCore->GetLevel());
    }
    connect(this,SIGNAL(users_loaded_signal(void*)),this,SLOT(users_loaded_slot(void*)));
}

KanjiToolsWindow::~KanjiToolsWindow()
{
    delete ui;
    delete m_pCore;
}

void KanjiToolsWindow::HideUnusedTabs(int level)
{
    switch(level)
    {
    case ACCOUNT_TYPE_ERROR:
        ui->tabWidget->removeTab(1);
        ui->tabWidget->removeTab(0);
        break;
    case ACCOUNT_TYPE_TEACHER:
        //ui->tabWidget->removeTab(1);
        //ui->tabWidget->removeTab(0);
        break;
    case ACCOUNT_TYPE_STUDENT:
        //ui->tabWidget->removeTab(1);
        //ui->tabWidget->removeTab(0);
        break;
    }
}

void KanjiToolsWindow::on_pushButton_clicked()
{
    m_pCore->AddQuery("drop schema `kanjitools`;");
    m_pCore->AddQuery("CREATE SCHEMA `kanjitools` DEFAULT CHARACTER SET ujis COLLATE ujis_japanese_ci ;");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`tutor` (     `Person_ID` INT NOT NULL AUTO_INCREMENT ,    `Name` TINYTEXT NOT NULL ,    `Surename` TINYTEXT NOT NULL ,    PRIMARY KEY (`Person_ID`) );");
    m_pCore->AddQuery("INSERT INTO kanjitools.tutor (`Name`,`Surename`) VALUES(\"教師\",\"ehe\");");
}
void KanjiToolsWindow::users_loaded(void * obj, void * arg)
{
    emit ((KanjiToolsWindow*)obj)->users_loaded_signal(arg);
}
void KanjiToolsWindow::users_loaded_slot(void * a)
{
     sql::ResultSet *res=(sql::ResultSet *)a;
     while (res->next())
     {
       //std::cout << "\t... MySQL replies: ";
       // Access column data by alias or column name
       //std::cout << res->getString("_message") << std::endl;
       //std::cout << res->getString(1) << std::endl;
       //std::cout << res->getString(2).c_str() << std::endl;
       //std::cout << res->getString(3) << std::endl;
       ui->listWidget->addItem((res->getString(2)+" "+res->getString(3)).c_str());

     }
     delete res;
}

void KanjiToolsWindow::on_tabWidget_currentChanged(QWidget *arg1)
{
    if(arg1 == ui->tab_3)//users
    {
        /// TODO: Refresh user list

        m_pCore->AddQuery("SELECT * FROM kanjitools.tutor;",users_loaded,this);
    }
}
