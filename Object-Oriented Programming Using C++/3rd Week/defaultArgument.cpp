// 7. Write a fumction power to raise a number m to power n. The function takes a double value for m and
// int value for n. Use default value for n to make the ålnction to calculate squares when this argument
// is omitted.
#include <iostream>
using namespace std;

double power(double m, int n = 2) {
  if (n == 0)
    return 1;
  return m * power(m, n - 1);
}

int main() {
  cout << "Only passing m: " << power(10) << endl
       << "Passing both m and n: " << power(10, 3) << endl;
  return 0;
}