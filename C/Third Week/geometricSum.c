#include <stdio.h>
#include <math.h>

void main()
{
    int a, r, n, sum = 0;
    printf("Enter a, r and n: ");
    scanf("%i %i %i", &a, &r, &n);
    for (int i = 0; i < n; i++)
    {
        sum += a * pow(r, i);
    }
    printf("Sum of %i numbers of this geometric series is %i\n", n, sum);
}