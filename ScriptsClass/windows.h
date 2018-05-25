#ifndef WINDOWS_H
#define WINDOWS_H

#include <QString>

namespace windows
{
    static const QString first = "@echo off\nset PATH=\"";
    // second: cwrsync
    static const QString third = "\"\ndate /T >>rsync.log\ntime /T >>rsync.log\nrsync -e ssh -av --delete --hard-links --progress \"";
    // fourth: clientDir
    static const QString fifth = "/\" ";
    // sixth: serverUser
    static const QString seventh = "@";
    // eighth: serverHostname
    static const QString ninth = ":/";
    // tenth: serverDaily
    static QString eleventh = "/ >> rsync.log";
};

#endif // WINDOWS_H
