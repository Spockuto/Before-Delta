S.VENKKATESH
CSE
106114104


I created shell script which lists the files in Desktop and moves them to seperate 
folders. Since mkdir and mv command requires root permission sudo was used. hence when the
command was executed it asks for root permission. 

I created the script and named it as venkkatesh.sh. Now i gave the script executable permission
by giving 555 so that the script can be read and executed but not rewritable. after this 
i moved the script to /usr/bin/venkkatesh so that .sh can be ommited. After this when i
typed venkkatesh the shell script worked as a comamnd.