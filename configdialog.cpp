#include "configdialog.h"
#include "ui_configdialog.h"

configDialog::configDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);
    initPtr();
}

configDialog::configDialog(const QString &host, const QString &username
                         , const QString &password, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);

    ui->hostLine->setText(host);
    ui->userLine->setText(username);
    ui->passLine->setText(password);
    initPtr();
}

configDialog::~configDialog()
{
    delete ui;
}

void configDialog::initPtr()
{
    hostPtr = ui->hostLine;
    usrPtr = ui->userLine;
    passPtr = ui->passLine;
    setModal(true);
}

void configDialog::on_passCheck_clicked()
{
    if (ui->passCheck->isChecked() == true) {
        ui->passLine->setEchoMode(QLineEdit::Normal);
    }
    else {
        ui->passLine->setEchoMode(QLineEdit::Password);
    }
}
