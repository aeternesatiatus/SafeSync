@echo off
SET PATH=./
date /T >>rsync.log
time /T >>rsync.log
rsync.exe -e ssh.exe -av --delete --progress "rsync.log" root@139.99.157.74:/home/luka/ >> rsync.log
echo TERMINE
pause