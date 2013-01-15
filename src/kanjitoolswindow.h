#ifndef KANJITOOLSWINDOW_H
#define KANJITOOLSWINDOW_H

#include <QtGui/QMainWindow>
#include <QList>
#include "common.h"
class Core;
class LoginDialog;
class UserDialog;
class KanjiModule;
class KanjiTestHandler;
class KanjiEncoreHandler;
namespace Ui {
class KanjiToolsWindow;
}

class KanjiToolsWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit KanjiToolsWindow(QWidget *parent = 0);
    ~KanjiToolsWindow();
    static void authentication(void * obj,void * arg);
    Core * getCore();
    UserDialog * getUserDialog();
    void ReloadUsers();
    Ui::KanjiToolsWindow * GetUI(){return ui;}

    void ReloadMaterials();

    int GetSelectedTestId();

signals:
    void users_loaded_signal(void * a);
    void courses_loaded_signal(void * a);
    void cadets_loaded_signal(void * a);
    void materials_loaded_signal(void * a);
    void kanji_loaded_signal(void * a);
    void authentication_signal(void * a);
    void ShowLoginDialogSignal();


    
private slots:
    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(QWidget *arg1);

    void users_loaded_slot(void * a);
    void courses_loaded_slot(void * a);
    void cadets_loaded_slot(void * a);
    void materials_loaded_slot(void * a);
    void kanji_loaded_slot(void * a);
    void authentication_slot(void * a);



    void ShowLoginDialog();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_comboBox_9_activated(const QString &arg1);

    void on_pushButton_46_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();




private:
    Ui::KanjiToolsWindow *ui;
    Core * m_pCore;
    QList<int> m_lCadetsIds;
    QList<int> m_lGroupsIds;
    QList<int> m_lTestsIds;
    LoginDialog *           m_pLoginDialog;
    UserDialog *            m_pUserDialog;
    KanjiModule *           m_pKanjiModule;
    KanjiTestHandler *      m_pKanjiTestHandler;
    KanjiEncoreHandler *    m_pKanjiEncoreHandler;

    void HideUnusedTabs();

    static void users_loaded(void * obj, void * arg);
    static void courses_loaded(void * obj, void * arg);
    static void cadets_loaded(void * obj, void * arg);
    static void materials_loaded(void * obj, void * arg);
    static void kanji_loaded(void * obj, void * arg);






    void ReloadCourses();
    void ReloadCadets(QString course ="");

    void ReloadKanji();

    void ReloadSettings();






};

#endif // KANJITOOLSWINDOW_H
