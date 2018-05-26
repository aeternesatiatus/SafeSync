#ifndef MACOSX_H
#define MACOSX_H

#include <QString>

namespace macosx
{
    static const QString first = "#!/bin/bash\n\ndate > /home/";
    // second: clientUser
    static const QString third = "/rsync.log\nrsync -e ssh -av --delete --hard-links --progress \"";
    // fourth: clientDir
    static const QString fifth = "/\" ";
    // sixth: serverUser
    static const QString seventh = "@";
    // eighth: serverHostname
    static const QString ninth = ":/";
    // Tenth: serverDaily
    static const QString eleventh = "/ >> rsync.log";
};

#endif // MACOSX_H
