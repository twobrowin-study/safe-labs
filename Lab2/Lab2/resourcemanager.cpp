#include "resourcemanager.h"

ResourceManager::ResourceManager(int argc, char *argv[])
    : QApplication(argc, argv)
    , loginDialog(&user)
    , resourceModel("/tmp")
    , resourceMainWindow(&user)
{
    connect(&loginDialog, &LoginDialog::signedInSucess, this, &ResourceManager::signedIn);
    connect(&resourceMainWindow, &ResourceMainWindow::exitSignal, this, &ResourceManager::exitToLogin);
}

int ResourceManager::exec()
{
    loginDialog.show();
    return QApplication::exec();
}

void ResourceManager::signedIn()
{
    loginDialog.hide();
    resourceMainWindow.setResourceModel(&resourceModel);
    resourceMainWindow.show();
}

void ResourceManager::exitToLogin()
{
    resourceMainWindow.hide();
    loginDialog.show();
}
