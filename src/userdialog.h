#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include "common.h"

class Core;
namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();
    user_t GetUser();
    void SetUser(std::string id);
    void SetCore(Core * core);
signals:
    void user_loaded_signal(void*a);
    
private:
    Ui::UserDialog *ui;
    Core * m_pCore;
    static void user_loaded(void * obj, void * a);
    std::string user_id;
private slots:
    void user_loaded_slot(void*a);
};

#endif // USERDIALOG_H