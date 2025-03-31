#include "securityStudent.h"

#include <iostream>
#include <string>

// default constructor - initialize with empty strings
SecurityStudent::SecurityStudent()
    : Student("", "", "", "", "", SECURITY,
              new int[DEFAULT_DAYS_ARRAY_SIZE]{0, 0, 0}) {}

// parameterized constructor
SecurityStudent::SecurityStudent(const std::string &StudentID,
                                 const std::string &firstName,
                                 const std::string &lastName,
                                 const std::string &emailAddress,
                                 const std::string &age,
                                 [[maybe_unused]] Degree degreeType,
                                 int *daysOfCourses)
    : Student(StudentID, firstName, lastName, emailAddress, age, SECURITY,
              daysOfCourses) {}

// overriden methods
Degree SecurityStudent::getDegreeProgram() { return SECURITY; }
void SecurityStudent::setDegreeType() { this->_degreeType = SECURITY; }
void SecurityStudent::print() {
  this->Student::print();
  std::cout << "SECURITY" << std::endl;
}

// superdestructor
SecurityStudent::~SecurityStudent() {}
