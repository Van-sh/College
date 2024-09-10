// 1. Write a program for multiplication of two matrices using OOP
#include <iostream>
using namespace std;
class matrix {
public:
  int r, c;
  int m[100][100] = {{0}};
  void matrix_input() {
    cout << "enter the number of rows=";
    cin >> r;
    cout << "enter the number of columns=";
    cin >> c;
    cout << "enter the elements =" << endl;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << "enter the element at index (" << i << "," << j << ")=";
        cin >> m[i][j];
      }
    }
    cout << endl;
  }
  void matrix_output() {
    cout << "matrix=" << endl;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << m[i][j] << "\t";
      }
      cout << endl;
    }
  }
  void multiply(matrix m1, matrix m2) {
    if (m1.c != m2.r) {
      cout << "incorrect matrix dimension";
      return;
    }
    r = m1.r;
    c = m2.c;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        for (int k = 0; k < m1.c; k++) {
          m[i][j] += m1.m[i][k] * m2.m[k][j];
        }
      }
    }
  }
};
int main() {
  matrix m1, m2, m3;
  cout << "enter details of 1st matrix=" << endl;
  m1.matrix_input();
  m1.matrix_output();
  cout << "enter details of 1st matrix=" << endl;
  m2.matrix_input();
  m2.matrix_output();
  cout << "result of matrix multiplication=" << endl;
  m3.multiply(m1, m2);
  m3.matrix_output();
}