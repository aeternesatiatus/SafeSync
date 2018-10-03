#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QRect>
#include <QDesktopWidget>
#include <QFileInfo>
#include <QFileDialog>

namespace Ui {
class configDialog;
}

class configDialog : public QDialog
{
    Q_OBJECT

public:
    explicit configDialog(QWidget *parent = 0);
    explicit configDialog(const QString &serverUser,
                            const QString &serverHost,
                            const QString &serverDaily,
                            const QString &serverBackup,
                            const QString &clientBackup,
                            const QString &clientKey,
                            QWidget *parent = 0);
    ~configDialog();

    QLineEdit *serverUser, *serverHost, *serverDaily, *serverBackup, *clientBackup, *clientKey;

private:
    Ui::configDialog *ui;

    void initPtr();
private slots:
    void on_searchButton_clicked();
    void on_searchBackupButton_clicked();
    void on_searchSSHButton_clicked();
};

#endif // CONFIGDIALOG_H
