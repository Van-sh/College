#include <stdio.h>
#define MAX 10
int isSparse(int matrix[MAX][MAX], int rows, int cols) {
  int zeroCount = 0;
  int totalElements = rows * cols;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0)
        zeroCount++;
    }
  }
  return (zeroCount > totalElements / 2);
}
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX],
                 int result[MAX][MAX], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}
void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX],
                      int result[MAX][MAX], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%i ", matrix[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int rows, cols;
  int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
  printf("Enter number of rows and columns for the matrix: ");
  scanf("%i %i", &rows, &cols);
  printf("Enter elements of the matrix:\n");
  for (int i = 0; i < rows; i++) {
    printf("Enter row %i of matrix: ", i + 1);
    for (int j = 0; j < cols; j++) {
      scanf("%i", &matrix1[i][j]);
    }
  }
  if (isSparse(matrix1, rows, cols)) {
    printf("The matrix is sparse.\n");
    printf("Enter elements of another matrix for addition/subtraction:\n");
    for (int i = 0; i < rows; i++) {
      printf("Enter row %i of matrix: ", i + 1);
      for (int j = 0; j < cols; j++) {
        scanf("%i", &matrix2[i][j]);
      }
    }
    displayMatrix(matrix1, rows, cols);
    displayMatrix(matrix2, rows, cols);
    addMatrices(matrix1, matrix2, result, rows, cols);
    printf("Result of matrix addition:\n");
    displayMatrix(result, rows, cols);
    subtractMatrices(matrix1, matrix2, result, rows, cols);
    printf("Result of matrix subtraction:\n");
    displayMatrix(result, rows, cols);
  } else {
    printf("The matrix is not sparse.\n");
  }
  return 0;
}