#ifndef KANJITOOLSWINDOW_H
#define KANJITOOLSWINDOW_H

#include <QMainWindow>
class Core;

namespace Ui {
class KanjiToolsWindow;
}

class KanjiToolsWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit KanjiToolsWindow(QWidget *parent = 0);
    ~KanjiToolsWindow();

signals:
    void users_loaded_signal(void * a);
    
private slots:
    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(QWidget *arg1);

    void users_loaded_slot(void * a);

private:
    Ui::KanjiToolsWindow *ui;
    Core * m_pCore;

    void HideUnusedTabs(int level);

    static void users_loaded(void * obj, void * arg);

};

#endif // KANJITOOLSWINDOW_H
