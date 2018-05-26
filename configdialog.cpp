#include "configdialog.h"
#include "ui_configdialog.h"

configDialog::configDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);
    initPtr();
}

configDialog::configDialog(const QString &serverUser,
                           const QString &serverHost,
                           const QString &serverDaily,
                           const QString &clientUser,
                           const QString &clientBackup,
                           QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);

    ui->serverUserLine->setText(serverUser);
    ui->serverHostLine->setText(serverHost);
    ui->serverDailyLine->setText(serverDaily);
    ui->clientUserLine->setText(clientUser);
    ui->clientBackupLine->setText(clientBackup);

    initPtr();
}

configDialog::~configDialog()
{
    delete ui;
}

void configDialog::initPtr()
{
    serverUser = ui->serverUserLine;
    serverHost = ui->serverHostLine;
    serverDaily = ui->serverDailyLine;
    clientUser = ui->clientUserLine;
    clientBackup = ui->clientBackupLine;

    setTabOrder(ui->serverUserLine, ui->serverHostLine);
    setTabOrder(ui->serverHostLine, ui->serverDailyLine);
    setTabOrder(ui->serverDailyLine, ui->clientUserLine);
    setTabOrder(ui->clientUserLine, ui->clientBackupLine);

    setModal(true);
}
