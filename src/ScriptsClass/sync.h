#ifndef SYNC_H
#define SYNC_H

#include <QObject>
#include <QString>

#include "commandstruct.h"

class sync : public QObject
{
    Q_OBJECT

public:
    enum os {
        linuxos, macosx
    };

    explicit sync(sync::os platform, QObject *parent = nullptr);
    explicit sync();
    sync::os Platform;
    void setClientDir (QString value);
    void setClientKey (QString value);
    void setServerUser (QString value);
    void setServerHostname (QString value);
    void setServerDaily (QString value);

    QString readClientDir ();
    QString readClientKey ();
    QString readServerUser ();
    QString readServerHostname ();
    QString readServerDaily ();

    QString generateCommand ();

    QString clientDir; // path to client backup folder
    QString clientKey; // path to client ssh key
    QString serverUser;
    QString serverHostname;
    QString serverDaily; // Path to daily backup folder

signals:
    void clientDirChanged ();
    void clientKeyChanged ();
    void serverUserChanged ();
    void serverHostnameChanged ();
    void serverDailyChanged ();
};

#endif // SYNC_H
