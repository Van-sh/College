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
}