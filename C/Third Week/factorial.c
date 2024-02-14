#include <stdio.h>

void main()
{
    int n, fact = 1;
    printf("Enter number: ");
    scanf("%i", &n);
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    printf("Factorial of %i is %i\n", n, fact);
}