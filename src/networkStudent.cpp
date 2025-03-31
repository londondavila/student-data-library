#include "networkStudent.h"

#include <iostream>
#include <string>

// default constructor
NetworkStudent::NetworkStudent()
    : Student("", "", "", "", "", NETWORKING,
              new int[DEFAULT_DAYS_ARRAY_SIZE]{0, 0, 0}) {}

// parameterized constructor
NetworkStudent::NetworkStudent(const std::string &StudentID,
                               const std::string &firstName,
                               const std::string &lastName,
                               const std::string &emailAddress,
                               const std::string &age,
                               [[maybe_unused]] Degree degreeType,
                               int *daysOfCourses)
    : Student(StudentID, firstName, lastName, emailAddress, age, degreeType,
              daysOfCourses) {}

// overriden methods
Degree NetworkStudent::getDegreeProgram() { return NETWORKING; }
void NetworkStudent::setDegreeType() { this->_degreeType = NETWORKING; }
void NetworkStudent::print() {
  this->Student::print();
  std::cout << "NETWORKING" << std::endl;
}

// destructor
NetworkStudent::~NetworkStudent() {}
