// 3. Calculate Simple Interest
#include <stdio.h>

void main()
{
    int P, T;
    float R, SI;
    printf("Enter Principal, Rate of Interest and Time: ");
    scanf("%i %f %i", &P, &R, &T);
    SI = (P * R * T) / 100;
    printf("Simple Interest = %.2f\n", SI);
}