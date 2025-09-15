#!/bin/bash
# 8. Write a program to print the Fibonacci series upto n terms.

if [ $# -ne 1 ]; then
   echo "Usage: $0 <terms>"
fi

a=1
b=1

echo -n "$a "

for i in $(seq 1 $(( $1 - 1 ))); do
   (( c = a + b ))
   echo -n "$b "
   a=$b
   b=$c
done

echo
