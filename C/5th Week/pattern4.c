// 26. Print this pattern:
// 
// 1
// 12
// 123
// 1234
#include <stdio.h>

void main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%i", j);
        }
        printf("\n");
    }
}