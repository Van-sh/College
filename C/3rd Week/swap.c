// 14. Swap two numbers without using third variable
#include <stdio.h>

void main()
{
    int a = 2, b = 3;
    printf("Before swap:\na = %i\nb = %i\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swap:\na = %i\nb = %i\n", a, b);
}