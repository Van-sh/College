#!/bin/bash
# 7. Write a program to compute no. of characters and words in each line of given file.

if [ $# -ne 1 ]; then
   echo "Usage: $0 <file>"
fi

if [ ! -f $1 ]; then
   echo "File $1 doesn't exist"
fi

linecount=0

while read line; do
   (( linecount = linecount + 1 ))
   counts=($(echo $line | wc))
   echo -e "${linecount}:\t${counts[1]}\t$((counts[2] - 1))"
   
done < $1
