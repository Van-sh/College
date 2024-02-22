// 21. Find quadrant where x, y quadrant given by user are
#include <stdio.h>

void main()
{
    float x, y;
    printf("Enter x and y coordinates: ");
    scanf("%f %f", &x, &y);
    if (x > 0 && y > 0)
    {
        printf("First Quadrant\n");
    }
    else if (x < 0 && y > 0)
    {
        printf("Second Quadrant\n");
    }
    else if (x < 0 && y < 0)
    {
        printf("Third Quadrant\n");
    }
    else if (x > 0 && y < 0)
    {
        printf("Fourth Quadrant\n");
    }
}