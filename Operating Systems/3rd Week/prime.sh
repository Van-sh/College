#!/bin/bash
# 4. Write a script to check whether the number is prime or not

if [ "$#" -ne 1 ]; then
   echo "Usage: $0 <number-1>"
   exit 1
fi

if [ $1 -le 1 ]; then
   echo "${1} is not a prime number."
   exit 0
fi

for (( i = 2; i <= $1 / i + 1; i++ )); do
   if (( $1 % $i == 0 )); then
      echo "${1} is not a prime number. Divisible by ${i}"
      exit 0
   fi
done

echo "${1} is a prime number"
