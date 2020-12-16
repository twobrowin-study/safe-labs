#include "resourcemainwindow.h"
#include "ui_resourcemainwindow.h"

ResourceMainWindow::ResourceMainWindow(User *user, QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::ResourceMainWindow)
    , user(user)
    , dialogPasswordChange(user)
{
    ui->setupUi(this);
}

ResourceMainWindow::~ResourceMainWindow()
{
    delete ui;
}

void ResourceMainWindow::setResourceModel(ResourceModel *resourceModel)
{
    ui->listViewResource->setModel(resourceModel);
    QString resourceText =
            QString("Вам предоставлен доступ к ресурсу %1 размером %2")
            .arg(resourceModel->getResourceName())
            .arg(resourceModel->rowCount());
    ui->labelResource->setText(resourceText);
}

void ResourceMainWindow::on_pushButtonExit_clicked()
{
    ui->listViewResource->setModel(nullptr);
    ui->labelResource->clear();
    emit exitSignal();
}

void ResourceMainWindow::on_pushButtoChangePassword_clicked()
{
    dialogPasswordChange.show();
}
