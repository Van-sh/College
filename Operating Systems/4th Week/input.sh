#!/bin/bash
# 6. Write a program to check whether the given input is a number or a string.

if [ $# -ne 1 ]; then
   echo "Usage; $0 <input>"
   exit 1
fi

if [[ $1 =~ ^[0-9]+$ ]]; then
   echo "$1 is an integer"
else
   echo "$1 is a string"
fi
