// 39. Write a program to illustrate call by reference for swapping 2 numbers
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int x = 5, y = 10;
    printf("x = %i, y = %i\n", x, y);
    swap(&x, &y);
    printf("x = %i, y = %i\n", x, y);
}