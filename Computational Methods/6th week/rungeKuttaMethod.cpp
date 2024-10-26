#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// #define f(x, y) (x + y)

double f(double x, double y) { return (x + y); }

int main() {
  cout << fixed;
  cout.precision(2);
  cout << "Runge Kutta Method\n"
       << "******************" << endl;
  cout << "\ndy / dx = x + y\n";
  double x0, y0, xn, h;
  cout << "Enter initial condition (x0, y0): ";
  cin >> x0 >> y0;
  cout << "Enter the calculation point: ";
  cin >> xn;
  cout << "Enter the step size: ";
  cin >> h;
  double x = x0, y = y0;
  while (x < xn) {
    double k1 = h * f(x0, y);
    double k2 = h * f(x0 + h / 2, y + k1 / 2);
    double k3 = h * f(x0 + h / 2, y + k2 / 2);
    double k4 = h * f(x0 + h, y + k3);

    y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    x = x + h;
  }
  double result = y;
  cout << "The value of y at time " << xn << " is " << result << endl;
  return 0;
}
