#ifndef RESOURCEMAINWINDOW_H
#define RESOURCEMAINWINDOW_H

#include "dialogpasswordchange.h"
#include "logindialog.h"
#include "resourcemodel.h"

#include <QMainWindow>

namespace Ui {
class ResourceMainWindow;
}

class ResourceMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResourceMainWindow(User *user, QWidget *parent = nullptr);
    ~ResourceMainWindow();
    void setResourceModel(ResourceModel *resourceModel);

private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtoChangePassword_clicked();

signals:
    void exitSignal();

private:
    Ui::ResourceMainWindow *ui;
    User *user;
    DialogPasswordChange dialogPasswordChange;
};

#endif // RESOURCEMAINWINDOW_H
