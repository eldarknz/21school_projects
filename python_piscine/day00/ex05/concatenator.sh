#!/bin/sh

dir="./"

files=`ls "$dir" | tr " " "\n"`

files=`echo "$files" | sed -n '/.*\([[:digit:]-]\{10\}\).*/p' | tr "\n" " "`

cat $files | sort -r | uniq | sort -t , -n -k2.10 -k2.13 -k1 > hh_positions.csv
