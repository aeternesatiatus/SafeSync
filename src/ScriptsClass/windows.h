#ifndef WINDOWS_H
#define WINDOWS_H

#include <QString>

namespace windows
{
    static const QString first = "@echo off&&set PATH='";
    // second: cwrsync
    static const QString third = "&&date /T >>rsync.log&&time /T >>rsync.log&&rsync -e 'ssh -i C:\\Users\\";
    // fourth clientUser
    static const QString fifth = "\\.ssh\\id_rsa -av --delete --hard-links --progress '";
    // sixth: clientDir
    static const QString seventh = "/' ";
    // eight: serverUser
    static const QString ninth = "@";
    // tenth: serverHostname
    static const QString eleventh = ":/";
    // tenth: serverDaily
    static QString twelfth = "/ >> rsync.log";
};

#endif // WINDOWS_H
