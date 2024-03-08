// 32. Write a recursive program to generate fibonacci series
#include <stdio.h>

int fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    return fib(n - 2) + fib(n - 1);
}

void main()
{
    int n;
    printf("Enter number of elements ot be generated: ");
    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("%i\n", fib(i));
    }
}