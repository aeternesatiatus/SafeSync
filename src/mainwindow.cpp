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
#define REGISTRY_KEY_SERVER_BACKUP "TY78S4K"
#define REGISTRY_KEY_CLIENT_BACKUP "7B4XM8Z"
#define REGISTRY_KEY_CLIENT_KEY "6H01MW2"

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
    settings("settings.ini", QSettings::IniFormat, this),
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
        (settings.value(REGISTRY_KEY_SERVER_BACKUP).toString()),
        (settings.value(REGISTRY_KEY_CLIENT_BACKUP).toString()),
        (settings.value(REGISTRY_KEY_CLIENT_KEY).toString()),
                    this);
        configInstance->show();
    }
    else {
        configInstance = new configDialog(this);
        configInstance->show();
    }

    configInstance->setModal(true);

    run.done = true;

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

    settings.setValue(REGISTRY_KEY_SERVER_BACKUP,   (configInstance->serverBackup->text()));

    settings.setValue(REGISTRY_KEY_CLIENT_BACKUP,   (configInstance->clientBackup->text()));

    settings.setValue(REGISTRY_KEY_CLIENT_KEY, (configInstance->clientKey->text()));

    QMessageBox::information(this, "Success", "Data successfully saved.");
    sync commandString(sync::linuxos);

    QString osName = getOsName();
    if (osName == "Linux") {
        commandString.Platform = (sync::linuxos);
    } else if (osName == "MacOSX") {
        commandString.Platform = (sync::macosx);
    } else {
        QMessageBox::critical(this, "ERROR", "Your OS is not supported. \n"
                                                         "This software only supports "
                                                         "LinuxOS and MacOSX. \nIf you think "
                                                         "that there is an issue, please report it on github.");
        qApp->quit();
    }

    commandString.setServerUser(configInstance->serverUser->text());
    commandString.setServerHostname(configInstance->serverHost->text());
    commandString.setServerDaily(configInstance->serverDaily->text());

    commandString.setClientDir(configInstance->clientBackup->text());
    commandString.setClientKey(configInstance->clientKey->text());

    command = commandString.generateCommand();
    settings.setValue(REGISTRY_KEY_COMMAND, command);
    run.done = false;

}

void MainWindow::modifyBackup () {
    sync commandString(sync::linuxos);
    QString osName = getOsName();

    if (osName == "Linux") {
        commandString.Platform = (sync::linuxos);
    } else if (osName == "MacOSX") {
        commandString.Platform = (sync::macosx);
    } else {
        QMessageBox::critical(this, "ERROR", "Your OS is not supported. \n"
                                                         "This software only supports "
                                                         "LinuxOS and MacOSX. \nIf you think "
                                                         "that there is an issue, please report it on github.");

        qApp->quit();
    }

    QString serverHost = settings.value(REGISTRY_KEY_SERVER_HOSTNAME).toString();
    QString serverUser = settings.value(REGISTRY_KEY_SERVER_USERNAME).toString();
    QString serverDaily = settings.value(REGISTRY_KEY_SERVER_DAILY).toString();

    QString clientBackup = settings.value(REGISTRY_KEY_CLIENT_BACKUP).toString();
    QString clientKey = settings.value(REGISTRY_KEY_CLIENT_KEY).toString();

    commandString.setServerHostname(serverHost);
    commandString.setServerUser(serverUser);
    commandString.setServerDaily(serverDaily);

    commandString.setClientDir(clientBackup);
    commandString.setClientKey(clientKey);

    command = commandString.generateCommand();
    settings.setValue(REGISTRY_KEY_COMMAND, command);
}

QString MainWindow::getNewString (QString property, bool &ok)
{
    QString newString = QInputDialog::getText(this,
                        "Change " + property, "Enter new " + property, QLineEdit::Normal, QString(), &ok);
    return newString;
}

void MainWindow::on_CServerHostButton_clicked()
{
    bool ok;
    QString newValue = getNewString("host", ok);
    if (ok)
        settings.setValue(REGISTRY_KEY_SERVER_HOSTNAME, newValue);
    modifyBackup();
}

void MainWindow::on_CServerUserButton_clicked()
{
    bool ok;
    QString newValue = getNewString("user", ok);
    if (ok)
        settings.setValue(REGISTRY_KEY_SERVER_USERNAME, newValue);
    modifyBackup();
}

void MainWindow::on_CServerDailyButton_clicked()
{
    bool ok;
    QString newValue = getNewString("daily", ok);
    if (ok)
        settings.setValue(REGISTRY_KEY_SERVER_DAILY, newValue);
    modifyBackup();
}

void MainWindow::on_CServerBackupButton_clicked()
{
    bool ok;
    QString newValue = getNewString("backup", ok);
    if (ok)
        settings.setValue(REGISTRY_KEY_SERVER_BACKUP, newValue);
}

void MainWindow::on_CClientBackupButton_clicked()
{
    bool ok;
    QString newValue = getNewString("backup", ok);
    if (ok)
        settings.setValue(REGISTRY_KEY_CLIENT_BACKUP, newValue);
    modifyBackup();
}

void MainWindow::on_CClientKeyButton_clicked()
{
    bool ok;
    QString newValue = getNewString("key", ok);
    if (ok)
        settings.setValue(REGISTRY_KEY_CLIENT_KEY, newValue);
    modifyBackup();
}

void MainWindow::on_CSyncButton_clicked()
{
    sync commandString(sync::linuxos);
    QString osName = getOsName();

    if (osName == "Linux") {
        commandString.Platform = (sync::linuxos);
    } else if (osName == "MacOSX") {
        commandString.Platform = (sync::macosx);
    } else {
        QMessageBox::critical(this, "ERROR", "Your OS is not supported. \n"
                                                         "This software only supports "
                                                         "LinuxOS and MacOSX. \nIf you think "
                                                         "that there is an issue, please report it on github.");

        qApp->quit();
    }

    QString serverHost = settings.value(REGISTRY_KEY_SERVER_HOSTNAME).toString();
    QString serverUser = settings.value(REGISTRY_KEY_SERVER_USERNAME).toString();
    QString serverDaily = settings.value(REGISTRY_KEY_SERVER_DAILY).toString();

    QString clientBackup = settings.value(REGISTRY_KEY_CLIENT_BACKUP).toString();
    QString clientKey = settings.value(REGISTRY_KEY_CLIENT_KEY).toString();

    commandString.setServerHostname(serverHost);
    commandString.setServerUser(serverUser);
    commandString.setServerDaily(serverDaily);

    commandString.setClientDir(clientBackup);
    commandString.setClientKey(clientKey);

    command = commandString.generateCommand();

    int work = system (command.toStdString().c_str());
    (void)work;
}

void MainWindow::on_CSearchButton_clicked()
{
    sync commandString(sync::linuxos);
    QString osName = getOsName();
    QString serverHost = settings.value(REGISTRY_KEY_SERVER_HOSTNAME).toString();
    QString serverUser = settings.value(REGISTRY_KEY_SERVER_USERNAME).toString();
    QString serverBackup = settings.value(REGISTRY_KEY_SERVER_BACKUP).toString();

    QString fileManagerCommand = "";
    QString sftpCommand = "sftp://" + serverUser + "@" + serverHost + ":" + serverBackup;
    int work = 0;
    showMinimized();
    if (osName == "Linux") {
         fileManagerCommand = "nautilus " + sftpCommand;
    } else if (osName == "MacOSX") {
       fileManagerCommand = "open /Applications/Cyberduck.app/Contents/MacOS/Cyberduck";
    } else {
        QMessageBox::critical(this, "ERROR", "Your OS is not supported. \n"
                                                         "This software only supports "
                                                         "LinuxOS and MacOSX. \nIf you think "
                                                         "that there is an issue, please report it on github.");

        qApp->quit();
    }
    work = system (fileManagerCommand.toStdString().c_str());
    (void)work;
}

void MainWindow::on_CLogButton_clicked()
{
    QString osName = getOsName();
    int work = 0;
    if (osName == "Linux") {
        work = system ("gedit rsync.log");
        if (work) {
            work = system ("mousepad rsync.log");
        }
    } else if (osName == "MacOSX") {
        work = system ("open rsync.log");
    } else {
        QMessageBox::critical(this, "ERROR", "Your OS is not supported. \n"
                                                         "This software only supports "
                                                         "LinuxOS and MacOSX. \nIf you think "
                                                         "that there is an issue, please report it on github.");

        qApp->quit();
    }
    (void)work;
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

void MainWindow::on_changeBackupButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Backup", QString(), QString());
    if (fileName.isEmpty()) return;
    settings.setValue(REGISTRY_KEY_CLIENT_BACKUP, fileName);
    modifyBackup();
}

void MainWindow::on_changeSSHButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "SSH Key", QString(), QString());
    if (fileName.isEmpty()) return;
    settings.setValue(REGISTRY_KEY_CLIENT_KEY, fileName);
    modifyBackup();
}
