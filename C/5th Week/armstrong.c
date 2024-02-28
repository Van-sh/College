// 29. Check if a number is an armstrong number
#include <stdio.h>
#include <math.h>

void main()
{
    int n, tmp, sum = 0;
    printf("Enter a number: ");
    scanf("%i", &n);
    tmp = n;
    while (tmp != 0)
    {
        sum += pow(tmp % 10, 3);
        tmp /= 10;
    }
    if (sum == n)
    {
        printf("%i is an Armstrong number.\n", n);
    }
    else
    {
        printf("%i is not an Armstrong number.\n", n);
    }
}