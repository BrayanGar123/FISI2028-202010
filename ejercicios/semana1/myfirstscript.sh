#!/bin/bash
# -*- coding: utf-8 -*-

echo "Printing random numbers with /dev/random"
stat /dev/random
entropy=$(cat /proc/sys/kernel/random/entropy_avail)
echo "How much entropy before calling /dev/random? $entropy"

# Now we create a file where we will store ages of turtles
echo "Turtle ages" > test.dat
for it in `seq 1000`
do
    num=`od -An -N1 -i /dev/random`
    if [ $num -gt 150 ]
    then
        let num=150+1
    elif (( $num <= 10 ))
    then
        num=$(($num-1))
    fi
    echo $num >> test.dat
done
echo "How much entropy after calling /dev/random? $(cat /proc/sys/kernel/random/entropy_avail)"
