// 28. Print this pattern:
// 
//    1
//   121
//  12321
// 1234321
#include <stdio.h>

void main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4 - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%i", j);
        }
        for (int j = i - 1; j >= 1; j--)
        {
            printf("%i", j);
        }
        printf("\n");
    }
}