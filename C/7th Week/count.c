// 41. Write a program to count vowels and consonants using pointers.
#include <stdio.h>

void countVowelsAndConsonants(char *str)
{
    int vowels = 0, consonants = 0;
    while (*str != '\0')
    {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||
            *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U')
        {
            vowels++;
        }
        else if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            consonants++;
        }
        str++;
    }
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
}

void main()
{
    char str[] = "Hello, World!";
    countVowelsAndConsonants(str);
}