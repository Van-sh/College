#!/bin/bash
# 14.  Write a program to implement CPU scheduling for Round Robin.

read -rp "Enter number of processes: " n
read -rp "Enter time quantum: " t

for (( i = 0; i < n; i++ )); do
   read -rp "Enter burst time for process $(( i + 1 )): " bt["i"]
   rbt[i]=${bt[i]}
   rt[i]=-1
done

echo -e "\nProcess\t\tResponse Time\tWaiting Time\tTurn Around Time"

cpid=0
ct=0
cp=0

while (( cp < n )); do
   if (( rt[cpid] == -1 )); then
      rt[cpid]=$ct
   fi

   if (( rbt[cpid] > t )); then
      (( ct += t ))
      (( rbt[cpid] -= t ))
   elif (( rbt[cpid] > 0 )); then
      (( ct += rbt[cpid] ))
      rbt[cpid]=0
      (( cp += 1 ))
      tt[cpid]=$ct
      wt[cpid]=$(( tt[cpid] - bt[cpid] ))
   fi
   (( cpid = (cpid + 1) % n ))
done

for (( i = 0; i < n; i++ )) do
   echo -e "$(( i + 1 ))\t\t${rt[i]}\t\t${wt[i]}\t\t${tt[i]}"
done

sum=0
average=0
for (( i = 0; i < n; i++ )); do
   (( sum = sum + rt[i] ))
done

average=$(bc -l <<< "scale=6;$sum / $n")
echo -e "Average response time: ${average}"

sum=0
average=0
for (( i = 0; i < n; i++ )); do
   (( sum = sum + wt[i] ))
done

average=$(bc -l <<< "scale=6;$sum / $n")
echo -e "Average waiting time: ${average}"

sum=0
average=0
for (( i = 0; i < n; i++ )); do
   (( sum = sum + tt[i] ))
done

average=$(bc -l <<< "scale=6;$sum / $n")
echo -e "Average Turnaround time: ${average}"
