#include "mainwindow.h"
#include "ui_mainwindow.h"

#define TRUE 1
#define FALSE 0

#define REGISTRY_FILE "configs/settings.ini"

#define REGISTRY_KEY_EXISTS "YDG3X2M"
#define REGISTRY_KEY_RECOVERABLE "7N3MPX4"
#define REGISTRY_KEY_SERVER_HOSTNAME "Q2WU6O9"
#define REGISTRY_KEY_SERVER_USERNAME "IRV31SZ"
#define REGISTRY_KEY_SERVER_DAILY "6H8D2K0"
#define REGISTRY_KEY_CLIENT_BACKUP "7B4XM8Z"
#define REGISTRY_KEY_CLIENT_USERNAME "9H4AZ1L"

#define REGISTRY_KEY_COMMAND "69J71R8"
#define REGISTRY_KEY_ATTEMPTS "KTDJ7M9"

#define REGISTRY_DEFAULT_VALUE ""

#define EXIT_ANIMATION_LENGHT 500
#define EXIT_ANIMATION_CURVE QEasingCurve::InOutCirc

#define FAVORITE_TAB_INDEX 2
#define RESTART_PROGRAM close();\
    qApp->quit();\
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

#define RESET_ATTEMPTS attempts = 11;\
settings.setValue(REGISTRY_KEY_ATTEMPTS, 11);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    run(this),
    multi(this)
{
    ui->setupUi(this);

    setMinimumSize(0, 0);

    qApp->processEvents();

    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height() / 4;
    int width = rec.width() / 4;
    move(width, height);

    QSettings settings(QString(REGISTRY_FILE), QSettings::IniFormat);

    ui->file2Group->hide();
    ui->file1Text->hide();
    ui->downloadF1Button->hide();

    exitAnimation = new QPropertyAnimation(this, "windowOpacity");
    exitAnimation->setEasingCurve(EXIT_ANIMATION_CURVE);
    exitAnimation->setDuration(EXIT_ANIMATION_LENGHT);
    exitAnimation->setStartValue(qreal(1));
    exitAnimation->setEndValue(qreal(0));

    connect(exitAnimation, SIGNAL(finished()), qApp, SLOT(quit()));

    multi.start();

    checkRegistryKey();

    command = settings.value(REGISTRY_KEY_COMMAND, REGISTRY_DEFAULT_VALUE).toString();

    run.moveToThread(&multi);
    run.commandPtr = &command;
    run.internalTimer->stop();
    run.done = false;
    run.startRunning();

    run.internalTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();

    run.internalTimer->stop();

    multi.exit(0);

    ui->centralWidget->hide();

//    exitAnimation->setStartValue(geometry());
//    exitAnimation->setEndValue(QRect(x(), y()+height()/2, width(), 0));
    exitAnimation->start(QPropertyAnimation::DeleteWhenStopped);
}

void MainWindow::on_compareCheckBox_clicked()
{
    ui->file2Group->setHidden(ui->compareCheckBox->isChecked() ^ TRUE);
    ui->file1Text->setHidden(ui->compareCheckBox->isChecked() ^ TRUE);
    ui->downloadF1Button->setHidden
            (ui->compareCheckBox->isChecked() ^ TRUE);
}

void MainWindow::on_favoriteFilesButton_clicked()
{
    ui->tabWidget->setCurrentIndex(FAVORITE_TAB_INDEX);
}

void MainWindow::checkRegistryKey()
{
    if (settings.value(REGISTRY_KEY_EXISTS) != TRUE) {
        configureSoftware();
    }
}

void MainWindow::on_resetButton_clicked()
{
    int ok = QMessageBox::warning(this, "Warning",
"Do you really want to reset your data ? "
"You will still be able to recover most of it.",
QMessageBox::Yes, QMessageBox::No);

    if (ok == QMessageBox::No) {
        return;
    }

    settings.setValue(REGISTRY_KEY_EXISTS, FALSE);

    QMessageBox::information(this, "Information",
                   "The software will now restart");

    RESTART_PROGRAM
}

void MainWindow::on_hResetButton_clicked()
{
    int ok = QMessageBox::warning(this, "Warning",
"Do you really want to reset your data ? "
"You won't be able to recover any of it.",
QMessageBox::Yes, QMessageBox::No);

    if (ok == QMessageBox::No) {
        return;
    }

    settings.clear();
    QMessageBox::information(this, "Information",
                   "The software will now restart");

    RESTART_PROGRAM
}

void MainWindow::configureSoftware()
{
    int ok = QMessageBox::question(this, "Welcome",
"It seems to be the first time you run this program. "
"You must configure it first. Continue ?",
QMessageBox::Yes, QMessageBox::Abort);

    if (ok == QMessageBox::Abort) {
        close();
        return;
    }

    int recover(0);

    if (settings.value(REGISTRY_KEY_RECOVERABLE) == TRUE) {
        recover = QMessageBox::question(this, "Recover",
"A previous installation was detected. "
"Do you want to try to recover data from it ?",
QMessageBox::Yes, QMessageBox::No);
    }

    if (recover == QMessageBox::Yes) {
        configInstance = new configDialog(
        (settings.value(REGISTRY_KEY_SERVER_USERNAME).toString()),
        (settings.value(REGISTRY_KEY_SERVER_HOSTNAME).toString()),
        (settings.value(REGISTRY_KEY_SERVER_DAILY).toString()),
        (settings.value(REGISTRY_KEY_CLIENT_BACKUP).toString()),
        (settings.value(REGISTRY_KEY_CLIENT_USERNAME).toString()),
                    this);
        configInstance->show();
    }
    else {
        configInstance = new configDialog(this);
        configInstance->show();
    }

    configInstance->setModal(true);

    connect(configInstance, SIGNAL(rejected()), this, SLOT(close()));
    connect(configInstance, SIGNAL(accepted()), this, SLOT(connectionTest()));

}

void MainWindow::connectionTest()
{


    settings.setValue(REGISTRY_KEY_EXISTS, TRUE);
    settings.setValue(REGISTRY_KEY_RECOVERABLE, TRUE);

    settings.setValue(REGISTRY_KEY_SERVER_HOSTNAME, (configInstance->serverHost->text()));

    settings.setValue(REGISTRY_KEY_SERVER_USERNAME, (configInstance->serverUser->text()));

    settings.setValue(REGISTRY_KEY_SERVER_DAILY,    (configInstance->serverDaily->text()));

    settings.setValue(REGISTRY_KEY_CLIENT_BACKUP,   (configInstance->clientBackup->text()));

    settings.setValue(REGISTRY_KEY_CLIENT_USERNAME, (configInstance->clientUser->text()));

    QMessageBox::information(this, "Success", "Data successfully saved.");
    sync commandString(sync::linuxos);

    QString osName = getOsName();
    if (osName == "Windows") {
        commandString.Platform = (sync::windowsos);
    } else if (osName == "Linux") {
            commandString.Platform = (sync::linuxos);
    } else if (osName == "MacOSX") {
            commandString.Platform = (sync::macosx);
    } else {
        QMessageBox::critical(this, "ERROR", "Your OS is not supported. \n"
                                                         "This software only supports WindowsOS, "
                                                         "LinuxOS and MacOSX. \nIf you think "
                                                         "that there is an issue, please report it on github.");
        qApp->quit();
    }

    commandString.setClientDir(configInstance->clientBackup->text());

    commandString.setServerUser(configInstance->serverUser->text());
    commandString.setServerHostname(configInstance->serverHost->text());
    commandString.setServerDaily(configInstance->serverDaily->text());
    commandString.setClientUser(configInstance->clientUser->text());

    command = commandString.generateCommand();
    settings.setValue(REGISTRY_KEY_COMMAND, command);

}

void MainWindow::modifyBackup () {
    sync commandString(sync::linuxos);
    QString osName = getOsName();

    if (osName == "Windows") {
        commandString.Platform = (sync::windowsos);
    } else if (osName == "Linux") {
            commandString.Platform = (sync::linuxos);
    } else if (osName == "MacOSX") {
            commandString.Platform = (sync::macosx);
    } else {
        QMessageBox::critical(this, "ERROR", "Your OS is not supported. \n"
                                                         "This software only supports WindowsOS, "
                                                         "LinuxOS and MacOSX. \nIf you think "
                                                         "that there is an issue, please report it on github.");

        qApp->quit();
    }

    QString serverHost = settings.value(REGISTRY_KEY_SERVER_HOSTNAME).toString();
    QString serverUser = settings.value(REGISTRY_KEY_SERVER_USERNAME).toString();
    QString serverDaily = settings.value(REGISTRY_KEY_SERVER_DAILY).toString();

    QString clientBackup = settings.value(REGISTRY_KEY_CLIENT_BACKUP).toString();
    QString clientUser = settings.value(REGISTRY_KEY_CLIENT_USERNAME).toString();

    commandString.setServerHostname(serverHost);
    commandString.setServerUser(serverUser);
    commandString.setServerDaily(serverDaily);

    commandString.setClientDir(clientBackup);
    commandString.setClientUser(clientUser);

    command = commandString.generateCommand();
    settings.setValue(REGISTRY_KEY_COMMAND, command);
}

QString MainWindow::getNewString (QString property)
{
    QString newString = QInputDialog::getText(this,
                        "Change " + property, "Enter new " + property);
    return newString;
}

void MainWindow::on_CServerHostButton_clicked()
{
    QString newValue = getNewString("host");
    settings.setValue(REGISTRY_KEY_SERVER_HOSTNAME, newValue);
    modifyBackup();
}

void MainWindow::on_CServerUserButton_clicked()
{
    QString newValue = getNewString("user");
    settings.setValue(REGISTRY_KEY_SERVER_USERNAME, newValue);
    modifyBackup();
}

void MainWindow::on_CServerDailyButton_clicked()
{
    QString newValue = getNewString("daily");
    settings.setValue(REGISTRY_KEY_SERVER_DAILY, newValue);
    modifyBackup();
}

void MainWindow::on_CClientBackupButton_clicked()
{
    QString newValue = getNewString("backup");
    settings.setValue(REGISTRY_KEY_CLIENT_BACKUP, newValue);
    modifyBackup();
}

void MainWindow::on_CClientUserButton_clicked()
{
    QString newValue = getNewString("user");
    settings.setValue(REGISTRY_KEY_CLIENT_USERNAME, newValue);
    modifyBackup();
}

QString MainWindow::getOsName()
{
    #ifdef _WIN32
    return "Windows";
    #elif _WIN64
    return "Windows";
    #elif __APPLE__ || __MACH__
    return "MacOSX";
    #elif __linux__
    return "Linux";
    #else
    return "Other";
    #endif
}
