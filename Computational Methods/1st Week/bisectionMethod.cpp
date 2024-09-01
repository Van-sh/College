// 1. Program for finding roots of f(x)=0 by bisection method
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
#define f(x) (cos(x) - 3 * x + 1)

int main() {
  double x0, x1, x, f0, f1, f, e;
  int step = 1;
  cout << setprecision(6) << fixed;
input:
  cout << "Enter first guess: ";
  cin >> x0;
  cout << "Enter second guess: ";
  cin >> x1;
  cout << "Enter tolerable error: ";
  cin >> e;
  f0 = f(x0);
  f1 = f(x1);
  if (f0 * f1 > 0.0)

  {
    cout << "Incorrect Initial Guesses." << endl;
    goto input;
  }
  cout << endl << "****************" << endl;
  cout << "Bisection Method" << endl;
  cout << "****************" << endl;
  do {
    x = (x0 + x1) / 2;
    f = f(x);
    cout << "Iteration-" << step << ":\t x =" << setw(10) << x
         << " and f(x) =" << setw(10) << f(x) << endl;
    if (f0 * f < 0) {
      x1 = x;
    } else {
      x0 = x;
    }
    step++;
  } while (fabs(f) > e);
  cout << endl << "Root is: " << setprecision(3) << x << endl;
  return 0;
}