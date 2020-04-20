#!/bin/sh

file="../ex01/hh.csv"

(head -n1 $file && tail -n+2 $file | sort -t , -n -k2.10 -k2.13 -k1) > hh_sorted.csv
