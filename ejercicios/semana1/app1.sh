#!/bin/bash
# -*- coding: utf-8 -*-

NUM_TRIALS=10

if [ ! $# -eq 3 ]
then
  echo -e "Usage: The command needs a <name>, a positive integer and a filename as an argument\n\te.g. $0 5" >&2; exit 1
fi

re="^[0-9]+$"
if ! [[ $2 =~ $re ]]
then
  echo "Error: Not a positive integer number" >&2; exit 1
fi

[ -f $3 ] && echo "File: <$3> exists and will be overwritten" 1>&2

printf "Checks passed, running the calculations" >&2
printf "Process id=%d" $$
echo -e "experiment\tdata" > $3
for it in `seq $NUM_TRIALS`
do
    num=`od -An -N1 -i /dev/random`
    if [ $num -gt $2 ]
    then
        let num=$2
    fi
    printf "%s\t%d\n" $1 $num >> $3
done

exit 0
