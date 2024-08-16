#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int), target;
    printf("Enter number to find: ");
    scanf("%i", &target);
    int result = binarySearch(arr, size, target);
    if (result == -1) {
        printf("%i not found in the array.\n", target);
    }
    else {
        printf("%i found at index %i.\n", target, result);
    }
    return 0;
}