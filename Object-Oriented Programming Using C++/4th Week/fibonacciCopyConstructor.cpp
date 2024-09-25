// 9. Fibonacci series using copy constructor
#include <iostream>
using namespace std;

class Fibonacci {
public:
  int length, *series;
  Fibonacci(int n) : length(n) {
    series = new int[length];
    series[0] = 0;
    series[1] = 1;
    for (int i = 2; i < length; i++)
      series[i] = series[i - 1] + series[i - 2];
  }
  Fibonacci(Fibonacci &other) {
    length = other.length;
    series = new int[length];
    for (int i = 0; i < length; i++)
      series[i] = other.series[i];
  }
  ~Fibonacci() { delete[] series; }
  void print() {
    for (int i = 0; i < length; i++)
      cout << series[i] << " ";
    cout << endl;
  }
};

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  Fibonacci f1(n);
  f1.print();
  cout << "Copying to another object" << endl;
  Fibonacci f2(f1);
  f2.print();
}