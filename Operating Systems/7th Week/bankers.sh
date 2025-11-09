#!/bin/bash
# 19. Write a program to implement bankers algorithm for deadlock avoidance.

read -rp "Enter number of processes: " n
read -rp "Enter number of resources: " m

echo "Enter Allocation Matrix:"
for (( i = 0; i < n; i++ )); do
   read -ra row
   for (( j = 0; j < m; j++ )); do
      alloc[$((i * m + j))]=${row[j]}
   done
done

echo "Enter Max Matrix:"
for (( i = 0; i < n; i++ )); do
   read -ra row
   for (( j = 0; j < m; j++ )); do
      max[$((i * m + j))]=${row[j]}
   done
done

echo "Enter Available Resources:"
read -a avail

for (( i = 0; i < n; i++ )); do
   for (( j = 0; j < m; j++ )); do
      idx=$((i * m + j))
      need[idx]=$(( max[idx] - alloc[idx] ))
   done
done

for (( i = 0; i < n; i++ )); do
   finish[$i]=0
done

count=0
safe_seq=()
while (( count < n )); do
   found=false
   for (( p = 0; p < n; p++ )); do
      if (( finish[p] == 0 )); then
         can_allocate=true
         for (( i = 0; i < m; i++)); do
            need_val=${need[p * m + j]}
            avail_val=${avail[j]}
            if (( need_val > avail_val )); then
               can_allocate=false
               break
            fi
         done
         if [[ $can_allocate = true ]]; then
            for (( i = 0; i < m; i++ )); do
               (( avail[i] += alloc[p * m + i] ))
            done
            finish[p]=1
            safe_seq+=("$p")
            (( count += 1 ))
            found=true
         fi
      fi
   done
   if [[ $found == false ]]; then
      echo "System is in UNSAFE State"
      exit 1
   fi
done
