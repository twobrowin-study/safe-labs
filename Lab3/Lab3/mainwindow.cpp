#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMath>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qreal p  = ui->lineEditP->text().toDouble();
    qint32 v = ui->lineEditV->text().toInt();
    qint32 t = ui->lineEditT->text().toInt();

    qint32 sStar = static_cast<qint32>((v*t)/p);
    ui->labelSstar->setNum(sStar);

    QString alphabet = "";
    if(ui->checkBoxLatUp->checkState())  { alphabet += ui->checkBoxLatUp->property("Alphabet").toString(); }
    if(ui->checkBoxLatLow->checkState()) { alphabet += ui->checkBoxLatLow->property("Alphabet").toString(); }
    if(ui->checkBoxCyrUp->checkState())  { alphabet += ui->checkBoxCyrUp->property("Alphabet").toString(); }
    if(ui->checkBoxCyrLow->checkState()) { alphabet += ui->checkBoxCyrLow->property("Alphabet").toString(); }
    if(ui->checkBoxSym->checkState())    { alphabet += ui->checkBoxSym->property("Alphabet").toString(); }
    if(ui->checkBoxNum->checkState())    { alphabet += ui->checkBoxNum->property("Alphabet").toString(); }
    qint32 a = alphabet.size();
    ui->labelA->setNum(a);

    qint32 l = static_cast<qint32>(qLn(sStar) / qLn(a)) + 1;
    ui->labelL->setNum(l);

    QString password = "";
    for(qint32 i = 0; i < l; i++)
    {
        quint32 k = QRandomGenerator::global()->generate() % static_cast<quint32>(a);
        password += alphabet[k];
    }
    ui->labelPassword->setText(password);
}
