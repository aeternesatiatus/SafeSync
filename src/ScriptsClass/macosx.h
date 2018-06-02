#ifndef MACOSX_H
#define MACOSX_H

#include <QString>

namespace macosx
{
    static const QString first = "date > rsync.log; rsync -e 'ssh -i /home/";
    // second: clientUser
    static const QString third = "/.ssh/id_rsa' -av --delete --hard-links --progress '";
    // fourth: clientDir
    static const QString fifth = "' ";
    // sixth: serverUser
    static const QString seventh = "@";
    // eigth: serverHostname
    static const QString ninth = ":";
    // tenth: serverDaily
    static const QString eleventh = " >> rsync.log";
};

#endif // MACOSX_H
