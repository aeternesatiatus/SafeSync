#ifndef COMMANDSTRUCT_H
#define COMMANDSTRUCT_H

#include <QString>

namespace commandStruct
{
    static const QString first = "date > rsync.log; rsync -e 'ssh -i ";
    // second: clientKey
    static const QString third = "' -av --delete --hard-links --progress '";
    // fourth: clientDir
    static const QString fifth = "' ";
    // sixth: serverUser
    static const QString seventh = "@";
    // eigth: serverHostname
    static const QString ninth = ":";
    // tenth: serverDaily
    static const QString eleventh = " >> rsync.log";
};

#endif // COMMANDSTRUCT_H
