// Find a number given by the user is odd or even
#include <stdio.h>

void main()
{
    int n;
    printf("Enter number: ");
    scanf("%i", &n);
    if (n % 2 == 0)
    {
        printf("%i is even\n", n);
    }
    else
    {
        printf("%i is odd\n", n);
    }
}