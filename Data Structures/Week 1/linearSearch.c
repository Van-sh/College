#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int), target;
    printf("Enter number to find: ");
    scanf("%i", &target);
    int result = linearSearch(arr, size, target);
    if (result == -1) {
        printf("%i not found in the array.\n", target);
    }
    else {
        printf("%i found at index %i.\n", target, result);
    }
    return 0;
}