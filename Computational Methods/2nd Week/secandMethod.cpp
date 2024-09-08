// 2. Program for finding roots of f(x)=0 by secant method
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
#define f(x) pow(x, 3) - 4 * x - 9

int main() {
  double x0, x1, x2, f0, f1, e;
  int step = 1, maxitr;
  cout << setprecision(6) << fixed;
  cout << "Enter first guess: ";
  cin >> x0;
  cout << "Enter second guess: ";
  cin >> x1;
  cout << "Enter tolerable error: ";
  cin >> e;
  cout << "Enter maximum iterations: ";
  cin >> maxitr;
  cout << endl << "*************" << endl;
  cout << "Secant Method" << endl;
  cout << "*************" << endl;
  do {
    f0 = f(x0);
    f1 = f(x1);
    x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
    cout << "Iteration-" << step << ":\t x =" << setw(10) << x2
         << " and f(x) =" << setw(10) << f(x2) << endl;
    x0 = x1;
    x1 = x2;
    step++;
  } while (step <= maxitr && fabs(f1) > e);
  cout << endl << "Root is: " << setprecision(3) << x2 << endl;
  return 0;
}