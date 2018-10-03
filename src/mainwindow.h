#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QMessageBox>
#include <QDialog>
#include <QInputDialog>
#include <QProcess>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QCloseEvent>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include <QDebug>


#include <configdialog.h>
#include <ScriptsClass/sync.h>
#include <background.h>

namespace Ui {
// Ui is used to link the XML created in designer with C++ code
class MainWindow;
// Declares a MainWindow class used by both Ui (XML) and C++ classes
}

class MainWindow : public QMainWindow
        // Main Window class herits from QMainWindow
{
    Q_OBJECT // #defined by default in Qt, used for slots and signals

public:
    explicit MainWindow(QWidget *parent = NULL); // Constructor
    void modifyBackup ();
    ~MainWindow(); // Destructor

private:
    Ui::MainWindow *ui; // ui is a pointer to XML class MainWindow

    void checkRegistryKey();
    bool LogIn();
    void configureSoftware();

    QSettings settings;
    QPropertyAnimation *exitAnimation;
    configDialog *configInstance;
    QString getNewString (QString property, bool &ok);
    QString getOsName();
    void makeExecutable (QString file);
    background run;
    QThread multi;
public:
    QString command;

protected:
    void closeEvent(QCloseEvent *event);

public slots:
    // void on_pushButton_clicked();
    // Slots linked with XML (on_instanceName_signal)
    // Another slot used for when a button is clicked
    void on_resetButton_clicked(); // Soft reset.
    void on_hResetButton_clicked();// Hard reset.
    void connectionTest();

    void on_CServerHostButton_clicked();
    void on_CServerUserButton_clicked();
    void on_CServerDailyButton_clicked();
    void on_CServerBackupButton_clicked();

    void on_CClientBackupButton_clicked();
    void on_CClientKeyButton_clicked();

    void on_CLogButton_clicked();
    void on_CSyncButton_clicked();
    void on_CSearchButton_clicked();
    void on_searchBackupButton_clicked();
    void on_changeBackupButton_clicked();
    void on_changeSSHButton_clicked();

signals:
};

#endif // MAINWINDOW_H
