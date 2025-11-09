#!/bin/bash
# 11. Write a program to calculate the sum of digits of the given number.

if (( $# != 1 )); then
   echo "Usage: $0 <number>"
   exit 1
fi

sum=0
temp=$1

while [[ $temp != 0 ]]; do
   (( sum += temp % 10 ))
   (( temp /= 10 ))
done

echo "Sum of the digits of $1 is $sum"
