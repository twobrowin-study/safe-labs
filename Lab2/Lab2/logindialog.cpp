#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(User *user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    user(user),
    dialogRegistration(user)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButtonSignIn_clicked()
{
    QString user_name = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    if (    (user_name.length() > 0) && (user_name == user->user_name) &&
            ( password.length() > 0) && (password == user->password)    )
    {
        ui->lineEditUsername->clear();
        ui->lineEditPassword->clear();
        emit signedInSucess();
    }
}

void LoginDialog::on_pushButtonSignUp_clicked()
{
    dialogRegistration.show();
}
