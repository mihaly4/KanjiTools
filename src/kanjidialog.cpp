#include "kanjidialog.h"
#include "ui_kanjidialog.h"
#include "core.h"
#include <cppconn/resultset.h>

KanjiDialog::KanjiDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KanjiDialog)
{
    ui->setupUi(this);
    kanji="";
    m_pCore = NULL;
    connect(this,SIGNAL(LoadKanji(void*)),this,SLOT(LoadKanjiSlot(void*)));
}

KanjiDialog::~KanjiDialog()
{
    delete ui;
}

void KanjiDialog::SetKanji(QString kanji)
{
    this->kanji = kanji;
    m_pCore->AddQuery("SELECT * from kanjitools.kanji WHERE `kanji` = \""+kanji.toStdString()+"\";",kanji_loaded,this);
}

void KanjiDialog::on_buttonBox_accepted()
{
    if(kanji.length()>0)
    {

    }
    else
    {
        m_pCore->AddKanji(ui->lineEdit->text().toStdString(),
                          ui->lineEdit_2->text().toStdString(),
                          ui->lineEdit_3->text().toStdString(),
                          ui->plainTextEdit->toPlainText().toStdString(),
                          ui->plainTextEdit_2->toPlainText().toStdString());
    }
}

void KanjiDialog::SetCore(Core * core)
{
    m_pCore = core;
}

void KanjiDialog::kanji_loaded(void * obj, void * res)
{
    KanjiDialog * dlg = (KanjiDialog*)obj;
    emit dlg->LoadKanji(res);
}

void KanjiDialog::LoadKanjiSlot(void *a)
{
    sql::ResultSet *res=(sql::ResultSet *)a;
    while(res->next())
    {
        ui->lineEdit->setText(res->getString(1).c_str());
        ui->lineEdit_2->setText(res->getString(2).c_str());
        ui->lineEdit_3->setText(res->getString(3).c_str());
        ui->plainTextEdit->setPlainText(res->getString(4).c_str());
        ui->plainTextEdit_2->setPlainText(res->getString(5).c_str());
    }
    delete res;
}
