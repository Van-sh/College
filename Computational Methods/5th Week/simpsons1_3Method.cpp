#include <cmath>
#include <iostream>
using namespace std;

#define f(x) (1 / (1 + pow(x, 2)))

int main() {
  int n;
  double a, b, h, result = 0;
  cout << "Simpson's 1/3 Formula\n"
       << "*********************" << endl;
  cout << "Enter the limits of the function: ";
  cin >> a >> b;
  cout << "Enter number of intervals: ";
  cin >> n;
  if (n % 2) {
    cout << "Enter an even number of intervals" << endl;
    return 1;
  }
  h = (b - a) / n;
  result += f(a) + f(b);
  for (int i = 1; i < n; i++) {
    result += ((i % 2) ? 4 : 2) * f(a + i * h);
  }
  result *= h / 3;
  cout << "The result is: " << result << endl;
  return 0;
}
