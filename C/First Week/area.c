#include <stdio.h>

void main()
{
    int r, l, b, r_area;
    float c_area;
    printf("Enter radius of circle: ");
    scanf("%i", &r);
    c_area = 3.14 * r * r;
    printf("Area of circle is %f\n", c_area);
    printf("Enter length and breadth of rectangle: ");
    scanf("%i %i", &l, &b);
    r_area = l * b;
    printf("Area of rectangle is %i\n", r_area);
}