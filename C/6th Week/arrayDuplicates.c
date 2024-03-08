// 34. Write a program to count the total number of duplicate elements in an array
#include <stdio.h>

void main()
{
    int arr[] = {2, 3, 2, 4, 3, 3, 6, 5};
    int duplicateCount = 0, size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicateCount++;
                break;
            }
        }
    }
    printf("%i\n", duplicateCount);
}