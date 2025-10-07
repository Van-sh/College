#!/bin/bash
# 10. Write a program to calculate the factorial of a given number.

if [[ $# != 1 ]]; then
   echo "Usage: $0 <number>"
   exit 1
fi

if [[ $1 < 0 ]]; then
   echo "number must be greater than 0"
   exit 2
fi

result=1
for (( i = 1; i <= $1; i++ )); do
   (( result *= i ))
done

echo "Factorial of $1 is $result"
