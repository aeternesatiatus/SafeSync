@echo off
set PATH="programdir/extractedexe"
date /T >>rsync.log
time /T >>rsync.log
date > /home/USER/rsync.log
rsync -e ssh -av --delete --hard-links --progress "/home/NAME_OF_DIR_YOU_CHOSE/" USER@HOSTNAME:/PATH_TO_SERVER_DAILY_BACKUP_FOLDER/ >> rsync.log
echo TERMINE
