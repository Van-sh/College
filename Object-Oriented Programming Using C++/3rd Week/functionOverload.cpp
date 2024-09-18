// 5. Using the concept of function overloading, write functions 
// to calculate the area of circle, rectangle and triangle
#include <cmath>
#include <iostream>
using namespace std;

double area(double radius) { return M_PI * pow(radius, 2); }

double area(double length, double width) { return length * width; }

double area(float base, double height) { return (base * height) / 2; }

int main() {
  double radius = 7, length = 5, width = 6, height = 4;
  float base = 3;
  cout << "Area of circle: " << area(radius) << endl
       << "Area of rectangle: " << area(length, width) << endl
       << "Area of triangle: " << area(base, height) << endl;
}