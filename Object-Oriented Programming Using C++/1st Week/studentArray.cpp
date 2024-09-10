// 2. Create a class student which has data members as name, branch, age, sex, marks, roll no, in 5 subjects. Display the name of the student and percentage who has scored more than 70% marks using array of object.
#include <iostream>
#include <string>
using namespace std;

class Student {
  string Name;
  string roll_no;
  string branch;
  int age;
  char sex;
  int marks;
  int per;

public:
  void get();
  void display();
  double getper() { return per; }
};

void Student::get() {
  cout << "Enter Name: ";
  cin >> Name;
  cout << "roll_no: ";
  cin >> roll_no;
  cout << "branch: ";
  cin >> branch;
  cout << "Enter age: ";
  cin >> age;
  cout << "Enter sex: ";
  cin >> sex;
  cout << "Enter marks: ";
  cin >> marks;
  per = marks / 5;
  cout << endl;
}

void Student::display() {
  cout << "Name: " << Name << endl;
  cout << "Percentage: " << per << endl;
  cout << endl;
}

int main() {
  Student s[5];
  for (int i = 0; i < 5; i++) {
    s[i].get();
  }

  cout << "Details of students above 70 percent" << endl;
  for (int i = 0; i < 5; i++) {
    if (s[i].getper() > 70) {
      s[i].display();
    }
  }
}
