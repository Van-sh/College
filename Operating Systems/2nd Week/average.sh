#!/bin/bash
# 3. Write a script to calculate the average of n numbers

read -p "Enter number of numbers: " n

sum=0
for i in $(seq 0 $(( n - 1 ))); do
   read -p "Enter number $(( i + 1 )): " num
   (( sum = sum + num ))
done


echo "Average"
echo -e "Without Decimals: $(( sum / n ))"
average=`echo "$sum / $n" | bc -l`
echo -e "With Decimals:    $average"
