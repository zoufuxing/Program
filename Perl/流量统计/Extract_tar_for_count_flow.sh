#!/bin/bash
echo $1
cd $1
#tar -zxvf *.tar.gz  && rm -f *.tar.gz
for i in `ls $i`;do /bin/tar -zxvf $i && rm -f $i;done
