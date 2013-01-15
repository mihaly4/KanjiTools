#ifndef KANJITESTHANDLER_H
#define KANJITESTHANDLER_H

#include <QObject>
#include "common.h"
class KanjiToolsWindow;
class BaseTest;
class KanjiModule;
class Core;

class KanjiTestHandler : public QObject
{
    Q_OBJECT
public:
    explicit KanjiTestHandler(QObject *parent = 0);
    void Init(Core *core);
    void ReloadTestResults();
    
signals:
    void test_loaded_signal();
     void test_results_loaded_signal(void * a);
    
public slots:
    void on_pushButton_27_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_comboBox_5_activated(int index);

    void test_loaded_slot();
    void test_results_loaded_slot(void *a);
private:
    KanjiToolsWindow *      m_pKTW;
    BaseTest *              m_pTest;
    KanjiModule *           m_pKanjiModule;
    Core *                  m_pCore;
    QList<test_result_t>    m_lResults;

    void NextCase();
    static void test_loaded(void * obj);
    static void test_results_loaded(void * obj, void * arg);


    
};

#endif // KANJITESTHANDLER_H
