#include <stdio.h>

void main()
{
    char a, d;
    int b, c;
    printf("Enter a character: ");
    scanf("%c", &a);
    b = a;
    printf("ASCII value of %c is %i\n", a, b);
    printf("Enter an ASCII value: ");
    scanf("%i", &c);
    d = c;
    printf("Character with the ASCII value of %i is %c\n", c, d);
}