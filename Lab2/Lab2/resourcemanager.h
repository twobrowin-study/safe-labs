#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "logindialog.h"
#include "resourcemainwindow.h"
#include "user.h"

#include <QApplication>

class ResourceManager: public QApplication
{
    Q_OBJECT

public:
    ResourceManager(int argc, char *argv[]);
    int exec();

private:
    User user;
    LoginDialog loginDialog;
    ResourceModel resourceModel;
    ResourceMainWindow resourceMainWindow;

private slots:
    void signedIn();
    void exitToLogin();
};

#endif // RESOURCEMANAGER_H
