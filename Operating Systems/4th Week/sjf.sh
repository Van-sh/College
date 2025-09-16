#!/bin/bash
# 9. Write a program to implement CPU scheduling for shortest job first.

read -p "Enter number of processes: " n

for i in $(seq 0 "$(( n - 1 ))"); do
   read -p "Enter burst time for process $(( i + 1 )): " bt[$i]
   pid[$i]=$(( i + 1 ))
done

echo -e "\nProcess\t\tWaiting Time\tTurn Around Time"

for i in $(seq 0 $(( n - 1 ))); do
   for j in $(seq $(( i + 1 )) $(( n - 1 ))); do
      if [ ${bt[$j]} -lt ${bt[$i]} ]; then
         (( bt[$i] ^= bt[$j] ))
         (( bt[$j] ^= bt[$i] ))
         (( bt[$i] ^= bt[$j] ))

         (( pid[$i] ^= pid[$j] ))
         (( pid[$j] ^= pid[$i] ))
         (( pid[$i] ^= pid[$j] ))
      fi
   done
done

for i in $(seq 0 "$(( n - 1 ))"); do
   if [ $i -eq 0 ]; then
      wt[$i]=0
   else
      (( wt[i] = bt[i-1] + wt[i-1] ))
   fi
   (( tt[i] = wt[i] + bt[i] ))
   echo -e "${pid[$i]}\t\t${wt[$i]}\t\t${tt[$i]}"
done

sum=0
average=0
for i in $(seq 0 "$((n-1))"); do
   (( sum = sum + wt[i] ))
done

average=`echo "scale=6;$sum / $n" | bc -l`
echo -e "Average waiting time: ${average}"

sum=0
average=0
for i in $(seq 0 "$((n-1))"); do
   (( sum = sum + tt[i] ))
done

average=`echo "scale=6;$sum / $n" | bc -l`
echo -e "Average Turnaround time: ${average}"
