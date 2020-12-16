#include "dialogregistration.h"
#include "ui_dialogregistration.h"

DialogRegistration::DialogRegistration(User *user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRegistration),
    user(user)
{
    ui->setupUi(this);
    ui->labelError->setStyleSheet("QLabel { color : red; }");
}

DialogRegistration::~DialogRegistration()
{
    delete ui;
}

void DialogRegistration::on_pushButtonSave_clicked()
{
    User testUser;
    testUser.user_name = ui->lineEditUserName->text();
    testUser.password = ui->lineEditPassword->text();
    testUser.sur_name = ui->lineEditSurName->text();
    testUser.name = ui->lineEditName->text();
    testUser.sec_name = ui->lineEditSecName->text();
    testUser.birth_day = ui->dateEditBirthDate->date();
    testUser.birth_place = ui->lineEditBirthPlace->text();
    testUser.phone_number = ui->lineEditPhoneNumber->text();

    switch (testUser.checkPassword(testUser.password))
    {
        case User::PASSWORD_OK:
            break;
        case User::PASSWORD_BAD_LENGTH:
            ui->labelError->setText("Длина пароля должна быть 8 символов");
            return;
        case User::PASSWORD_BAD_FORMAT:
            ui->labelError->setText("Пароль должен содержить только\nцифры и знаки припенания");
            return;
        case User::PASSWORD_EQ_BIRTH_DATE:
            ui->labelError->setText("Пароль не должен совпадать\nс датой рождения");
            return;
    }

    ui->lineEditUserName->clear();
    ui->lineEditPassword->clear();
    ui->lineEditSurName->clear();
    ui->lineEditName->clear();
    ui->lineEditSecName->clear();
    ui->dateEditBirthDate->clear();
    ui->lineEditBirthPlace->clear();
    ui->lineEditPhoneNumber->clear();
    *user = testUser;
    this->close();
}
