// 33. Write a menu-driven program to do the following operations depending on whether the operation requires 1 or 2 matrices:
// 1. Addition
// 2. Subtraction
// 3. Find Upper and Lower triangular matrices
// 4. Transpose
// 5. Product
#include <stdio.h>

void main()
{
    int choice;
    int matrix1[3][3];
    int matrix2[3][3];
    int matrix3[3][3];
    while (1)
    {
        printf("\tMENU\n1. Addition\n2. Subtraction\n3. Find Upper And Lower Trangular Matrices\n4. Transpose\n5. Product\n0. Close\n\nYour Choice: ");
        scanf("%i", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < 3; i++)
            {
                printf("Enter elements of first row for first matrix: ");
                scanf("%i %i %i", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
            }
            for (int i = 0; i < 3; i++)
            {
                printf("Enter elements of first row for second matrix: ");
                scanf("%i %i %i", &matrix2[i][0], &matrix2[i][1], &matrix2[i][2]);
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            printf("Result is:\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%i\t", matrix3[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            for (int i = 0; i < 3; i++)
            {
                printf("Enter elements of first row for first matrix: ");
                scanf("%i %i %i", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
            }
            for (int i = 0; i < 3; i++)
            {
                printf("Enter elements of first row for second matrix: ");
                scanf("%i %i %i", &matrix2[i][0], &matrix2[i][1], &matrix2[i][2]);
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            printf("Result is:\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%i\t", matrix3[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            for (int i = 0; i < 3; i++)
            {
                printf("Enter elements of first row: ");
                scanf("%i %i %i", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrix2[i][j] = matrix1[i][j];
                    matrix3[i][j] = matrix1[i][j];
                    if (i > j)
                    {
                        matrix2[i][j] = 0;
                    }
                    else if (i < j)
                    {
                        matrix3[i][j] = 0;
                    }
                }
            }
            printf("Upper Triangular Matrix is:\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%i\t", matrix2[i][j]);
                }
                printf("\n");
            }
            printf("Lower Triangular Matrix is:\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%i\t", matrix3[i][j]);
                }
                printf("\n");
            }
            break;
        case 4:
            for (int i = 0; i < 3; i++)
            {
                printf("Enter elements of first row: ");
                scanf("%i %i %i", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrix2[i][j] = matrix1[j][i];
                }
            }
            printf("Transpose of the Matrix is:\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%i\t", matrix2[i][j]);
                }
                printf("\n");
            }
            break;
        case 5:
            for (int i = 0; i < 3; i++)
            {
                printf("Enter elements of first row for first matrix: ");
                scanf("%i %i %i", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
            }
            for (int i = 0; i < 3; i++)
            {
                printf("Enter elements of first row for second matrix: ");
                scanf("%i %i %i", &matrix2[i][0], &matrix2[i][1], &matrix2[i][2]);
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrix3[i][j] = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            printf("Result is:\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%i\t", matrix3[i][j]);
                }
                printf("\n");
            }
            break;
        case 0:
            printf("Closing...\n");
            return;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}