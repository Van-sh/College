// 8. Print factorial of a number using constructor
#include <iostream>
using namespace std;

class Factorial {
public:
  int num, fact;
  Factorial(int n) {
    num = n;
    fact = 1;
    for (int i = 1; i <= n; i++)
      fact *= i;
  }
};

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  Factorial f(n);
  cout << "Factorial of " << f.num << " is " << f.fact << endl;
}