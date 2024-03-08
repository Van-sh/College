// 35. Write a program to check if an array is a subset of another array
#include <stdio.h>

void main()
{
    int arr1[] = {2, 7, 6}, arr2[] = {1, 2, 3, 4, 5, 6};
    int size1 = sizeof(arr1) / sizeof(int), size2 = sizeof(arr2) / sizeof(int);
    int isSubset = 1;
    for (int x = 0; x < size1; x++)
    {
        int found = 0;
        for (int y = 0; y < size2 && !found; y++)
        {
            if (arr1[x] == arr2[y])
            {
                found = 1;
            }
        }
        if (!found)
        {
            isSubset = 0;
            break;
        }
    }
    if (isSubset)
    {
        printf("arr1 is a subset of arr2\n");
    }
    else
    {
        printf("arr1 is not a subset of arr2\n");
    }
}