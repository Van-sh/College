//  19. Find the sum, difference, product, quotient and remainder of 2 numbers using switch case
#include <stdio.h>

void main()
{
    int a, b, choice;
    printf("Enter two numbers: ");
    scanf("%i %i", &a, &b);
    printf("\tChoose Operation\n(1) Addition\n(2) Subtraction\n(3) Multiplication\n(4) Quotient\n(5) Remainder\n\nYour choice: ");
    scanf("%i", &choice);
    switch (choice)
    {
    case 1:
        printf("%i + %i = %i\n", a, b, a + b);
        break;
    case 2:
        printf("%i - %i = %i\n", a, b, a - b);
        break;
    case 3:
        printf("%i * %i = %i\n", a, b, a * b);
        break;
    case 4:
        printf("%i / %i = %i\n", a, b, (float)a / b);
        break;
    case 5:
        printf("%i %% %i = %i\n", a, b, a % b);
        break;
    default:
        printf("Not a valid operator\n");
        break;
    }
}
