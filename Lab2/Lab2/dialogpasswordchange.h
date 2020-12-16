#ifndef DIALOGPASSWORDCHANGE_H
#define DIALOGPASSWORDCHANGE_H

#include "user.h"

#include <QDialog>

namespace Ui {
class DialogPasswordChange;
}

class DialogPasswordChange : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPasswordChange(User *user, QWidget *parent = nullptr);
    ~DialogPasswordChange();

private slots:
    void on_pushButtonSave_clicked();

private:
    Ui::DialogPasswordChange *ui;
    User *user;
};

#endif // DIALOGPASSWORDCHANGE_H
