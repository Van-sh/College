// 4. Write a program to perform addition of two complex numbers using
// constructor overloading. The first constructor which takes no argument is
// used to create objects which are not initialized, second which takes one
// argument is used to initialize real and imag parts to equal values and third
// which takes two argument is used to initialized real and imag to two
// different values.
#include <iostream>
using namespace std;

class Complex {
  float real = 0, imag = 0;

public:
  Complex() {}
  Complex(float num) { real = imag = num; }
  Complex(float num1, float num2) { real = num1, imag = num2; }
  void display() { cout << real << " + " << imag << "j" << endl; }
  void add(Complex c1, Complex c2) {
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
  }
};

int main() {
  Complex c1(1.1, 2.2), c2(3.3), c3, c4;
  c3.add(c1, c4);
  c4.add(c2, c3);
  c1.display();
  c2.display();
  c3.display();
  c4.display();
}