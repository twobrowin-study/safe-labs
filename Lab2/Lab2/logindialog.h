#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "dialogregistration.h"
#include "user.h"

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(User *user, QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_pushButtonSignIn_clicked();

    void on_pushButtonSignUp_clicked();

signals:
    void signedInSucess();

private:
    Ui::LoginDialog *ui;
    User *user;
    DialogRegistration dialogRegistration;
};

#endif // LOGINDIALOG_H
