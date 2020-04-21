#!/bin/sh

file="../ex03/hh_positions.csv"

cat $file | while read line 
do
	# 2020-04-17T13:12:04+0300
	# val=`echo $line | sed 's/.*\([[:digit:]-]\{10\}T[[:digit:]\:]\{8\}+[[:digit:]]\{4\}\).*/\1/'`
	val=`echo $line | sed 's/.*\([[:digit:]-]\{10\}\).*/\1/'`
	l=`echo "$val" | awk '{print length}'`
	if [ $l -eq 10 ]
	then
		[ -f $val ]
		if [ $? -eq 1 ]
		then
			head -n1 $file > $val
		fi
		echo "$line" >> $val
	fi
done
