#ifndef WINDOWS_H
#define WINDOWS_H

#include <QString>

namespace windows
{
    static const QString first = "date /T >> rsync.log & time /T >> rsync.log & rsync -e 'ssh -i C:\\Users\\";
    // second clientUser
    static const QString third = "\\.ssh\\id_rsa' -av --delete --hard-links --progress '";
    // fourth: clientDir
    static const QString fifth = "' ";
    // sixth: serverUser
    static const QString seventh = "@";
    // eight: serverHostname
    static const QString ninth = ":";
    // tenth: serverDaily
    static QString eleventh = "/ >> rsync.log";
};

#endif // WINDOWS_H
