// 2. Perform Linear Search and Binary Search on an array. Description of programs:
// a. Read an array of type integer
// b. Input element from user for searching
// c. Search the element by passing the array to a function and then returning the position of the element
// from the function else return -1 if the element is not found
// d. Display the position where the element has been found
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
    int arr[100], size, target;
    printf("Enter size of array: ");
    scanf("%i", &size);
    printf("Enter Array: ");
    for (int i = 0; i < size; i++) {
        scanf("%i", &arr[i]);
    }
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