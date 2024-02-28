// 23. Print this pattern:
// 
// XXXX
// XXXX
// XXXX
// XXXX
#include <stdio.h>

void main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            printf("X");
        }
        printf("\n");
    }
}