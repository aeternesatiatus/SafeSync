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
                           const QString &clientBackup,
                           const QString &clientUser,
                           QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);

    ui->serverUserLine->setText(serverUser);
    ui->serverHostLine->setText(serverHost);
    ui->serverDailyLine->setText(serverDaily);
    ui->clientBackupLine->setText(clientBackup);
    ui->clientUserLine->setText(clientUser);

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
    clientBackup = ui->clientBackupLine;
    clientUser = ui->clientUserLine;

    setTabOrder(ui->serverUserLine, ui->serverHostLine);
    setTabOrder(ui->serverHostLine, ui->serverDailyLine);
    setTabOrder(ui->serverDailyLine, ui->clientBackupLine);
    setTabOrder(ui->clientBackupLine, ui->clientUserLine);

    setModal(true);
}
