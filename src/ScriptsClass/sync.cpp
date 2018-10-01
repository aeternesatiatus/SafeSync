#include "sync.h"
#include "commandstruct.h"

sync::sync(sync::os platform, QObject *parent) : QObject(parent), Platform(platform)
{
    
}

void sync::setServerHostname (QString value) {
    serverHostname = value;
    emit serverHostnameChanged();
}

void sync::setServerUser (QString value) {
    serverUser = value;
    emit serverUserChanged();
}

void sync::setServerDaily (QString value) {
    serverDaily = value;
    emit serverDailyChanged();
}

void sync::setClientDir (QString value) {
    clientDir = value;
    emit clientDirChanged();
}

void sync::setClientKey (QString value) {
    clientKey = value;
    emit clientKeyChanged();
}

QString sync::generateCommand () {
    QString command;

    switch (Platform) {
        case linuxos: // same for linux and mac
        case macosx:
            command = (commandStruct::first + clientKey +
                       commandStruct::third + clientDir +
                       commandStruct::fifth + serverUser +
                       commandStruct::seventh + serverHostname +
                       commandStruct::ninth + serverDaily +
                       commandStruct::eleventh);
            break;
    }
    return command;
}
