// 27. Print this pattern:
// 
// 1
// 22
// 333
// 4444
#include <stdio.h>

void main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%i", i);
        }
        printf("\n");
    }
}