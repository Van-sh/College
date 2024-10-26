#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define n 3

void printMatrix(vector<vector<double>> &matrix) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << "\n";
  }
  cout << endl;
}

void gaussJordan(vector<vector<double>> &matrix) {
  for (int i = 0; i < n; i++) {
    double pivot = matrix[i][i];
    for (int j = 0; j < 2 * n; j++) {
      matrix[i][j] /= pivot;
    }
    for (int k = 0; k < n; k++) {
      if (k != i) {
        double factor = matrix[k][i];
        for (int j = 0; j < 2 * n; j++) {
          matrix[k][j] = matrix[k][j] - factor * matrix[i][j];
        }
      }
    }
  }
}

int main() {
  cout << fixed;
  cout.precision(2);
  cout << "Gauss Jordan Elimination Method\n"
       << "*******************************" << endl;
  vector<vector<double>> matrix(n, vector<double>(2 * n, 0));
  for (int i = 0; i < n; i++) {
    cout << "Enter elements of row " << i + 1 << ": ";
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = n; j < 2 * n; j++) {
      matrix[i][j] = (i == j - n) ? 1 : 0;
    }
  }
  cout << "Augmented matrix (A:I) before Gauss Jordan Elimination:\n";
  printMatrix(matrix);
  gaussJordan(matrix);
  cout << "Augmented matrix after Gauss Jordan Elimination:\n";
  printMatrix(matrix);
  return 0;
}
