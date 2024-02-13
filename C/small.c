#include <stdio.h>

void main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%i %i %i", &a, &b, &c);
    if (a < b && a < c)
    {
        printf("%i is the smallest\n", a);
    }
    else if (b <= a && b < c)
    {
        printf("%i is the smallest\n", b);
    }
    else
    {
        printf("%i is the smallest\n", c);
    }
}