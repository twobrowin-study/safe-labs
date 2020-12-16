#include "onlywindow.h"
#include "ui_onlywindow.h"

OnlyWindow::OnlyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OnlyWindow)
{
    ui->setupUi(this);
}

OnlyWindow::~OnlyWindow()
{
    delete ui;
}


void OnlyWindow::on_genPushButton_clicked()
{
    /* Вариант № 5 */
    qint32 M = 10;
    QString idx = ui->idxLineEdit->text();
    qint32 N = idx.length();
    qint32 Q = N % 6;
    ui->qValue->setNum(Q);
    QString password(M, '-');

    /* b1, b2 */
    password[0] = 'A' + rnd(26);
    password[1] = 'A' + rnd(26);

    /* b3...bM-Q-1 */
    for (qint32 i = 2; i < M-Q; i++) {
        password[i] = 'a' + rnd(26);
    }

    /* bM-Q...bM */
    for (qint32 i = M-Q; i < M; i++) {
        password[i] = '0' + rnd(10);
    }

    ui->passwordValue->setText(password);
}
