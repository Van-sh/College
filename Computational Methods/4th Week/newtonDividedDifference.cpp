// 4. To implement Newton’s Divided Difference formula and
// find Interpolated values at a given point.
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cout << "Newton's Divided Difference Interpolation Method" << endl
       << "************************************************" << endl;
  cout << "Enter the number of points: ";
  cin >> n;
  vector<double> x(n, 0), y(n, 0);
  double xi, result = 0;
  for (int i = 0; i < n; i++) {
    cout << "Enter x and y for point " << i << ": ";
    cin >> x[i] >> y[i];
  }
  vector<vector<double>> table(n, vector<double>(n, 0));
  for (int i = 0; i < n; i++) {
    table[i][0] = y[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      table[i][j] = (table[i][j - 1] - table[i - 1][j - 1]) / (x[i] - x[i - j]);
    }
  }
  cout << "Enter the value of x for which the interpolated value is to be "
          "found: ";
  cin >> xi;
  result = table[0][0];
  for (int i = 1; i < n; i++) {
    double term = table[i][i];
    for (int j = 0; j < i; j++) {
      term *= (xi - x[j]);
    }
    result += term;
  }
  cout << "The interpolated value at x = " << xi << " is " << result << endl;
}