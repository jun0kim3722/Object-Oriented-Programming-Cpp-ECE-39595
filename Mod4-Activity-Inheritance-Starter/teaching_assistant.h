#include <string>
#include "Student.h"

class TeachingAssistant : public Student {

private:
    std::string _course;


public:
    TeachingAssistant(float gpa, std::string name, std::string course) : Student(gpa, name) {
        _course = course;
    };

    void print() {
        std::string name = this->getName();
        float gpa = this->getGPA();

        std::cout << name << " " << gpa << " " << _course << std::endl;
    };
};