#include "softwareStudent.h"
#include <iostream>

// default constructor
SoftwareStudent::SoftwareStudent() { setDegreeType(SOFTWARE); }

// parameterized constructor
SoftwareStudent::SoftwareStudent(std::string StudentID, std::string firstName,
                                 std::string lastName, std::string emailAddress,
                                 std::string age, int *daysOfCourses,
                                 Degree degreeType) {
  setDegreeType(SOFTWARE);
}

// overriden methods
Degree SoftwareStudent::getDegreeProgram() { return SOFTWARE; }
void SoftwareStudent::setDegreeType(Degree d) { this->degreeType = SOFTWARE; }
void SoftwareStudent::print() {
  this->Student::print();
  std::cout << "SOFTWARE\n";
}

// destructor
SoftwareStudent::~SoftwareStudent() {}