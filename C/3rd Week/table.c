// 15. Calculate table of a number given by the user
#include <stdio.h>

void main()
{
    int n;
    printf("Enter number: ");
    scanf("%i", &n);
    for (int i = 1; i <= 10; i++)
    {
        int num = n * i;
        printf("%i x %i = %i\n", n, i, num);
    }
}