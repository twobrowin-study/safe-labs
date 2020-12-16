#ifndef ONLYWINDOW_H
#define ONLYWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class OnlyWindow; }
QT_END_NAMESPACE

class OnlyWindow : public QMainWindow
{
    Q_OBJECT

public:
    OnlyWindow(QWidget *parent = nullptr);
    ~OnlyWindow();

private slots:
    void on_genPushButton_clicked();

private:
    inline quint32 rnd(quint32 edje) { return QRandomGenerator::global()->generate() % edje; }

private:
    Ui::OnlyWindow *ui;
};
#endif // ONLYWINDOW_H
