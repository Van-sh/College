// 36. Write a program to find the diameter, circumference and area of a circle using functions
#include <stdio.h>

float diameter(float r)
{
    return 2 * r;
}

float circumference(float r)
{
    return 2 * 3.14 * r;
}

float area(float r)
{
    return 3.14 * r * r;
}

void main()
{
    float r;
    printf("Enter radius: ");
    scanf("%f", &r);
    printf("Diameter: %.2f\nCircumference: %.2f\nArea: %.2f\n", diameter(r), circumference(r), area(r));
}