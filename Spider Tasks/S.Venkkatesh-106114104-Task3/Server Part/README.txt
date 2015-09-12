S.VENKKATESH
CSE
106114104

I first installed vsftpd using rpm because my os crashed when using lvm and i completed 
task2 in ubuntu. As i was installing again  , it will take time for configuring yum and 
hence i did using rpm. after installing i opened port 21 for ftp transfer using iptables
The default location for  ftp transfer is /var/ftp. I created some files in the directory
and  also enabled anonymous user login for easier work.  then i restarted vsftpd and opened
browser and typed ftp://localhost and it gave me /var/ftp ie the ftp directory.
 