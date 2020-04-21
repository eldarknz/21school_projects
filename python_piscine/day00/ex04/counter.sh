#!/bin/sh

file="../ex03/hh_positions.csv"

(echo "\"name\",\"count\"" && tail -n+2 $file | awk -F, '{print $3}' | sort | uniq -c | awk -F"\"" '{print"\""$2"\"" "," $1}' | sed 's/[^,a-zA-Zа-яА-Я()] [^0-9]//g') > hh_uniq_positions.csv
