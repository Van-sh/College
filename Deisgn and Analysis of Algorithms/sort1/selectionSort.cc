#include <chrono>
#include <random>
#include <vector>
#include <iostream>
#include <string_view>

double measureAverageTime(std::vector<int> &arr, int trials);
void printVector(const std::vector<int> &arr);
void runCase(const std::string_view &label, std::vector<int> &arr, int trials);

void selectionSort(std::vector<int> &arr)
{
   for (size_t i = 0; i < arr.size() - 1; i++)
   {
      int minIndex = i;
      for (size_t j = i + 1; j < arr.size(); j++)
      {
         if (arr[j] < arr[minIndex])
         {
            minIndex = j;
         }
      }
      if (minIndex != i)
      {
         std::swap(arr[i], arr[minIndex]);
      }
   }
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
      selectionSort(copy);
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
   selectionSort(copy);
   std::cout << "After: ";
   printVector(copy);
   std::cout << "\n";

   double avgTime = measureAverageTime(arr, trials);
   std::cout << "Average Time: " << avgTime << " ns\n\n";
}
