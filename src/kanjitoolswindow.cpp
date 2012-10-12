#include "kanjitoolswindow.h"
#include "ui_kanjitoolswindow.h"
#include "logindialog.h"
#include "core.h"
#include <QDebug>
#include <cppconn/resultset.h>
#include "kanjidialog.h"

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
    connect(this,SIGNAL(courses_loaded_signal(void*)),this,SLOT(courses_loaded_slot(void*)));
    connect(this,SIGNAL(cadets_loaded_signal(void*)),this,SLOT(cadets_loaded_slot(void*)));
    connect(this,SIGNAL(materials_loaded_signal(void*)),this,SLOT(materials_loaded_slot(void*)));
    connect(this,SIGNAL(kanji_loaded_signal(void*)),this,SLOT(kanji_loaded_slot(void*)));
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
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`person` (     `Person_ID` INT NOT NULL AUTO_INCREMENT ,    `Name` TINYTEXT NOT NULL ,    `Surename` TINYTEXT NOT NULL , `account_type` INT,   PRIMARY KEY (`Person_ID`) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`course` ( `Name` TINYTEXT NOT NULL , `Tutor_ID` INT,   PRIMARY KEY (`Name`(10)) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`cadet_in_course` ( `Person_ID` INT NOT NULL , `course_name` TINYTEXT NOT NULL,  PRIMARY KEY (`Person_ID`,`course_name`(10)) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`material` ( `Material_ID` INT NOT NULL AUTO_INCREMENT , `title` TINYTEXT NOT NULL, `mat_type` INT,  PRIMARY KEY (`Material_ID`) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`accessibility` ( `Person_ID` INT NOT NULL , `Material_ID` INT NOT NULL, PRIMARY KEY (`Person_ID`,`Material_ID`) );");


    m_pCore->AddQuery("INSERT INTO kanjitools.person (`Name`,`Surename`,`account_type`) VALUES(\"教師\",\"ehe\",1);");
    m_pCore->AddQuery("INSERT INTO kanjitools.person (`Name`,`Surename`,`account_type`) VALUES(\"Carina\",\"Tsvetkova\",2);");
    m_pCore->AddQuery("INSERT INTO kanjitools.person (`Name`,`Surename`,`account_type`) VALUES(\"Sergej\",\"Andreyev\",2);");
    m_pCore->AddQuery("INSERT INTO kanjitools.person (`Name`,`Surename`,`account_type`) VALUES(\"Sergej\",\"Comov\",1);");
    m_pCore->AddQuery("INSERT INTO kanjitools.course (`Name`) VALUES(\"4202mv\");");
    m_pCore->AddQuery("INSERT INTO kanjitools.course (`Name`) VALUES(\"4201mv\");");
    m_pCore->AddQuery("INSERT INTO kanjitools.cadet_in_course (`Person_ID`,`course_name`) VALUES(2,\"4201mv\");");
    m_pCore->AddQuery("INSERT INTO kanjitools.cadet_in_course (`Person_ID`,`course_name`) VALUES(3,\"4201mv\");");
    m_pCore->AddQuery("INSERT INTO kanjitools.material (`title`,`mat_type`) VALUES(\"kanji group no 1\",1);");
    m_pCore->AddQuery("INSERT INTO kanjitools.material (`title`,`mat_type`) VALUES(\"kanji group no 2\",1);");
    m_pCore->AddQuery("INSERT INTO kanjitools.material (`title`,`mat_type`) VALUES(\"test no 1\",2);");
    m_pCore->AddQuery("INSERT INTO kanjitools.material (`title`,`mat_type`) VALUES(\"test no 2\",2);");


}
void KanjiToolsWindow::users_loaded(void * obj, void * arg)
{
    emit ((KanjiToolsWindow*)obj)->users_loaded_signal(arg);
}
void KanjiToolsWindow::materials_loaded(void * obj, void * arg)
{
    emit ((KanjiToolsWindow*)obj)->materials_loaded_signal(arg);
}
void KanjiToolsWindow::kanji_loaded(void * obj, void * arg)
{
    emit ((KanjiToolsWindow*)obj)->kanji_loaded_signal(arg);
}
void KanjiToolsWindow::users_loaded_slot(void * a)
{
    ui->listWidget->clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    while (res->next())
    {
        //std::cout << "\t... MySQL replies: ";
        // Access column data by alias or column name
        //std::cout << res->getString("_message") << std::endl;
        QListWidgetItem * it = new QListWidgetItem();
        it->setData(1,res->getString(1).c_str());
        it->setText((res->getString(2)+" "+res->getString(3)).c_str());
        ui->listWidget->addItem(it);
    }
    delete res;
}

void KanjiToolsWindow::courses_loaded(void * obj, void * arg)
{
    emit ((KanjiToolsWindow*)obj)->courses_loaded_signal(arg);
}
void KanjiToolsWindow::cadets_loaded(void * obj, void * arg)
{
    emit ((KanjiToolsWindow*)obj)->cadets_loaded_signal(arg);
}
void KanjiToolsWindow::courses_loaded_slot(void * a)
{
    ui->comboBox->clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    while (res->next())
    {
        ui->comboBox->addItem(res->getString(1).c_str());
    }
    delete res;
}

void KanjiToolsWindow::cadets_loaded_slot(void * a)
{
    ui->comboBox_3->clear();
    m_lCadetsIds.clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    while (res->next())
    {
        m_lCadetsIds.push_back(res->getInt(1));
        ui->comboBox_3->addItem((res->getString(2)+" "+res->getString(3)).c_str());
    }
    delete res;
}
void KanjiToolsWindow::materials_loaded_slot(void * a)
{
    ui->comboBox_2->clear();
    ui->comboBox_4->clear();
    m_lTestsIds.clear();
    m_lGroupsIds.clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    while (res->next())
    {
        if(res->getInt(3)==1)
        {
            m_lGroupsIds.push_back(res->getInt(1));
            ui->comboBox_2->addItem(res->getString(2).c_str());
        }
        else
        {
            m_lTestsIds.push_back(res->getInt(1));
            ui->comboBox_4->addItem(res->getString(2).c_str());
        }
    }
    delete res;
}
void KanjiToolsWindow::kanji_loaded_slot(void * a)
{
    ui->listWidget_2->clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    while (res->next())
    {
        ui->listWidget_2->addItem(res->getString(2).c_str());
    }
    delete res;
}

void KanjiToolsWindow::on_tabWidget_currentChanged(QWidget *arg1)
{
    if(arg1 == ui->tab_3)//users
    {
        ReloadUsers();
    }
    if(arg1 == ui->tab_2)//teacher
    {
        ReloadCourses();
        ReloadCadets();
        ReloadMaterials();
        /// todo: reload kanji
    }
}

void KanjiToolsWindow::on_pushButton_3_clicked()
{
    if(ui->listWidget->selectedItems().count()>0)
    {
        m_pCore->AddQuery("DELETE FROM kanjitools.person WHERE person_id = " +ui->listWidget->selectedItems()[0]->data(1).toString().toStdString()+";");
        ReloadUsers();
    }
}
void KanjiToolsWindow::ReloadUsers()
{
    m_pCore->AddQuery("SELECT * FROM kanjitools.person;",users_loaded,this);
}
void KanjiToolsWindow::ReloadCourses()
{
    m_pCore->AddQuery("SELECT * FROM kanjitools.course;",courses_loaded,this);
}
void KanjiToolsWindow::ReloadCadets(QString course)
{
    m_pCore->AddQuery("SELECT * FROM kanjitools.person WHERE account_type = 2;",cadets_loaded,this);
}
void KanjiToolsWindow::ReloadMaterials()
{
    m_pCore->AddQuery("SELECT * FROM kanjitools.material;",materials_loaded,this);
}

void KanjiToolsWindow::ReloadKanji()
{
    m_pCore->AddQuery("SELECT * FROM kanjitools.kanji;",kanji_loaded,this);
}

void KanjiToolsWindow::on_pushButton_5_clicked()
{
    if(ui->comboBox->currentText().length()==0)
        return;
    m_pCore->AddQuery("INSERT INTO kanjitools.course (`Name`) VALUES(\""+ui->comboBox->currentText().toStdString()+"\");");
    ReloadCourses();
}

void KanjiToolsWindow::on_pushButton_6_clicked()
{
    if(ui->comboBox->currentIndex()>=0)
    {
        m_pCore->AddQuery("DELETE FROM kanjitools.course WHERE Name=\'" +ui->comboBox->currentText().toStdString()+"\';");
        ReloadCourses();
    }
}

void KanjiToolsWindow::on_pushButton_10_clicked()
{
    if(ui->comboBox->currentIndex()>=0 && ui->comboBox_3->currentText()>=0)
    {
        m_pCore->AddQuery("INSERT INTO kanjitools.cadet_in_course (`course_name`,`Person_ID`) VALUES(\"" +
                          ui->comboBox->currentText().toStdString()+"\","+
                          QString::number(m_lCadetsIds[ui->comboBox_3->currentIndex()]).toStdString()+");");
        ReloadCadets();
    }
}

void KanjiToolsWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ReloadCadets(arg1);
}

void KanjiToolsWindow::on_pushButton_7_clicked()
{
    if(ui->comboBox_2->currentText().length()==0)
        return;
    m_pCore->AddQuery("INSERT INTO kanjitools.material (`title`,`mat_type`) VALUES(\""+ui->comboBox_2->currentText().toStdString()+"\",1);");
    ReloadMaterials();
}

void KanjiToolsWindow::on_pushButton_8_clicked()
{
    if(ui->comboBox_2->currentIndex()>=0)
    {
        m_pCore->AddQuery("DELETE FROM kanjitools.material WHERE title=\'" +ui->comboBox_2->currentText().toStdString()+"\';");
        /// TODO: add check for mat_type
        ReloadMaterials();
    }
}

void KanjiToolsWindow::on_pushButton_9_clicked()
{

}

void KanjiToolsWindow::on_pushButton_11_clicked()
{
    if(ui->comboBox_2->currentIndex()>=0 && ui->comboBox_3->currentIndex()>=0)
    {
        m_pCore->AddQuery("INSERT INTO kanjitools.accessibility (`Person_ID`,`Material_ID`) VALUES(" +
                          QString::number(m_lCadetsIds[ui->comboBox_3->currentIndex()]).toStdString()+","+
                          QString::number(m_lGroupsIds[ui->comboBox_2->currentIndex()]).toStdString()+");");
        ReloadMaterials();
    }
}

void KanjiToolsWindow::on_pushButton_12_clicked()
{
    if(ui->comboBox_4->currentText().length()==0)
        return;
    m_pCore->AddQuery("INSERT INTO kanjitools.material (`title`,`mat_type`) VALUES(\""+ui->comboBox_4->currentText().toStdString()+"\",2);");
    ReloadMaterials();
}

void KanjiToolsWindow::on_pushButton_13_clicked()
{
    if(ui->comboBox_4->currentIndex()>=0)
    {
        m_pCore->AddQuery("DELETE FROM kanjitools.material WHERE title=\'" +ui->comboBox_4->currentText().toStdString()+"\';");
        /// TODO: add check for mat_type
        ReloadMaterials();
    }
}

void KanjiToolsWindow::on_pushButton_15_clicked()
{
    if(ui->comboBox_3->currentIndex()>=0 && ui->comboBox_4->currentIndex()>=0)
    {
        m_pCore->AddQuery("INSERT INTO kanjitools.accessibility (`Person_ID`,`Material_ID`) VALUES(" +
                          QString::number(m_lCadetsIds[ui->comboBox_3->currentIndex()]).toStdString()+","+
                          QString::number(m_lTestsIds[ui->comboBox_4->currentIndex()]).toStdString()+");");
        ReloadMaterials();
    }
}

void KanjiToolsWindow::on_pushButton_16_clicked()
{
    KanjiDialog kd;
    kd.SetCore(m_pCore);
    kd.show();
    kd.exec();
}

void KanjiToolsWindow::on_pushButton_18_clicked()
{
    if(ui->listWidget_2->selectedItems().count()==0)
        return;
    KanjiDialog kd;
    kd.SetCore(m_pCore);
    kd.SetKanji(ui->listWidget_2->selectedItems()[0]->text());
    kd.show();
    kd.exec();
}
