#!/bin/bash
# 9. Write a program to implement CPU scheduling for shortest remaining time first.

function calculate_average {
   local arr=("${!1}")
   local sum=0

   for (( i = 0; i < n; i++ )); do
      (( sum = sum + arr[i] ))
   done

   echo "$(bc -l <<< "scale=6;$sum / ${#arr[@]}")"
}

read -p "Enter number of processes: " n

if (( n <= 0 )); then
   echo "No processes to schedule. Exiting."
   exit 0
fi

for (( i = 0; i < n; i++ )); do
   read -p "Enter arrival time for Process $(( i + 1 )): " at[$i]
   read -p "Enter burst time for Process $(( i + 1 )): " bt[$i]
   pid[$i]=$(( i + 1 ))
   remaining_bt[$i]=${bt[$i]}
   wt[$i]=0
   tt[$i]=0
   rt[$i]=-1
   completion_time[$i]=-1
   last_run_time[$i]=${at[$i]}
done

echo -e "\nProcess\t\tResponse Time\tWaiting Time\tTurn Around Time"

current_time=0
completed_processes=0

while (( completed_processes < n )); do
   min_remaining_burst=2147483647
   shortest_process_idx=-1

   for (( i = 0; i < n; i++ )); do
      if (( at[i] <= current_time && remaining_bt[i] > 0 )); then
         if (( remaining_bt[i] < min_remaining_burst )); then
            min_remaining_burst=${remaining_bt[$i]}
            shortest_process_idx=$i
         elif (( remaining_bt[i] == min_remaining_burst && at[i] < at[shortest_process_idx] )); then
            shortest_process_idx=$i
         fi
      fi
   done

   if (( shortest_process_idx == -1 )); then
      (( current_time += 1 ))
      continue
   fi

   if (( rt[shortest_process_idx] == -1 )); then
      rt[$shortest_process_idx]=$(( current_time - at[shortest_process_idx] ))
   fi

   (( remaining_bt[shortest_process_idx] -= 1 ))
   (( current_time += 1 ))
   last_run_time[$shortest_process_idx]=${current_time}

   if (( remaining_bt[shortest_process_idx] == 0 )); then
      completed_processes=$(( completed_processes + 1 ))
      tt[$shortest_process_idx]=$(( current_time - at[shortest_process_idx] ))
      wt[$shortest_process_idx]=$(( tt[shortest_process_idx] - bt[shortest_process_idx] ))
   fi
done

for idx in "${pid[@]}"; do
   index=$((idx - 1))
   echo -e "P${pid[$index]}\t\t${rt[$index]}\t\t${wt[$index]}\t\t${tt[$index]}"
done

echo -e "Average Response time: $(calculate_average rt[@])"
echo -e "Average waiting time: $(calculate_average wt[@])"
echo -e "Average Turnaround time: $(calculate_average tt[@])"
