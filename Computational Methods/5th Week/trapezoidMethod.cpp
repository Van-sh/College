#include <cmath>
#include <iostream>
using namespace std;

#define f(x) (1 / (1 + pow(x, 2)))

int main() {
  int n;
  double a, b, h, result = 0;
  cout << "Trapezoid Formula\n"
       << "*****************" << endl;
  cout << "Enter the limits of the function: ";
  cin >> a >> b;
  cout << "Enter number of intervals: ";
  cin >> n;
  h = (b - a) / n;
  result += f(a) + f(b);
  for (int i = 1; i < n; i++) {
    result += 2 * f(a + i * h);
  }
  result *= h / 2;
  cout << "The result is: " << result << endl;
  return 0;
}
