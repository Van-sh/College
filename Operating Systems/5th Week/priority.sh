#!/bin/bash
# 13. Write a program to implement the priority scheduling.

read -rp "Enter number of processes: " n

for (( i = 0; i < n; i++ )); do
   read -rp "Enter burst time and priority for process $(( i + 1 )): " bt["i"] p["i"]
   pid[i]=$i
done

echo -e "\nProcess\t\tWaiting Time\tTurn Around Time"

for (( i = 0; i < n - 1; i++ )); do
   for (( j = 0; j < n - i - 1; j++ )); do
      if (( p[pid[j]] > p[pid[j + 1]] )); then
         temp=${pid[j]}
         pid[j]=${pid[j+1]}
         pid[j+1]=$temp
      fi
   done
done

for (( i = 0; i < n; i++ )); do
   if (( i == 0 )); then
      wt[pid[i]]=0
   else
      wt[pid[i]]=$((wt[pid[i - 1]] + bt[pid[i - 1]] ))
   fi
   tt[pid[i]]=$((wt[pid[i]] + bt[pid[i]] ))
done

for (( i = 0; i < n; i++ )) do
   echo -e "$(( i + 1 ))\t\t${wt[i]}\t\t${tt[i]}"
done
