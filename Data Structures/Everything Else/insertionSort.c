#include <stdio.h>

void insertionSort(int arr[], int n) {
  int i, j;
  for (i = 1; i < n; i++) {
    int key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {64, 52, 12, 22, 11, 23};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertionSort(arr, n);
  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
    printf("%i ", arr[i]);
  printf("\n");
  return 0;
}