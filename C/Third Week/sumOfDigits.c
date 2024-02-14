#include <stdio.h>

void main()
{
    int n, sum = 0;
    printf("Enter number: ");
    scanf("%i", &n);
    int tmp = n;
    while (tmp != 0)
    {
        sum += tmp % 10;
        tmp /= 10;
    }
    printf("Sum of digits of %i is %i\n", n, sum);
}