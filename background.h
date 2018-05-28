#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QWidget>

#include <sys/utsname.h>

class background : public QObject
{
    Q_OBJECT
public:
    background(QWidget *mbparent, QObject *parent = 0);
    QString osName = "", *commandPtr;
    QTimer *internalTimer;
private:
    bool done;
    QString getOsName();
    QWidget *temp;
public slots:
    void verify();
    void startRunning();
};

#endif // BACKGROUND_H
