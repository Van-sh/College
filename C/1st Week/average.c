// 4. Compute average of 3 numbers
#include <stdio.h>

void main()
{
    int a, b, c;
    float avg;
    printf("Enter three numbers: ");
    scanf("%i %i %i", &a, &b, &c);
    avg = (float)(a + b + c) / 3;
    printf("Average of %i, %i and %i is %.2f\n", a, b, c, avg);
}