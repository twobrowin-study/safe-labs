#ifndef DIALOGREGISTRATION_H
#define DIALOGREGISTRATION_H

#include "user.h"

#include <QDialog>

namespace Ui {
class DialogRegistration;
}

class DialogRegistration : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRegistration(User *user, QWidget *parent = nullptr);
    ~DialogRegistration();

private slots:
    void on_pushButtonSave_clicked();

private:
    Ui::DialogRegistration *ui;
    User *user;
};

#endif // DIALOGREGISTRATION_H
