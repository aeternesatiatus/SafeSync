#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QRect>
#include <QDesktopWidget>

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
                            const QString &serverDaily, const QString &clientUser,
                            const QString &clientBackup, QWidget *parent = 0);
    ~configDialog();

    QLineEdit *serverUser, *serverHost, *serverDaily, *clientUser, *clientBackup;

private:
    Ui::configDialog *ui;

    void initPtr();
};

#endif // CONFIGDIALOG_H
