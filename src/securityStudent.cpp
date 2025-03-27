#include "securityStudent.h"

#include <iostream>
#include <string>

// default constructor - initialize with empty strings
SecurityStudent::SecurityStudent()
    : Student("", "", "", "", "",
              new int[Student::getDefaultDaysArraySize()]{0, 0, 0}, SECURITY) {}

// parameterized constructor
SecurityStudent::SecurityStudent(const std::string &StudentID,
                                 const std::string &firstName,
                                 const std::string &lastName,
                                 const std::string &emailAddress,
                                 const std::string &age, int *daysOfCourses,
                                 Degree degreeType)
    : Student(StudentID, firstName, lastName, emailAddress, age, daysOfCourses,
              SECURITY) {}

// overriden methods
Degree SecurityStudent::getDegreeProgram() { return SECURITY; }
void SecurityStudent::print() {
  this->Student::print();
  std::cout << "SECURITY" << std::endl;
}

// superdestructor
SecurityStudent::~SecurityStudent() {}
