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
                           const QString &serverBackup,
                           const QString &clientBackup,
                           const QString &clientKey,
                           QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);

    ui->serverUserLine->setText(serverUser);
    ui->serverHostLine->setText(serverHost);
    ui->serverDailyLine->setText(serverDaily);
    ui->serverBackupLine->setText(serverBackup);

    ui->clientBackupLine->setText(clientBackup);
    ui->clientKeyLine->setText(clientKey);

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
    serverBackup = ui->serverBackupLine;

    clientBackup = ui->clientBackupLine;
    clientKey = ui->clientKeyLine;

    setTabOrder(ui->serverUserLine, ui->serverHostLine);
    setTabOrder(ui->serverHostLine, ui->serverDailyLine);
    setTabOrder(ui->serverDailyLine, ui->serverBackupLine);
    setTabOrder(ui->serverBackupLine, ui->clientBackupLine);
    setTabOrder(ui->clientBackupLine, ui->clientKeyLine);

    setModal(true);
}

void configDialog::on_searchBackupButton_clicked()
{
    QString folderName = QFileDialog::getExistingDirectory (this, "Open Client Backup Directory", QString(), QFileDialog::ShowDirsOnly);
    if (folderName.isEmpty()) return;
    ui->clientBackupLine->setText(folderName);
}

void configDialog::on_searchSSHButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Public SSH key", QString(), QString());
    if (fileName.isEmpty()) return;
    ui->clientKeyLine->setText(fileName);
}
