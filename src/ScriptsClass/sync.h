#ifndef SYNC_H
#define SYNC_H

#include <QObject>
#include <QString>

#include "linux.h"
#include "macosx.h"
#include "windows.h"

class sync : public QObject
{
    Q_OBJECT

public:
    enum os {
        windowsos, linuxos, macosx
    };

    explicit sync(sync::os platform, QObject *parent = nullptr);
    explicit sync();
    sync::os Platform;
    void setClientUser (QString value);
    void setClientDir (QString value);
    void setServerUser (QString value);
    void setServerHostname (QString value);
    void setServerDaily (QString value);
    void setCwrsync (QString value);

    QString readClientUser ();
    QString readClientDir ();
    QString readServerUser ();
    QString readServerHostname ();
    QString readServerDaily ();
    QString readCwrsync ();

    QString generateCommand ();

    QString clientUser;
    QString clientDir; // path to client backup folder
    QString serverUser;
    QString serverHostname;
    QString serverDaily; // Path to daily backup folder
    QString cwrsync; // Path to cwrsync.exe in ressources

signals:
    void clientUserChanged ();
    void clientDirChanged ();
    void serverUserChanged ();
    void serverHostnameChanged ();
    void serverDailyChanged ();
    void cwrsyncChanged ();
};

#endif // SYNC_H
