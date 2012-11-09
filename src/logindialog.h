#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    QString GetLoginName();
    QString GetPassword();
    
private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
