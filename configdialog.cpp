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
                           const QString &serverHost, const QString &serverPass,
                           const QString &serverDaily, const QString &clientUser,
                           const QString &clientBackup, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);

    ui->serverUserLine->setText(serverUser);
    ui->serverHostLine->setText(serverHost);
    ui->serverPassLine->setText(serverPass);
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
    serverPass = ui->serverPassLine;
    serverDaily = ui->serverDailyLine;
    clientUser = clientUser;
    clientBackup = ui->clientBackupLine;

    setModal(true);
}

void configDialog::on_passCheck_clicked()
{
    if (ui->passCheck->isChecked() == true) {
        ui->serverPassLine->setEchoMode(QLineEdit::Normal);
    }
    else {
        ui->serverPassLine->setEchoMode(QLineEdit::Password);
    }
}
