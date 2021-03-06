#include "kanjitoolswindow.h"
#include "ui_kanjitoolswindow.h"
#include "logindialog.h"
#include "core.h"
#include <QDebug>
#include "connector_wraper.h"
#include "kanjidialog.h"
#include "userdialog.h"
#include "kanji_module.h"
#include "kanjitesthandler.h"
#include "kanjiencorehandler.h"
#include <sstream>
#include "d301.h"
#include "d302.h"
#include "d303.h"
#include "d304.h"
#include "d305.h"

KanjiToolsWindow::KanjiToolsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KanjiToolsWindow)
{
    ui->setupUi(this);

    m_pCore = new Core();
    m_pKanjiModule = m_pCore->GetKanjiModule();

    connect(this,SIGNAL(users_loaded_signal(void*)),this,SLOT(users_loaded_slot(void*)));
    connect(this,SIGNAL(courses_loaded_signal(void*)),this,SLOT(courses_loaded_slot(void*)));
    connect(this,SIGNAL(cadets_loaded_signal(void*)),this,SLOT(cadets_loaded_slot(void*)));
    connect(this,SIGNAL(materials_loaded_signal(void*)),this,SLOT(materials_loaded_slot(void*)));
    connect(this,SIGNAL(kanji_loaded_signal(void*)),this,SLOT(kanji_loaded_slot(void*)));
    connect(this,SIGNAL(authentication_signal(void*)),this,SLOT(authentication_slot(void*)));
    connect(this,SIGNAL(ShowLoginDialogSignal()),this,SLOT(ShowLoginDialog()));


    m_pLoginDialog = new LoginDialog(this);
    m_pLoginDialog->SetCore(m_pCore);
    m_pUserDialog = new UserDialog(this);
    m_pUserDialog->SetCore(m_pCore);
    ui->tabWidget->hide();
    //m_pLoginDialog->setAttribute(Qt::WA_QuitOnClose);

    //initialize test handler
    m_pKanjiTestHandler = new KanjiTestHandler(this);
    m_pKanjiTestHandler->Init(m_pCore);

    m_pKanjiEncoreHandler = new KanjiEncoreHandler(this);
    m_pKanjiEncoreHandler->Init(m_pCore);
    emit ShowLoginDialogSignal();
    
}

KanjiToolsWindow::~KanjiToolsWindow()
{
    delete ui;
    delete m_pCore;
}

Core * KanjiToolsWindow::getCore()
{
    return m_pCore;
}

UserDialog * KanjiToolsWindow::getUserDialog()
{
    return m_pUserDialog;
}

void KanjiToolsWindow::HideUnusedTabs()
{
    qDebug() <<"account type is "<<m_pCore->GetUser().account_type;
    switch(m_pCore->GetUser().account_type)
    {
    case ACCOUNT_TYPE_ERROR:
        ui->tabWidget->removeTab(1);
        ui->tabWidget->removeTab(0);
        break;
    case ACCOUNT_TYPE_TEACHER:
        ui->tabWidget->removeTab(3);
        break;
    case ACCOUNT_TYPE_STUDENT:
        ui->tabWidget->removeTab(2);// teacher
        ui->tabWidget->removeTab(1);//users
        ui->tabWidget->removeTab(0);//admin
        break;
    }
}

void KanjiToolsWindow::on_pushButton_clicked()
{
    m_pCore->AddQuery("drop schema `kanjitools`;");
    m_pCore->AddQuery("CREATE SCHEMA `kanjitools` DEFAULT CHARACTER SET ujis COLLATE ujis_japanese_ci ;");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`person` (     `Person_ID` INT NOT NULL AUTO_INCREMENT , `Login` TINYTEXT NOT NULL ,`Password` TINYTEXT NOT NULL ,  `Name` TINYTEXT NOT NULL ,    `Surename` TINYTEXT NOT NULL , `account_type` INT,   PRIMARY KEY (`Person_ID`) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`course` ( `Name` TINYTEXT NOT NULL , `Tutor_ID` INT,   PRIMARY KEY (`Name`(10)) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`cadet_in_course` ( `Person_ID` INT NOT NULL , `course_name` TINYTEXT NOT NULL,  PRIMARY KEY (`Person_ID`,`course_name`(10)) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`material` ( `Material_ID` INT NOT NULL AUTO_INCREMENT , `title` TINYTEXT NOT NULL, `mat_type` INT,  PRIMARY KEY (`Material_ID`) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`accessibility` ( `Person_ID` INT NOT NULL , `Material_ID` INT NOT NULL, PRIMARY KEY (`Person_ID`,`Material_ID`) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`kanji` ( `kanji` CHAR NOT NULL , `on_youmi` TINYTEXT,`kun_youmi` TINYTEXT, `translations` TEXT,`examples` TINYTEXT,PRIMARY KEY (`kanji`) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`kanjiinmaterial` ( `kanji` CHAR NOT NULL , `Material_ID` INT NOT NULL,PRIMARY KEY (`kanji`,`Material_ID`) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`testresults` ( `Result_ID` int NOT NULL AUTO_INCREMENT, `Material_ID` INT NOT NULL, `Test_type` TINYTEXT NOT NULL, `Person_ID` INT NOT NULL, PRIMARY KEY (`Result_ID`) );");
    m_pCore->AddQuery("CREATE  TABLE `kanjitools`.`kanjiinresult` ( `kanji` CHAR NOT NULL , `Result_ID` INT NOT NULL,PRIMARY KEY (`kanji`,`Result_ID`) );");

    m_pCore->AddQuery("ALTER TABLE `kanjitools`.`kanjiinresult` ADD INDEX `fk_kanjiinresult_1_idx` (`Result_ID` ASC);");
    m_pCore->AddQuery("ALTER TABLE `kanjitools`.`kanjiinresult` ADD CONSTRAINT `fk_kanjiinresult_1` FOREIGN KEY (`Result_ID`) REFERENCES `kanjitools`.`testresults` (`Result_ID`) ON DELETE CASCADE ON UPDATE CASCADE;");

    m_pCore->AddQuery("INSERT INTO kanjitools.person (`Login`,`Password`,`Name`,`Surename`,`account_type`) VALUES(\"divinitas\",\"1234\",\"Carina\",\"Tsvetkova\",3);");
    m_pCore->AddQuery("INSERT INTO kanjitools.person (`Login`,`Password`,`Name`,`Surename`,`account_type`) VALUES(\"andeyeff\",\"1234\",\"Sergej\",\"Andreyev\",3);");
    m_pCore->AddQuery("INSERT INTO kanjitools.person (`Login`,`Password`,`Name`,`Surename`,`account_type`) VALUES(\"mihaly4\",\"1234\",\"Sergej\",\"Comov\",3);");
    m_pCore->AddQuery("INSERT INTO kanjitools.course (`Name`) VALUES(\"4202mv\");");
    m_pCore->AddQuery("INSERT INTO kanjitools.course (`Name`) VALUES(\"4201mv\");");
    m_pCore->AddQuery("INSERT INTO kanjitools.cadet_in_course (`Person_ID`,`course_name`) VALUES(2,\"4201mv\");");
    m_pCore->AddQuery("INSERT INTO kanjitools.cadet_in_course (`Person_ID`,`course_name`) VALUES(3,\"4201mv\");");

    d3xx * data[5];
    data[0] = new d301();
    data[1] = new d302();
    data[2] = new d303();
    data[3] = new d304();
    data[4] = new d305();
    
    for(int g =0; g < 5; g++)
    {
	d3xx * p1 = data[g];
	m_pCore->AddQuery("INSERT INTO kanjitools.material (`title`,`mat_type`) VALUES(\""+p1->GetGroupName()+"\",1);");
	m_pCore->AddQuery("INSERT INTO kanjitools.material (`title`,`mat_type`) VALUES(\"Test: "+p1->GetGroupName()+"\",2);");
	for(int i=0;i<60;i++)
	{
	    std::string * kanji_info = p1->ksdb[i];
	    
	    m_pCore->AddQuery("INSERT INTO kanjitools.kanji ( `kanji`,`on_youmi`,`kun_youmi`,`translations`,`examples`) \
	    VALUES(\
	    \""+p1->GetKanji(i)+"\",\
	    \""+p1->GetOn(i)+"\",\
	    \""+p1->GetKun(i)+"\",\
	    \""+p1->GetMeaning(i)+"\",\
	    \""+p1->GetExamples(i)+"\");");
	    std::ostringstream s;
	    s << g*2+1;
	    std::ostringstream s2;
	    s2 << g*2+2;

	    m_pCore->AddQuery("INSERT INTO kanjitools.kanjiinmaterial (`kanji`,`Material_ID`) VALUES(\""+p1->GetKanji(i)+"\","+s.str()+");");
	    m_pCore->AddQuery("INSERT INTO kanjitools.kanjiinmaterial (`kanji`,`Material_ID`) VALUES(\""+p1->GetKanji(i)+"\","+s2.str()+");");
	}
    }
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
        qDebug() << "\t... MySQL replies: ";
        // Access column data by alias or column name
        //std::cout << res->getString("_message") << std::endl;
        QListWidgetItem * it = new QListWidgetItem();
        it->setData(1,res->getString(1).c_str());
        it->setText((res->getString(4)+" "+res->getString(5)).c_str());
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
        ui->comboBox_3->addItem((res->getString(4)+" "+res->getString(5)).c_str());
    }
    delete res;
}
void KanjiToolsWindow::materials_loaded_slot(void * a)
{
    ui->comboBox_2->clear();
    ui->comboBox_4->clear();
    ui->comboBox_9->clear();
    ui->comboBox_5->clear();
    ui->comboBox_6->clear();
    ui->label_5->setText("");
    m_lTestsIds.clear();
    m_lGroupsIds.clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    while (res->next())
    {
        if(res->getInt(3)==1)
        {
            m_lGroupsIds.push_back(res->getInt(1));
            ui->comboBox_2->addItem(res->getString(2).c_str());
            ui->comboBox_9->addItem(res->getString(2).c_str());
        }
        else
        {
            m_lTestsIds.push_back(res->getInt(1));
            ui->comboBox_4->addItem(res->getString(2).c_str());
            ui->comboBox_5->addItem(res->getString(2).c_str());
        }
    }
    ui->comboBox_9->setCurrentIndex(-1);
    ui->comboBox_5->setCurrentIndex(-1);
    delete res;
}
void KanjiToolsWindow::kanji_loaded_slot(void * a)
{
    ui->listWidget_2->clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    while (res->next())
    {
        ui->listWidget_2->addItem(res->getString(1).c_str());
    }
    delete res;
}

void KanjiToolsWindow::on_tabWidget_currentChanged(QWidget *arg1)
{
    if(arg1 == ui->tab) // settings
    {
        ReloadSettings();
    }
    if(arg1 == ui->tab_3)//users
    {
        ReloadUsers();
    }
    if(arg1 == ui->tab_2)//teacher
    {
        ReloadCourses();
        ReloadCadets();
        ReloadMaterials();
        ReloadKanji();
    }
    if(arg1 == ui->tab_7)//review
    {
        ReloadMaterials();
    }
    if(arg1 == ui->tab_4)//all-test
    {
        m_pKanjiTestHandler->ReloadTestResults();
        ReloadMaterials();
    }
    if(arg1 == ui->tab_5)
    {
        m_pKanjiEncoreHandler->ReloadEncore();
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
    m_pCore->AddQuery("SELECT * FROM kanjitools.person WHERE account_type = 3;",cadets_loaded,this);
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
    kd.SetCore(m_pCore,m_pKanjiModule);
    kd.show();
    kd.exec();
    ReloadKanji();
}

void KanjiToolsWindow::on_pushButton_17_clicked()
{
    //delete selected kanji
    if(ui->listWidget_2->selectedItems().count()==0)
        return;
    for(int i=0;i<ui->listWidget_2->selectedItems().count();i++)
    {
        m_pCore->AddQuery("DELETE FROM kanjitools.kanji WHERE `kanji` = \""+
                          ui->listWidget_2->selectedItems()[i]->text().toStdString()+"\";");
    }
    ReloadKanji();
}

void KanjiToolsWindow::on_pushButton_18_clicked()
{
    if(ui->listWidget_2->selectedItems().count()==0)
        return;
    KanjiDialog kd;
    kd.SetCore(m_pCore,m_pKanjiModule);
    kd.SetKanji(ui->listWidget_2->selectedItems()[0]->text());
    kd.show();
    kd.exec();
    if(kd.result() == QDialog::Accepted)ReloadKanji();
}

void KanjiToolsWindow::on_pushButton_19_clicked()
{
    if(ui->listWidget_2->selectedItems().count()==0 || ui->comboBox_2->currentIndex()<0)
        return;
    for(int i=0;i<ui->listWidget_2->selectedItems().count();i++)
    {
        m_pCore->AddQuery("INSERT INTO kanjitools.kanjiinmaterial (`kanji`,`Material_ID`) VALUES(\""+
                          ui->listWidget_2->selectedItems()[i]->text().toStdString()+"\","+
                          QString::number(m_lGroupsIds[ui->comboBox_2->currentIndex()]).toStdString()+");");
    }
}

void KanjiToolsWindow::on_pushButton_20_clicked()
{
    if(ui->listWidget_2->selectedItems().count()==0 || ui->comboBox_4->currentIndex()<0)
        return;
    for(int i=0;i<ui->listWidget_2->selectedItems().count();i++)
    {
        m_pCore->AddQuery("INSERT INTO kanjitools.kanjiinmaterial (`kanji`,`Material_ID`) VALUES(\""+
                          ui->listWidget_2->selectedItems()[i]->text().toStdString()+"\","+
                          QString::number(m_lTestsIds[ui->comboBox_4->currentIndex()]).toStdString()+");");
    }
}

void KanjiToolsWindow::on_pushButton_21_clicked()
{
    if(ui->listWidget_2->selectedItems().count()==0 || ui->comboBox_4->currentIndex()<0)
        return;
    for(int i=0;i<ui->listWidget_2->selectedItems().count();i++)
    {
        m_pCore->AddQuery("DELETE FROM kanjitools.kanjiinmaterial WHERE `kanji` = \""+
                          ui->listWidget_2->selectedItems()[i]->text().toStdString()+"\" AND `Material_ID` = "+
                          QString::number(m_lTestsIds[ui->comboBox_4->currentIndex()]).toStdString()+";");
    }
}

void KanjiToolsWindow::on_pushButton_22_clicked()
{
    if(ui->listWidget_2->selectedItems().count()==0 || ui->comboBox_2->currentIndex()<0)
        return;
    for(int i=0;i<ui->listWidget_2->selectedItems().count();i++)
    {
        m_pCore->AddQuery("DELETE FROM kanjitools.kanjiinmaterial WHERE `kanji` = \""+
                          ui->listWidget_2->selectedItems()[i]->text().toStdString()+"\" AND `Material_ID` = "+
                          QString::number(m_lGroupsIds[ui->comboBox_2->currentIndex()]).toStdString()+";");
    }
}

void KanjiToolsWindow::on_comboBox_9_activated(const QString &arg1)
{
    if(ui->comboBox_9->currentIndex()<0)
        return;
    m_pKanjiModule->LoadMaterial(m_lGroupsIds[ui->comboBox_9->currentIndex()]);
    ui->label_9->setText("");
    ui->label_10->setText("");
    ui->label_11->setText("");
    ui->label_12->setText("");
    ui->label_13->setText("");
}

void KanjiToolsWindow::on_pushButton_46_clicked()
{
    kanji_t k = m_pKanjiModule->NextKanji();
    ui->label_9->setText(k.kanji.c_str());
    ui->label_10->setText(k.on_youmi.c_str());
    ui->label_11->setText(k.kun_youmi.c_str());
    ui->label_12->setText(k.meaning.c_str());
    ui->label_13->setText(k.examples.c_str());
}

void KanjiToolsWindow::on_pushButton_45_clicked()
{
    kanji_t k = m_pKanjiModule->PreviousKanji();
    ui->label_9->setText(k.kanji.c_str());
    ui->label_10->setText(k.on_youmi.c_str());
    ui->label_11->setText(k.kun_youmi.c_str());
    ui->label_12->setText(k.meaning.c_str());
    ui->label_13->setText(k.examples.c_str());
}

void KanjiToolsWindow::on_pushButton_2_clicked()
{
    m_pUserDialog->SetUser("-1");
    m_pUserDialog->show();
}

void KanjiToolsWindow::on_pushButton_4_clicked()
{
    if(ui->listWidget->selectedItems().count()==0)
        return;
    m_pUserDialog->SetUser(ui->listWidget->selectedItems()[0]->data(1).toString().toStdString());
    m_pUserDialog->show();
}

void KanjiToolsWindow::authentication(void *obj, void *arg)
{
    emit ((KanjiToolsWindow*)obj)->authentication_signal(arg);
}

void KanjiToolsWindow::authentication_slot(void *a)
{
    user_t u;
    if(a==NULL)
    {
        u.account_type = ACCOUNT_TYPE_ADMIN;
        u.name = "Admin";
        u.surename = "Adminovich";
    }
    else
    {
        sql::ResultSet *res=(sql::ResultSet *)a;
        while (res->next())
        {
            u.id = res->getString(1);
            u.login = res->getString(2);
            u.password = res->getString(3);
            u.name = res->getString(4);
            u.surename = res->getString(5);
            u.account_type = res->getString(6)[0]-'0';
        }
        if(res->rowsCount()==0)
        {
            u.name="bad boy";
            emit ShowLoginDialogSignal();
            delete res;
            return;
        }
        delete res;
    }


    m_pCore->SetUser(u);
    HideUnusedTabs();
    setWindowTitle(QString::fromStdString(u.name+" "+u.surename));
    ui->tabWidget->show();
    show();
    on_tabWidget_currentChanged(ui->tabWidget->currentWidget());
}

void KanjiToolsWindow::ShowLoginDialog()
{
    //LoginDialog ldg;
    //m_pLoginDialog->show();
    m_pLoginDialog->exec();
    /*m_pLoginDialog->exec();
    if(m_pLoginDialog->result() == QDialog::Rejected)
    {
        close();
        exit(0);
        return;
    }
    m_pCore->Authenticate(m_pLoginDialog->GetLoginName().toStdString(),
                          m_pLoginDialog->GetPassword().toStdString(),authentication,this);*/
}


int KanjiToolsWindow::GetSelectedTestId()
{
    return m_lTestsIds[ui->comboBox_5->currentIndex()];
}


void KanjiToolsWindow::ReloadSettings()
{
    db_settings_t sets = m_pCore->GetDBSettings();
    ui->lineEdit->setText(QString::fromStdString(sets.host));
    ui->lineEdit_2->setText(QString::fromStdString(sets.user));
    ui->lineEdit_3->setText(QString::fromStdString(sets.password));
    ui->lineEdit_4->setText(QString::fromStdString(sets.dbname));
}




