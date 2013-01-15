#include "kanjiencorehandler.h"
#include "core.h"
#include "kanjitoolswindow.h"
#include "ui_kanjitoolswindow.h"
#include "kanji_module.h"
#include "connector_wraper.h"

KanjiEncoreHandler::KanjiEncoreHandler(QObject *parent) :
    QObject(parent)
{
    m_pKanjiToolsWindow = (KanjiToolsWindow*)parent;
    connect(this,SIGNAL(encore_loaded_signal(void*)),this,SLOT(encore_loaded_slot(void*)));
    connect(m_pKanjiToolsWindow->GetUI()->comboBox_10,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_10_currentIndexChanged(int)));
    connect(m_pKanjiToolsWindow->GetUI()->pushButton_47,SIGNAL(clicked()),this,SLOT(on_pushButton_47_clicked()));
    connect(m_pKanjiToolsWindow->GetUI()->pushButton_48,SIGNAL(clicked()),this,SLOT(on_pushButton_48_clicked()));
}

void KanjiEncoreHandler::Init(Core *core)
{
    m_pCore = core;
    m_pKanjiModule = core->GetKanjiModule();
}



void KanjiEncoreHandler::on_comboBox_10_currentIndexChanged(int index)
{
    if(m_pKanjiToolsWindow->GetUI()->comboBox_10->currentIndex()<0)
        return;
    m_pKanjiModule->LoadKanjiFromResult(m_lEncore[m_pKanjiToolsWindow->GetUI()->comboBox_10->currentIndex()].result_id,NULL,NULL);
    m_pKanjiToolsWindow->GetUI()->label_21->setText("");
    m_pKanjiToolsWindow->GetUI()->label_24->setText("");
    m_pKanjiToolsWindow->GetUI()->label_25->setText("");
    m_pKanjiToolsWindow->GetUI()->label_28->setText("");
    m_pKanjiToolsWindow->GetUI()->label_29->setText("");
}

void KanjiEncoreHandler::on_pushButton_48_clicked()
{
    kanji_t k = m_pKanjiModule->NextKanji();
    m_pKanjiToolsWindow->GetUI()->label_21->setText(k.kanji.c_str());
    m_pKanjiToolsWindow->GetUI()->label_24->setText(k.on_youmi.c_str());
    m_pKanjiToolsWindow->GetUI()->label_25->setText(k.kun_youmi.c_str());
    m_pKanjiToolsWindow->GetUI()->label_28->setText(k.meaning.c_str());
    m_pKanjiToolsWindow->GetUI()->label_29->setText(k.examples.c_str());
}

void KanjiEncoreHandler::on_pushButton_47_clicked()
{
    kanji_t k = m_pKanjiModule->PreviousKanji();
    m_pKanjiToolsWindow->GetUI()->label_21->setText(k.kanji.c_str());
    m_pKanjiToolsWindow->GetUI()->label_24->setText(k.on_youmi.c_str());
    m_pKanjiToolsWindow->GetUI()->label_25->setText(k.kun_youmi.c_str());
    m_pKanjiToolsWindow->GetUI()->label_28->setText(k.meaning.c_str());
    m_pKanjiToolsWindow->GetUI()->label_29->setText(k.examples.c_str());
}


void KanjiEncoreHandler::ReloadEncore()
{
    m_pCore->AddQuery("SELECT `kanjitools`.`testresults`.`Result_ID`,`Test_type`,COUNT(`kanji`), `title` FROM kanjitools.kanjiinresult LEFT JOIN (kanjitools.testresults CROSS JOIN kanjitools.material)  ON (kanjitools.testresults.Material_ID=kanjitools.material.Material_ID AND kanjitools.testresults.Result_ID=kanjitools.kanjiinresult.Result_ID) WHERE `Person_ID` = "+m_pCore->GetUser().id+" GROUP BY `Result_ID`;",
                      encore_loaded,this);
}



void KanjiEncoreHandler::encore_loaded(void *obj, void *arg)
{
    emit ((KanjiEncoreHandler*)obj)->encore_loaded_signal(arg);
}



void KanjiEncoreHandler::encore_loaded_slot(void * a)
{
    m_pKanjiToolsWindow->GetUI()->comboBox_10->clear();
    m_lEncore.clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    int fail_index=0;
    while (res->next())
    {
        encore_t r;
        r.result_id = res->getString(1);
        r.test_type = res->getString(2);
        //r.test_type = res->getString(3);
        //r.person_id = res->getString(4);
        m_lEncore.push_back(r);
        m_pKanjiToolsWindow->GetUI()->comboBox_10->addItem(QString::fromStdString(res->getString(4)+": "+res->getString(2)+": "+res->getString(3)));
       // qDebug()<<QString::fromStdString(r.id)<<QString::fromStdString(r.test_type);
    }
    delete res;
}
