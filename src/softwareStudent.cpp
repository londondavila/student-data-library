#include "softwareStudent.h"

#include <iostream>
#include <string>

// default constructor
SoftwareStudent::SoftwareStudent()
    : Student("", "", "", "", "",
              new int[Student::getDefaultDaysArraySize()]{0, 0, 0}, SOFTWARE) {}

// parameterized constructor
SoftwareStudent::SoftwareStudent(const std::string &StudentID,
                                 const std::string &firstName,
                                 const std::string &lastName,
                                 const std::string &emailAddress,
                                 const std::string &age, int *daysOfCourses,
                                 Degree degreeType)
    : Student(StudentID, firstName, lastName, emailAddress, age, daysOfCourses,
              SOFTWARE) {}

// overriden methods
Degree SoftwareStudent::getDegreeProgram() { return SOFTWARE; }
void SoftwareStudent::print() {
  this->Student::print();
  std::cout << "SOFTWARE\n";
}

// destructor
SoftwareStudent::~SoftwareStudent() {}
