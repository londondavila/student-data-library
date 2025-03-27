#include "networkStudent.h"

#include <iostream>
#include <string>

// default constructor
NetworkStudent::NetworkStudent()
    : Student("", "", "", "", "",
              new int[Student::getDefaultDaysArraySize()]{0, 0, 0},
              NETWORKING) {}

// parameterized constructor
NetworkStudent::NetworkStudent(const std::string &StudentID,
                               const std::string &firstName,
                               const std::string &lastName,
                               const std::string &emailAddress,
                               const std::string &age, int *daysOfCourses,
                               Degree degreeType)
    : Student(StudentID, firstName, lastName, emailAddress, age, daysOfCourses,
              NETWORKING) {}

// overriden methods
Degree NetworkStudent::getDegreeProgram() { return NETWORKING; }
void NetworkStudent::print() {
  this->Student::print();
  std::cout << "NETWORKING" << std::endl;
}

// destructor
NetworkStudent::~NetworkStudent() {}
