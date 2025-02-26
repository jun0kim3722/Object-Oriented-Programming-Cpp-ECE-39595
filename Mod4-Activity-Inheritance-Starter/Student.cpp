#include <string>
#include "Student.h"

Student::Student(float _gpa, std::string name): Person(name)  {
   gpa = _gpa;
}

float Student::getGPA( ) {
   return gpa;
}

void Student::print() {
   std::string name = this->getName();
   std::cout << name << " " << gpa << std::endl;
}