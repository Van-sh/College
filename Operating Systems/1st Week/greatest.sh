#!/bin/bash
# 1. Write a program using shell scripting to find the greatest of 5 numbers

if [ "$#" -ne 5 ]; then
   echo "Usage: $0 <number-1> <number-2> <number-3> <number-4> <number-5>"
   exit 1
fi

greatest=${1}

for i in {2..5}; do
   current=${!i}
   if [ $current -gt $greatest ]; then
      greatest=$current
   fi
done

echo "The greatest number is \"${greatest}\""