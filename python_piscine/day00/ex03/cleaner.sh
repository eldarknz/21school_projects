#!/bin/sh

sed -e 's/[ (][Dd]ata [Ss]cientist[ )]//g; s/[Dd]ata [Ss]cientist[ /,]//g; s/[ /,][Dd]ata [Ss]cientist//g' ../ex02/hh_sorted.csv > hh_positions.csv
