#!/bin/bash
# 15. Write a program for page replacement policy using LRU, FIFO and Optimal.

read -rp "Enter number of frames: " frames

read -rp "Enter reference string (space separated): " -a ref
n=${#ref[@]}

fifo() {
   echo "----- FIFO -----"
   local -i faults=0
   local -a queue=()
   for (( i = 0; i < n; i++ )); do
      page=${ref[$i]}
      found=0

      for x in "${queue[@]}"; do
         if [[ $x == "$page" ]]; then
            found=1
            break
         fi
      done

      if (( found == 0 )); then
         (( faults++ ))
         if (( ${#queue[@]} < frames )); then
            queue+=("$page")
         else
            queue=("${queue[@]:1}")
            queue+=("$page")
         fi
      fi
      echo "Frames: ${queue[*]}"
   done

   echo "Total Page Faults (FIFO): $faults"
   echo
}

lru() {
   echo "----- LRU -----"
   local -i faults=0
   local -a frame=()
   local -a recent=()
   for (( i = 0; i < n; i++ )); do
      page=${ref[$i]}
      found=0
      for (( j = 0; j < ${#frame[@]}; j++ )); do
         if (( frame[j] == page )); then
            found=1
            recent[j]=$i
            break
         fi
      done

      if (( found == 0 )); then
         (( faults++ ))
         if (( ${#frame[@]} < frames )); then
            frame+=("$page")
            recent+=("$i")
         else
            min=${recent[0]}
            pos=0
            for (( j = 1; j < ${#recent[@]} ;j++ )); do
               if (( recent[j] < min )); then
                  min=${recent[$j]}
                  pos=$j
               fi
            done
            frame[pos]=$page
            recent[pos]=$i
         fi
      fi
      echo "Frames: ${frame[*]}"
   done

   echo "Total Page Faults (LRU): $faults"
   echo
}

optimal() {
   echo "----- Optimal -----"
   local -i faults=0
   local -a frame=()
   for (( i = 0; i < n; i++ )); do
      page=${ref[$i]}
      found=0
      for p in "${frame[@]}"; do
         if (( p == page )); then
            found=1
            break
         fi
      done

      if (( found == 0 )); then
         (( faults++ ))
         if [[ ${#frame[@]} -lt $frames ]]; then
            frame+=("$page")
         else
            farthest=-1
            index=-1
            for (( j = 0; j < ${#frame[@]}; j++ )); do
               next_use=-1
               for (( k = i + 1; k < n; k++ )); do
                  if [[ ${ref[$k]} == "${frame[$j]}" ]]; then
                     next_use=$k
                     break
                  fi
               done
               if (( next_use == -1 )); then
                  index=$j
                  break
               elif (( next_use > farthest )); then
                  farthest=$next_use
                  index=$j
               fi
            done
            frame[index]=$page
         fi
      fi
      echo "Frames: ${frame[*]}"
   done

   echo "Total Page Faults (Optimal): $faults"
   echo
}

fifo
lru
optimal

