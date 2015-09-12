S.VENKKATESH
106114104
CSE

1- To create the four logical partitions , i used fdisk /dev/sda and create four locical
partitions from 6 to 9 as 5 was reserved for swap. I used command n to create the partitiob
l to specify its logical and +1536M for giving it 1.5G space. Also by default it assigned 
type linux. so using t command i assigned it to linux LVM(8e).So now four logical partitions
are done and used w to write them on disk and rebooted.

2- I used pvcreate command to make sda6,7,8 into physical volume.(pvcreate /dev/sda6 /dev/
sda7 /dev/sda8). Now three physcial volumes have been created.

3-a,3-b - Now im putting under a volume group spider of 4.5G using vgcreate. This help us 
in creating logical volume of respective sizes.
(vgcreate spider /dev/sda6 /dev/sda7 /dev/sda8)

4&5&6 - Now im creating logical volumes out of the volume group using lvcreate. Here the 
space can be specified based on the size (1.5G) or integral multiples of minimum allocation
unit(4mb)(lvcreate -l 256 -n redhat spider)

7-a , 7-b , 7-c : In this Im assigning ext4 filesystem to the created logical volumes using
mkfs (mkfs -t ext4 /dev/spider/redhat)

7-d - Now im creating a directory in desktop for the three logical volumes and assigning them
as mount points for the three lv's of ext4 filesystem using mount command
(mount -t ext4 /dev/spider/redhat /home/venkaktesh/Desktop/redhat

8 - im writing the entries in the /etc/fstab so that these get mounted on boot itself.
Here im setting the dump and fsck order values as 0 as its a less important partition and
their mount order doesnt matter.
(/dev/spider/redhat /home/venkkatesh/Desktop/redhat ext defaults 0 0)

9 -Now im increasing the size of the logical volume redhat from 1 to 1.5G. I use lvexpand
and give +512M so that the size increase to 1.5G. Also for the changes to reflect on the
mount point use resize2fs command
(lvexpand -L+512M /dev/spider/redhat
resize2fs /dev/spider/redhat)

10-now im reducing the size of kali to 1.5g .I first use resize2fs so the there wont be any
file loss on reducing the space .I use lvreduce and give -512M so that it reduces 
from 2G to 1.5G.(resize2fs /dev/spider/kali lvreduce -L-512M /dev/redhat/kali)

11-im now creating a physical volume of the 4th partition using pvcreate 

12-Im appending the fourth partion into the volume group spider using vgextend command
(vgextend spider /dev/sda9)

13-Im removing the 4th partition from the volume group by vgreduce
(vgreduce spider /dev/sda9)

14-Deleting the entries from fstab.

15- Im unmounting the lv's from desktop using umount command
(umount /dev/spider/redhat /home/venkkatesh/Desktop/redhat)

16- Im removing the logical volumes and deleting the volume group using lvremove and 
vgremove
(lvremove /dev/sda/kali
vgremove spider)

17 -Now im removing the physical volumes created using pvremove.
(pvremove /dev/sda6 /dev/sda7 /dev/sda8 /dev/sda9)

18- Im now converitng the partiotions back to linux using t;83 and not deleting them so
that further lvm can be done.