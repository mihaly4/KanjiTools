#ifndef KANJIDIALOG_H
#define KANJIDIALOG_H

#include <QtGui/QDialog>

class Core;
class KanjiModule;

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
    void SetCore(Core * core, KanjiModule *km);
signals:
    void LoadKanji(void * res);
    
private slots:
    void on_buttonBox_accepted();

    void LoadKanjiSlot(void * a);

private:
    Ui::KanjiDialog *ui;
    QString kanji;
    Core * m_pCore;
    KanjiModule * m_pKanjiModule;

    static void kanji_loaded(void * obj, void * res);
};

#endif // KANJIDIALOG_H
