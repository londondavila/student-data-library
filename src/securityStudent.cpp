#include "securityStudent.h"
#include <iostream>

// default constructor
SecurityStudent::SecurityStudent() { setDegreeType(SECURITY); }

// parameterized constructor
SecurityStudent::SecurityStudent(std::string StudentID, std::string firstName,
                                 std::string lastName, std::string emailAddress,
                                 std::string age, int *daysOfCourses,
                                 Degree degreeType) {
  setDegreeType(SECURITY);
}

// overriden methods
Degree SecurityStudent::getDegreeProgram() { return SECURITY; }
void SecurityStudent::setDegreeType(Degree d) { this->degreeType = SECURITY; }
void SecurityStudent::print() {
  this->Student::print();
  std::cout << "SECURITY\n";
}

// superdestructor
SecurityStudent::~SecurityStudent() {}
