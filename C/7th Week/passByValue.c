// 38. Write a program to illustrate call by value for swapping 2 numbers
#include <stdio.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("a = %i, b = %i\n", a, b);
}

void main()
{
    int x = 5, y = 10;
    swap(x, y);
    printf("x = %i, y = %i\n", x, y);
}