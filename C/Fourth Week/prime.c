#include <stdio.h>

void main()
{
    int n, i = 2;
    printf("Enter number: ");
    scanf("%i", &n);
    while (1)
    {
        if (i <= (n + 1) / i)
        {
            if (n % i == 0)
            {
                printf("%i is a composite number\n", n);
                break;
            }
        }
        else
        {
            printf("%i is a prime number\n", n);
            break;
        }
        i++;
    }
}