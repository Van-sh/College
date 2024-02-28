// 30. Check if a number is a palindrome
#include <stdio.h>

void main()
{
    int n, tmp, rev = 0;
    printf("Enter a number: ");
    scanf("%i", &n);
    tmp = n;
    while (tmp != 0)
    {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    if (rev == n)
    {
        printf("%i is a palindrome.\n", n);
    }
    else
    {
        printf("%i is not a palindrome.\n", n);
    }
}