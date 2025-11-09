#!/bin/bash
# 16. Write a program to implement first fit, worst fit and best fit algorithm for memory management.

read -rp "Enter number of memory blocks:" nb
read -rp "Enter sizes of memory blocks (space separated): " -a block

read -rp "Enter number of processes:" np
read -rp "Enter sizes of processes (space separated):" -a process

first_fit() {
   echo "----- FIRST FIT -----"
   local -a allocated=()
   for (( i = 0; i < np; i++ )); do
      allocated[i]=-1
   done

   local temp=("${block[@]}")
   for (( i = 0; i < np; i++ )); do
      for (( j = 0; j < nb; j++ )); do
         if (( temp[j] > process[i] )); then
            allocated[i]=$j
            (( temp[j] -= process[i] ))
            break
         fi
      done
   done

   for (( i = 0; i < np; i++ )); do
      if (( allocated[i] != -1 )); then
         echo "Process $((i + 1)) of size ${process[i]} -> Block $((allocated[i] + 1))"
      else
         echo "Process $((i + 1)) of size ${process[i]} -> Not Allocated"
      fi
   done
   echo
}

best_fit() {
   echo "----- BEST FIT -----"
   local -a allocated=()
   for (( i = 0; i < np; i++ )); do
      allocated[i]=-1
   done
   
   local -a temp=("${block[@]}")
   local -i best
   for (( i = 0; i < np; i++ )); do
      best=-1
      for (( j = 0; j < nb; j++ )); do
         if (( temp[j] > process[i] )); then
            if (( best == -1 || temp[j] < temp[best] )); then
               best=$j
            fi
         fi
      done
      if (( best != -1 )); then
         allocated[i]=$best
         (( temp[best] -= process[i]))
      fi
   done

   for (( i = 0; i < np; i++ )); do
      if (( allocated[i] != -1 )); then
         echo "Process $((i + 1)) of size ${process[i]} -> Block $((allocated[i] + 1))"
      else
         echo "Process $((i + 1)) of size ${process[i]} -> Not Allocated"
      fi
   done
   echo
}

worst_fit() {
   echo "----- WORST FIT -----"
   local -a allocated=()
   for (( i = 0; i < np; i++ )); do
      allocated[i]=-1
   done

   local -a temp=("${block[@]}")
   local -i worst
   for (( i = 0; i < np; i++ )); do
      worst=-1
      for (( j = 0; j < nb; j++ )); do
         if (( temp[j] > process[i] )); then
            if (( worst == -1 || temp[j] > temp[worst] )); then
               worst=$j
            fi
         fi
      done
      if (( worst != -1 )); then
         allocated[i]=$worst
         (( temp[worst] -= process[i] ))
      fi
   done

   for (( i = 0; i < np; i++ )); do
      if [[ ${allocated[i]} -ne -1 ]]; then
         echo "Process $((i+1)) of size ${process[i]} -> Block $((allocated[i]+1))"
      else
         echo "Process $((i+1)) of size ${process[i]} -> Not Allocated"
      fi
   done
   echo
}

first_fit
best_fit
worst_fit
