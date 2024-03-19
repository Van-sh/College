// 40. Write a program without using string functions to perform the following operations on string:
// 1. Find length of the string
// 2. To concatenate 2 strings
// 3. To find the reverse of a string
// 4. To copy 1 string into another string
#include <stdio.h>

void calculateStringLength(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    printf("Length of the string: %i\n", len);
}

void concatenateStrings(char str1[], char str2[], char result[])
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        result[j] = str1[i];
        i++;
        j++;
    }
    i = 0;
    while (str2[i] != '\0')
    {
        result[j] = str2[i];
        i++;
        j++;
    }
    result[j] = '\0';
    printf("Concatenated string: %s\n", result);
}

void reverseString(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void copyString(char source[], char destination[])
{
    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    printf("Copied string: %s\n", destination);
}

void main()
{
    char str1[100], str2[100], result[200], copy[100];
    int choice;
    while (1)
    {
        printf("\n1. Calculate String Length\n2. Concatenate Strings\n3. Reverse a String\n4. Copy a String\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%i%*c", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a string: ");
            scanf("%[^\n]s%*c", str1);
            calculateStringLength(str1);
            break;
        case 2:
            printf("Enter first string: ");
            scanf("%[^\n]s%*c", str1);
            printf("Enter second string: ");
            scanf("\n%[^\n]s%*c", str2);
            concatenateStrings(str1, str2, result);
            break;
        case 3:
            printf("Enter a string to reverse: ");
            scanf("%[^\n]s%*c", str1);
            reverseString(str1);
            break;
        case 4:
            printf("Enter a string to copy: ");
            scanf("%[^\n]s%*c", str1);
            copyString(str1, copy);
            break;
        case 5:
            return;
        default:
            printf("Invalid choice!\n");
        }
    }
}