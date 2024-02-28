// 24. Print this pattern:
// 
// X
// XX
// XXX
// XXXX
#include <stdio.h>

void main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("X");
        }
        printf("\n");
    }
}