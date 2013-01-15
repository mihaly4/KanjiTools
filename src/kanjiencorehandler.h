#ifndef KANJIENCOREHANDLER_H
#define KANJIENCOREHANDLER_H

#include <QObject>
#include "common.h"
class Core;
class KanjiModule;
class KanjiToolsWindow;

class KanjiEncoreHandler : public QObject
{
    Q_OBJECT
public:
    explicit KanjiEncoreHandler(QObject *parent = 0);
    void Init(Core * core);
    void ReloadEncore();
signals:

    void encore_loaded_signal(void * a);
    
public slots:



     void on_comboBox_10_currentIndexChanged(int index);

     void on_pushButton_48_clicked();

     void on_pushButton_47_clicked();

private slots:
     void encore_loaded_slot(void * a);

private:
     Core *             m_pCore;
     KanjiToolsWindow * m_pKanjiToolsWindow;
     KanjiModule *      m_pKanjiModule;
     QList<encore_t> m_lEncore;


     static void encore_loaded(void * obj, void * arg);


};

#endif // KANJIENCOREHANDLER_H
