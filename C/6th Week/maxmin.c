// 37. Write a program to find max and min of 2 numbers using functions
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}

void main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%i %i", &a, &b);
    printf("Max: %i\nMin: %i\n", max(a, b), min(a, b));
}
