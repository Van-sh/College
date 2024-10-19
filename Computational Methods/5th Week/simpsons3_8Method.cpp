#include <cmath>
#include <iostream>
using namespace std;

#define f(x) (1 / (1 + pow(x, 2)))

int main() {
  int n;
  double a, b, h, result = 0;
  cout << "Simpson's 3/8 Formula\n"
       << "*********************" << endl;
  cout << "Enter the limits of the function: ";
  cin >> a >> b;
  cout << "Enter number of intervals: ";
  cin >> n;
  if (n % 3) {
    cout << "Number of intervals should be a multiple of 3" << endl;
    return 1;
  }
  h = (b - a) / n;
  result += f(a) + f(b);
  for (int i = 1; i < n; i++) {
    result += ((i % 3) ? 3 : 2) * f(a + i * h);
  }
  result *= 3 * h / 8;
  cout << "The result is: " << result << endl;
  return 0;
}
