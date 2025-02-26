#include "teaching_assistant.h"
#include <iostream>

int main(int argc, char* argv[ ]) {
   // Part 1------------------------------------------------
   Student s = Student(2.9, "Sam");
   // std::cout << "Name = " << s.getName() << " GPA = " << s.getGPA() << std::endl;

   Person p = Person("RIC");
   p.print(); // step1: "RIC" | step2: "RIC"
   s.print(); // step1: "Sam" | step2: "Sam 2.9"

   // Step3: if print function is not there for Person class, it will cause compiler error

   // Part 2------------------------------------------------
   // Person *personPtr = &s; // L1
   // Student *studentPtr = &p; // L2
   // 1. compiler error
   // 2. compiler error
   // 3. works
   // 4. L2 is problem since it is assigning person class(higher) to student class(lower)
   //    it causes a problem

   // Part 3-------------------------------------------------
   Person *personPtr = &s;
   Student *studentPtr = &s;

   personPtr -> print();  //step1: Sam     | step2: Sam 2.9
   studentPtr -> print(); //step1: Sam 2.9 | step2: Sam 2.9

   // Part 5-------------------------------------------------
   TeachingAssistant ta1 = TeachingAssistant(3.8, "Julie", "OO Programming");
   ta1.print(); // out: Julie 3.8 OO Programming

   Person* collection[] = {&p, &s, &ta1};
   for (size_t i = 0; i < 3; i++) {
      collection[i] -> print();
   }

   // without virtural it will print name only (use Person print function)
   // if virtual is used but print function is not there for Teaching Assistant it will call student print()

   // Part 6-------------------------------------------------
   // CASE1: Assume print() is defined as virtual in all classes. No other functions are virtual.
      // Person            -> VFT |pointer to Person::print()|
      // Student           -> VFT |pointer to Student::print()|
      // TeachingAssistant -> VFT |pointer to TeachingAssistant::print()|

   // CASE2: Assume print() and all functions (which are not constructors) are defined as virtual for all classes.
      // Person            -> VFT |pointer to Person::print(),
      //                           pointer to Person::getName()|
   
      // Student           -> VFT |pointer to Student::print(),
      //                           pointer to Person::getName(),
      //                           pointer to Student::getGPA()|

      // TeachingAssistant -> VFT |pointer to TeachingAssistant::print()
      //                           pointer to Person::getName(),
      //                           pointer to Student::getGPA()|
}

