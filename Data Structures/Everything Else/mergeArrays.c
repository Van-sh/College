#include <stdio.h>

int main() {
  int arr1[] = {1, 3, 5, 7, 9};
  int arr2[] = {2, 4, 6, 8, 10};
  int arr3[10];
  int i = 0, j = 0, k = 0;
  while (i < 5 && j < 5) {
    if (arr1[i] < arr2[j]) {
      arr3[k++] = arr1[i++];
    } else {
      arr3[k++] = arr2[j++];
    }
  }
  while (i < 5) {
    arr3[k++] = arr1[i++];
  }
  while (j < 5) {
    arr3[k++] = arr2[j++];
  }
  printf("Merged array: ");
  for (i = 0; i < 10; i++) {
    printf("%i ", arr3[i]);
  }
  printf("\n");
  return 0;
}