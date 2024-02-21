#include <stdio.h>

void main()
{
    char ch;
    printf("Enter character: ");
    scanf("%c", &ch);
    switch (ch)
    {
    case 'a':
        printf("Vowel\n");
        break;
    case 'e':
        printf("Vowel\n");
        break;
    case 'i':
        printf("Vowel\n");
        break;
    case 'o':
        printf("Vowel\n");
        break;
    case 'u':
        printf("Vowel\n");
        break;
    default:
        printf("Consonant\n");
        break;
    }
}