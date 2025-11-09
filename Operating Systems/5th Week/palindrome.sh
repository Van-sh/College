#!/bin/bash
# 12. Write a program to check whether the given string is a palindrome.

if (( $# != 1 )); then
   echo "Usage: $0 <string>"
   exit 1
fi

str=$1

left=0
right=$((${#str} - 1))

while (( left < right )); do
   if [[ ${str:$left:1} != "${str:$right:1}" ]]; then
      echo "$str is not a palindrome"
      exit 0
   fi
   (( left += 1 ))
   (( right -= 1 ))
done

echo "$str is a palindrome"
