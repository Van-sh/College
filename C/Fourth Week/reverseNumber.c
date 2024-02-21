#include <stdio.h>

void main()
{
    int n, tmp, rev = 0;
    printf("Enter number to be reversed: ");
    scanf("%i", &n);
    tmp = n;
    while (tmp != 0)
    {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    printf("Reverse of %i is %i\n", n, rev);
}