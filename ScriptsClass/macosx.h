#ifndef MACOSX_H
#define MACOSX_H

#include <QString>

namespace macosx
{
    static const QString first = "#!/bin/bash\n\ndate > rsync.log\nrsync -e ssh -av --delete --hard-links --progress \"";
    // second: clientDir
    static const QString third = "\" ";
    // fourth: serverUser
    static const QString fifth = "@";
    // sixth: serverHostname
    static const QString seventh = ":";
    // eight: serverDaily
    static const QString ninth = " >> rsync.log";
};

#endif // MACOSX_H
