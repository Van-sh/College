#!/bin/bash
# 18. Write a program to implement producer-consumer problem using semaphore.

buffer=()
buffer_size=5
mutex=1
empty=$buffer_size
full=0

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

producer() {
   local -i id=$1
   local -i item
   down empty
   down mutex

   item=$(( RANDOM % 100 ))
   buffer+=("$item")
   sleep "0.$(( RANDOM % 5 + 1 ))"
   echo "Producer $id produced item $item | Buffer: ${buffer[*]}"
   
   up mutex
   up full
}

consumer() {
   local -i id=$1
   local -i item
   down full
   down mutex
   
   item=${buffer[0]}
   buffer=("${buffer[@]:1}")
   sleep "0.$(( RANDOM % 5 + 1 ))"
   echo "Consumer $id consumed item $item | Buffer: ${buffer[*]}"
   
   up mutex
   up empty
}

for ((i=1; i <= 6; i++)); do
   producer $i
   consumer $i
done