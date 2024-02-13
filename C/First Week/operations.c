#include <stdio.h>

void main()
{
    int a, b, sum, diff, mul, mod;
    float div;
    printf("Enter two numbers: ");
    scanf("%i %i", &a, &b);
    sum = a + b;
    diff = a - b;
    mul = a * b;
    div = (float)a / b;
    mod = a % b;
    printf("sum = %i\ndiff = %i\nmul = %i\ndiv = %f\nmod = %i\n", sum, diff, mul, div, mod);
}