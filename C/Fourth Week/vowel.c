#include <stdio.h>

void main()
{
    char ch;
    printf("Enter character: ");
    scanf("%c", &ch);
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("Vowel\n");
        break;
    default:
        printf("Consonant\n");
        break;
    }
}