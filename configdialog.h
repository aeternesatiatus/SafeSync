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
    explicit configDialog(const QString & host, const QString & username,
                          const QString & password, QWidget *parent = 0);
    ~configDialog();

    QLineEdit *hostPtr, *usrPtr, *passPtr, *sPassPtr;

private:
    Ui::configDialog *ui;

    void initPtr();
public slots:
    void on_passCheck_clicked();
};

#endif // CONFIGDIALOG_H
