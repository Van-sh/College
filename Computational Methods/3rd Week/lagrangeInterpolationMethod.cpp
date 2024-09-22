// 4. To implement Lagrange's Interpolation formula and find Interpolated values
// at a given point and also find interpolated polynomial
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cout << "Lagrange's Interpolation Method" << endl
       << "*******************************" << endl;
  cout << "Enter the number of points: ";
  cin >> n;
  vector<double> x(n, 0), y(n, 0);
  double xi, result = 0;
  for (int i = 0; i < n; i++) {
    cout << "Enter x and y for point " << i << ": ";
    cin >> x[i] >> y[i];
  }
  cout << endl << "Langrange's Polynomial P(x) = ";
  for (int i = 0; i < n; i++) {
    cout << y[i];
    for (int j = 0; j < n; j++) {
      if (j != i) {
        cout << " * (x - " << x[j] << ") / (" << x[i] << " - " << x[j] << ")";
      }
    }
    (i == n - 1) ? cout << endl << endl : cout << " + ";
  }
  cout << "Enter the value of x for which the interpolated value is to be found: ";
  cin >> xi;
  for (int i = 0; i < n; i++) {
    double term = y[i];
    for (int j = 0; j < n; j++) {
      if (j != i) {
        term *= (xi - x[j]) / (x[i] - x[j]);
      }
    }
    result += term;
  }
  cout << "The interpolated value at x = " << xi << " is " << result << endl;
}