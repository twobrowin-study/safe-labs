#include "dialogpasswordchange.h"
#include "ui_dialogpasswordchange.h"

DialogPasswordChange::DialogPasswordChange(User *user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPasswordChange),
    user(user)
{
    ui->setupUi(this);
    ui->labelError->setStyleSheet("QLabel { color : red; }");
}

DialogPasswordChange::~DialogPasswordChange()
{
    delete ui;
}

void DialogPasswordChange::on_pushButtonSave_clicked()
{
    QString curr_password = ui->lineEditCurrentPasword->text();
    QString new_password1 = ui->lineEditNewPassword->text();
    QString new_password2 = ui->lineEditNewPasswordAgain->text();

    if (new_password1.length() == 0 && new_password1 != new_password2)
    {
        ui->labelError->setText("Новый пароль нужно повторить 2 раза");
        return;
    }
    if (user->password != curr_password)
    {
        ui->labelError->setText("Текущий пароль не верный");
        return;
    }
    switch (user->checkPassword(new_password1))
    {
        case User::PASSWORD_OK:
            user->password = new_password1;
            ui->lineEditCurrentPasword->clear();
            ui->lineEditNewPassword->clear();
            ui->lineEditNewPasswordAgain->clear();
            this->close();
            break;
        case User::PASSWORD_BAD_LENGTH:
            ui->labelError->setText("Длина пароля должна быть 8 символов");
            break;
        case User::PASSWORD_BAD_FORMAT:
            ui->labelError->setText("Пароль должен содержать только цифры\nи знаки препинания");
            break;
        case User::PASSWORD_EQ_BIRTH_DATE:
            ui->labelError->setText("Пароль не должен совпадать с датой рождения");
            break;
    }
}
