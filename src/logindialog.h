#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
class LoginDialog;
}
class Core;

class LoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    QString GetLoginName();
    QString GetPassword();
    static LoginDialog * GetCurrentDialog(){return current_dialog;}
    static bool ResetCurrentDialog(){current_dialog = NULL;}
    void SetCore(Core * core);
private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::LoginDialog *ui;
    static LoginDialog * current_dialog;
    Core * m_pCore;
};

#endif // LOGINDIALOG_H
