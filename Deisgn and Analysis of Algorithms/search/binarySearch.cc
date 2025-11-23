#include <chrono>
#include <vector>
#include <iostream>
#include <string_view>

double measureAverageTime(std::vector<int> &arr, int target, int trials);
void printVector(const std::vector<int> &arr);
void runCase(const std::string_view &label, std::vector<int> &arr, int target, int trials);

size_t binarySearch(const std::vector<int> &arr, int target)
{
   size_t left = 0, right = arr.size() - 1;
   while (left <= right)
   {
      size_t mid = left + (right - left) / 2;
      if (arr[mid] == target)
         return mid;
      else if (arr[mid] < target)
         left = mid + 1;
      else
         right = mid - 1;

      if (right == ULLONG_MAX)
         break;
   }
   return -1;
}

int main()
{
   int n = 10;
   int trials = 1000000;
   std::vector<int> arr(n);
   for (int i = 0; i < n; i++)
   {
      arr[i] = i + 1;
   }

   int bestCase = arr[(n - 1) / 2];
   int averageCase = arr[(n - 3) / 4];
   int worstCase = arr[n - 1];
   int notFoundCase = n + 1;

   std::cout << "Insertion Sort Timing (" << n << " elements, " << trials << " trials)\n\n";

   runCase("Best Case", arr, bestCase, trials);
   runCase("Average Case", arr, averageCase, trials);
   runCase("Worst Case", arr, worstCase, trials);
   runCase("Not Found Case", arr, notFoundCase, trials);
}

double measureAverageTime(std::vector<int> &arr, int target, int trials)
{
   long long totalTime = 0;
   for (int t = 0; t < trials; t++)
   {
      auto start = std::chrono::high_resolution_clock::now();
      binarySearch(arr, target);
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

void runCase(const std::string_view &label, std::vector<int> &arr, int target, int trials)
{
   std::cout << label << ":\n";
   std::cout << "Array: ";
   printVector(arr);
   std::cout << "\nTarget: " << target << "\n";
   double avgTime = measureAverageTime(arr, target, trials);
   std::cout << "Average Time: " << avgTime << " ns\n\n";
}
