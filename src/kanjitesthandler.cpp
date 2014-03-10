#include "kanjitesthandler.h"
#include "kanjitoolswindow.h"
#include "ui_kanjitoolswindow.h"

#include "core.h"
#include "basetest.h"
#include "onyoumitest1.h"
#include "onyoumitest2.h"
#include "kunyoumitest1.h"
#include "kunyoumitest2.h"
#include "meaningtest1.h"
#include "meaningtest2.h"
#include "kanji_module.h"
#include "connector_wraper.h"

KanjiTestHandler::KanjiTestHandler(QObject *parent) :
    QObject(parent)
{
    m_pKTW = (KanjiToolsWindow*)parent;
    connect(this,SIGNAL(test_loaded_signal()),this,SLOT(test_loaded_slot()));
    connect(this,SIGNAL(test_results_loaded_signal(void*)),this,SLOT(test_results_loaded_slot(void*)));
    connect(m_pKTW->GetUI()->pushButton_23,SIGNAL(clicked()),this,SLOT(on_pushButton_23_clicked()));
    connect(m_pKTW->GetUI()->pushButton_24,SIGNAL(clicked()),this,SLOT(on_pushButton_24_clicked()));
    connect(m_pKTW->GetUI()->pushButton_25,SIGNAL(clicked()),this,SLOT(on_pushButton_25_clicked()));
    connect(m_pKTW->GetUI()->pushButton_26,SIGNAL(clicked()),this,SLOT(on_pushButton_26_clicked()));
    connect(m_pKTW->GetUI()->pushButton_27,SIGNAL(clicked()),this,SLOT(on_pushButton_27_clicked()));
    connect(m_pKTW->GetUI()->comboBox_5,SIGNAL(activated(int)),this,SLOT(on_comboBox_5_activated(int)));

}

void KanjiTestHandler::Init(Core * core)
{
    m_pCore = core;
    m_pTest = NULL;
    m_pKanjiModule = core->GetKanjiModule();
}


void KanjiTestHandler::on_pushButton_27_clicked()
{
    if(m_pKTW->GetUI()->comboBox_5->currentIndex()<0 || m_pKTW->GetUI()->comboBox_6->currentIndex()<0)
        return;
    /*m_pCore->CreateTest(ui->comboBox_6->currentText().toStdString(),
                        m_lTestsIds[ui->comboBox_5->currentIndex()],test_loaded,this);*/

    std::string test = m_pKTW->GetUI()->comboBox_6->currentText().toStdString();
    int mat_id = m_pKTW->GetSelectedTestId();

    if(test=="on-youmi-1")
    {
        m_pTest = new OnYoumiTest1();
    }
    else if(test=="on-youmi-2")
    {
        m_pTest = new OnYoumiTest2();
    }
    else if(test=="kun-youmi-1")
    {
        m_pTest = new KunYoumiTest1();
    }
    else if(test=="kun-youmi-2")
    {
        m_pTest = new KunYoumiTest2();
    }
    else if(test=="meaning-1")
    {
        m_pTest = new MeaningTest1();
    }
    else if(test=="meaning-2")
    {
        m_pTest = new MeaningTest2();
    }
    m_pTest->Init(m_pCore,mat_id);
    m_pTest->SetKanjiModule(m_pKanjiModule);

    m_pKanjiModule->LoadMaterial(mat_id,test_loaded,this);

    QFont font = m_pKTW->GetUI()->pushButton_23->font();
    font.setPointSize(m_pTest->GetTestVarFontSize());
    m_pKTW->GetUI()->pushButton_23->setFont(font);
    m_pKTW->GetUI()->pushButton_24->setFont(font);
    m_pKTW->GetUI()->pushButton_25->setFont(font);
    m_pKTW->GetUI()->pushButton_26->setFont(font);

    QFont font2 = m_pKTW->GetUI()->label_5->font();
    font2.setPointSize(m_pTest->GetTestQueFontSize());
    m_pKTW->GetUI()->label_5->setFont(font2);

}

void KanjiTestHandler::test_loaded(void *obj)
{
    emit ((KanjiTestHandler*)obj)->test_loaded_signal();
}

void KanjiTestHandler::test_loaded_slot()
{
    NextCase();
}


void KanjiTestHandler::NextCase()
{
    case_t c = m_pTest->NextCase();
    m_pKTW->GetUI()->pushButton_23->setText(QString::fromStdString(c.variants[0]));
    m_pKTW->GetUI()->pushButton_24->setText(QString::fromStdString(c.variants[1]));
    m_pKTW->GetUI()->pushButton_25->setText(QString::fromStdString(c.variants[2]));
    m_pKTW->GetUI()->pushButton_26->setText(QString::fromStdString(c.variants[3]));
    m_pKTW->GetUI()->label_5->setText(QString::fromStdString(c.question));

    if( m_pKTW->GetUI()->pushButton_23->text().length()==0)
    {
        QFont font2 = m_pKTW->GetUI()->label_5->font();
        font2.setPointSize(10);
        m_pKTW->GetUI()->label_5->setFont(font2);
        ReloadTestResults();
        m_pKTW->ReloadMaterials();
    }
    m_pKTW->GetUI()->label_35->setText(QString::fromStdString("Correct:"+m_pTest->GetCorrectAnswer()+"  "+m_pTest->GetStatus()));
}

void KanjiTestHandler::on_pushButton_23_clicked()
{
    m_pTest->Answer(0);
    NextCase();
}

void KanjiTestHandler::on_pushButton_24_clicked()
{
    m_pTest->Answer(1);
    NextCase();
}

void KanjiTestHandler::on_pushButton_25_clicked()
{
    m_pTest->Answer(2);
    NextCase();
}

void KanjiTestHandler::on_pushButton_26_clicked()
{
    m_pTest->Answer(3);
    NextCase();
}


void KanjiTestHandler::ReloadTestResults()
{
    m_pCore->AddQuery("SELECT * FROM kanjitools.testresults LEFT JOIN kanjitools.material ON (kanjitools.testresults.Material_ID=kanjitools.material.Material_ID) WHERE `Person_ID` = "+m_pCore->GetUser().id+";",
                      test_results_loaded,this);
}

void KanjiTestHandler::test_results_loaded(void *obj, void *arg)
{
    emit ((KanjiTestHandler*)obj)->test_results_loaded_signal(arg);
}

void KanjiTestHandler::test_results_loaded_slot(void *a)
{
    m_lResults.clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    int fail_index=0;
    while (res->next())
    {
        test_result_t r;
        r.id = res->getString(1);
        r.test_id = res->getString(2);
        r.test_type = res->getString(3);
        r.person_id = res->getString(4);
        m_lResults.push_back(r);
    }
    delete res;
}

void KanjiTestHandler::on_comboBox_5_activated(int index)
{
    m_pKTW->GetUI()->comboBox_6->clear();
    QString types[]={"on-youmi-1","on-youmi-2","kun-youmi-1","kun-youmi-2","meaning-1","meaning-2"};
    for(int i=0;i<6;i++)
    {
        bool f = false;
        for(int j=0;j<m_lResults.count();j++)
        {
            if(m_lResults[j].test_id == QString::number(m_pKTW->GetSelectedTestId()).toStdString() && m_lResults[j].test_type == types[i].toStdString())
            {
                f = true;
                break;
            }
        }
        if(!f)
            m_pKTW->GetUI()->comboBox_6->addItem(types[i]);
    }
}
