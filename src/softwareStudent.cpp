#include "softwareStudent.h"

#include <iostream>
#include <string>

// default constructor
SoftwareStudent::SoftwareStudent()
    : Student("", "", "", "", "", SOFTWARE,
              new int[DEFAULT_DAYS_ARRAY_SIZE]{0, 0, 0}) {}

// parameterized constructor
SoftwareStudent::SoftwareStudent(const std::string &StudentID,
                                 const std::string &firstName,
                                 const std::string &lastName,
                                 const std::string &emailAddress,
                                 const std::string &age,
                                 [[maybe_unused]] Degree degreeType,
                                 int *daysOfCourses)
    : Student(StudentID, firstName, lastName, emailAddress, age, SOFTWARE,
              daysOfCourses) {}

// overriden methods
Degree SoftwareStudent::getDegreeProgram() { return SOFTWARE; }
void SoftwareStudent::setDegreeType() { this->_degreeType = SOFTWARE; }
void SoftwareStudent::print() {
  this->Student::print();
  std::cout << "SOFTWARE" << std::endl;
}

// destructor
SoftwareStudent::~SoftwareStudent() {}
