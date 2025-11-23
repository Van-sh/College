#include <chrono>
#include <random>
#include <vector>
#include <iostream>
#include <string_view>

double measureAverageTime(std::vector<int> &arr, int trials);
void printVector(const std::vector<int> &arr);
void runCase(const std::string_view &label, std::vector<int> &arr, int trials);

void merge(std::vector<int> &arr, int low, int mid, int high)
{
   std::vector<int> temp;
   int left = low;
   int right = mid + 1;

   while (left <= mid && right <= high)
   {
      if (arr[left] <= arr[right])
      {
         temp.push_back(arr[left]);
         left++;
      }
      else
      {
         temp.push_back(arr[right]);
         right++;
      }
   }

   while (left <= mid)
   {
      temp.push_back(arr[left]);
      left++;
   }

   while (right <= high)
   {
      temp.push_back(arr[right]);
      right++;
   }

   for (int i = low; i <= high; i++)
   {
      arr[i] = temp[i - low];
   }
}

void ms(std::vector<int> &arr, int low, int high)
{
   if (low >= high)
      return;
   int mid = (low + high) / 2;
   ms(arr, low, mid);
   ms(arr, mid + 1, high);
   merge(arr, low, mid, high);
}

void mergeSort(std::vector<int> &arr)
{
   ms(arr, 0, arr.size() - 1);
}

int main()
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution distrib(1, 100);

   int n = 10;
   int trials = 1000000;

   std::vector<int> bestCase(n);
   for (int i = 0; i < n; i++)
   {
      bestCase[i] = i + 1;
   }

   std::vector<int> averageCase(n);
   for (int i = 0; i < n; i++)
   {
      averageCase[i] = distrib(gen);
   }

   std::vector<int> worstCase(n);
   for (int i = 0; i < n; i++)
   {
      worstCase[i] = n - i;
   }

   std::cout << "Insertion Sort Timing (" << n << " elements, " << trials << " trials)\n\n";

   runCase("Best Case (Already Sorted)", bestCase, trials);
   runCase("Average Case (Random Array)", averageCase, trials);
   runCase("Worst Case (Reverse Sorted)", worstCase, trials);
}

double measureAverageTime(std::vector<int> &arr, int trials)
{
   long long totalTime = 0;
   for (int t = 0; t < trials; t++)
   {
      std::vector<int> copy(arr);
      auto start = std::chrono::high_resolution_clock::now();
      mergeSort(copy);
      auto end = std::chrono::high_resolution_clock::now();
      totalTime +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
   }
   return static_cast<double>(totalTime) / trials;
}

void printVector(const std::vector<int> &arr)
{
   std::cout << "[";
   for (size_t i = 0; i < arr.size(); ++i)
   {
      std::cout << arr[i];
      if (i < arr.size() - 1)
      {
         std::cout << ", ";
      }
   }
   std::cout << "]";
}

void runCase(const std::string_view &label, std::vector<int> &arr, int trials)
{
   std::cout << label << ":\n";
   std::cout << "Before: ";
   printVector(arr);
   std::cout << "\n";

   std::vector<int> copy(arr);
   mergeSort(copy);
   std::cout << "After: ";
   printVector(copy);
   std::cout << "\n";

   double avgTime = measureAverageTime(arr, trials);
   std::cout << "Average Time: " << avgTime << " ns\n\n";
}
