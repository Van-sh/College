// 20. Check if a char given by the user is vowel or consonant using switch case
#include <stdio.h>

void main()
{
    char ch;
    printf("Enter character: ");
    scanf("%c", &ch);
    switch (ch)
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
        printf("Vowel\n");
        break;
    default:
        printf("Consonant\n");
        break;
    }
}
