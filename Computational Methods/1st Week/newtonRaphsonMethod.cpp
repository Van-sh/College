// 2. Program for finding roots of f(x)=0 by Newton Raphson method
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define f(x) (cos(x) - 3 * x + 1)
#define df(x) (-sin(x) - 3)

int main() {
  double x, xNew, f, df, e;
  int step = 1;
  cout << setprecision(6) << fixed;
  cout << "Enter Guess: ";
  cin >> x;
  xNew = x;
  cout << "Enter Tolerable Error: ";
  cin >> e;
  cout << endl << "*********************" << endl;
  cout << "Newton Raphson Method" << endl;
  cout << "*********************" << endl;
  do {
    x = xNew;
    f = f(x);
    df = df(x);
    cout << "Iteration-" << step << ":\tx=" << setw(10) << x
         << " and f(x)=" << setw(10) << f(x) << endl;

    xNew = x - f / df;
    step++;

  } while (fabs(f) > e);
  cout << endl << "Root is: " << setprecision(3) << x << endl;
  return 0;
}