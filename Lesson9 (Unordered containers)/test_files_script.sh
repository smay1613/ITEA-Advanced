#!/bin/bash

tgtdir=$1

dircount="1"
filecount="1"
ddoutput="/dev/null"
comp="zero"
setblksize="100"
smallfile="124"
largefile="126"
numdirs="3"
maxfiles="5"
minfiles="3"

while [ $dircount -le $numdirs ]
do /bin/mkdir -p $tgtdir/directory-$dircount
numfiles=$(( RANDOM% ($maxfiles - $minfiles) + $minfiles ))
for (( c=1; c<=$numfiles; c++ ))
do /bin/dd if=/dev/$comp of=$tgtdir/directory-$dircount/file-$filecount bs=$setblksize count=`echo $(( $smallfile+(RANDOM )%($largefile-$smallfile+1) *1024 ))` >> $ddoutput 2>&1 &
(( filecount ++ ))
done
(( dircount ++ ))
done 

"./unordered_hw" $tgtdir

