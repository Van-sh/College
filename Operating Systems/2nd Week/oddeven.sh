#!/bin/bash
# 2. Write a script to check whether the given no. is prime or not.

if [ "$#" -ne 1 ]; then
   echo "Usage: $0 <number>"
   exit 1
fi

if (( $1 % 2 == 0 )); then
   echo "$1 is even"
else
   echo "$1 is odd"
fi
