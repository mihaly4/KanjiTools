#ifndef KANJIDIALOG_H
#define KANJIDIALOG_H

#include <QDialog>

class Core;

namespace Ui {
class KanjiDialog;
}

class KanjiDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit KanjiDialog(QWidget *parent = 0);
    ~KanjiDialog();
    void SetKanji(QString kanji);
    void SetCore(Core * core);
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::KanjiDialog *ui;
    QString kanji;
    Core * m_pCore;
};

#endif // KANJIDIALOG_H
