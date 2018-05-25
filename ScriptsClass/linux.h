#ifndef LINUX_H
#define LINUX_H

#include <QString>

namespace gnulinux
{
    static const QString first = "date > /home/";
    // second: clientUser
    static const QString third = "/rsync.log\nrsync -e ssh -av --delete --hard-links --progress \"";
    // fourth: clientDir
    static const QString fifth = "/\" ";
    // sixth: serverUser
    static const QString seventh = "@";
    // eighth: serverHostname
    static const QString ninth = ":";
    // Tenth: serverDaily
    static const QString eleventh = "/ >> rsync.log";
};

#endif // LINUX_H
