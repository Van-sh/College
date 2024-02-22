// 8. Check whether number is positive, negative or zero
#include <stdio.h>

void main()
{
    int n;
    printf("Enter number: ");
    scanf("%i", &n);
    if (n > 0)
    {
        printf("%i is positive\n", n);
    }
    else if (n < 0)
    {
        printf("%i is negative\n", n);
    }
    else
    {
        printf("%i is zero\n", n);
    }
}