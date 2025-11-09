#!/bin/bash
# 17. Write a program to implement reader/writer problem using semaphore.

mutex=1
wrt=1
read_count=0

down() {
   local -n semaphore=$1
   while (( semaphore <= 0 )); do
      sleep 1
   done
   (( semaphore -= 1 ))
}

up() {
   local -n semaphore=$1
   (( semaphore += 1 ))
}

reader() {
   local -i id=$1
   echo "Reader $id is trying to read ... "

   down mutex
   read_count=$((read_count + 1))
   if (( read_count == 1 )); then
      down wrt
   fi
   up mutex
   
   echo "Reader $id is reading"
   sleep "$((RANDOM % 2 + 1))"
   echo "Reader $id finished reading"
   
   down mutex
   (( read_count -= 1 ))
   if (( read_count == 0 )); then
      up wrt
   fi
   up mutex
}

writer() {
   local -i id=$1
   echo "Writer $id is trying to write ... "

   down wrt

   echo "Writer $id is writing"
   sleep "$((RANDOM % 3 + 1))"
   echo "Writer $id finished writing"

   up wrt
}

read -rp "Enter number of readers: " nr
read -rp "Enter number of writers: " nw
for (( i = 1; i <= nr || i <= nw; i++ )); do
   if (( i <= nr )); then
      reader $i &
   fi
   if (( i <= nw )); then
      writer $i &
   fi
done;

wait
