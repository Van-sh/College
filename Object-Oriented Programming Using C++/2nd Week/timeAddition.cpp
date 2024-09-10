// Create a class time with members hours, minutes and seconds. Take input and
// add two time objects and passing objects to function and display the result
#include <iostream>
using namespace std;

class Time {
  int hours, minutes, seconds;

public:
  void takeInput() {
    cout << "Enter hours minutes and seconds: ";
    cin >> hours >> minutes >> seconds;
  }
  void display() { printf("%02i:%02i:%02i", hours, minutes, seconds); }
  void add(Time t1, Time t2) {
    seconds = t1.seconds + t2.seconds;
    minutes = t1.minutes + t2.minutes + seconds / 60;
    hours = t1.hours + t2.hours + minutes / 60;
    seconds %= 60;
    minutes %= 60;
  }
};

int main() {
  Time t1, t2, t3;
  cout << "Time 1" << endl;
  t1.takeInput();
  cout << "Time 2" << endl;
  t2.takeInput();
  t3.add(t1, t2);
  cout << "Sum" << endl;
  t3.display();
  return 0;
}