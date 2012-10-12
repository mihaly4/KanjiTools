#include "kanjidialog.h"
#include "ui_kanjidialog.h"
#include "core.h"

KanjiDialog::KanjiDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KanjiDialog)
{
    ui->setupUi(this);
    kanji="";
    m_pCore = NULL;
}

KanjiDialog::~KanjiDialog()
{
    delete ui;
}

void KanjiDialog::SetKanji(QString kanji)
{
    this->kanji = kanji;
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
