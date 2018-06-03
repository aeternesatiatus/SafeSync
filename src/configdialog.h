#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QRect>
#include <QDesktopWidget>
#include <QFileInfo>

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
                            const QString &clientUser,
                            QWidget *parent = 0);
    ~configDialog();

    QLineEdit *serverUser, *serverHost, *serverDaily, *serverBackup, *clientBackup, *clientUser;

private:
    Ui::configDialog *ui;

    void initPtr();
};

#endif // CONFIGDIALOG_H
