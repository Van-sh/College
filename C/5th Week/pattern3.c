// 25. Print this pattern:
// 
// XXXX
//  XXX
//   XX
//    X
#include <stdio.h>

void main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 5 - i; j++)
        {
            printf("X");
        }
        printf("\n");
    }
}