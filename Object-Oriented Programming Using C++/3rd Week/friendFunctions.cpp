// 6. WAP using friend functionsto calculate the biggest
// of 2 numbers of two different classes
#include <cmath>
#include <iostream>
using namespace std;

class c1;
class c2;

class c1 {
  int x = 10;
  friend int compare(c1, c2);
};
class c2 {
  int x = 10;
  friend int compare(c1, c2);
};

int compare(c1 a, c2 b) { return (a.x >= b.x) ? a.x : b.x; }

int main() {
  c1 a;
  c2 b;
  cout << "The bigger number is: " << compare(a, b);
}