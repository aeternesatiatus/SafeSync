#include "sync.h"
#include "linux.h"
#include "windows.h"
#include "macosx.h"

sync::sync(sync::os platform, QObject *parent) : QObject(parent), Platform(platform)
{
    
}

void sync::setClientUser (QString value) {
    clientUser = value;
    emit clientUserChanged();
}

void sync::setClientDir (QString value) {
    clientDir = value;
    emit clientDirChanged();
}

void sync::setServerUser (QString value) {
    serverUser = value;
    emit serverUserChanged();
}

void sync::setServerHostname (QString value) {
    serverHostname = value;
    emit serverHostnameChanged();
}

void sync::setServerDaily (QString value) {
    serverDaily = value;
    emit serverDailyChanged();
}

void sync::setCwrsync (QString value) {
    cwrsync = value;
    emit cwrsyncChanged();
}

QString sync::generateCommand () {
    QString command;

    switch (Platform) {
        case windowsos:
            command = (windows::first + cwrsync + windows::third +
                       clientDir + windows::fifth + serverUser +
                       windows::seventh + serverHostname +
                       windows::ninth + serverDaily +
                       windows::eleventh);
            break;
        case linuxos: // same for linux and mac

        case macosx:
            command = (gnulinux::first + clientUser + gnulinux::third +
                   clientDir + gnulinux::fifth + serverUser +
                   gnulinux::seventh + serverHostname +
                   gnulinux::ninth + serverDaily +
                   gnulinux::eleventh);
            break;
    }
    return command;
}

