#include "networkStudent.h"
#include <iostream>

// default constructor
NetworkStudent::NetworkStudent() { setDegreeType(NETWORKING); }

// parameterized constructor
NetworkStudent::NetworkStudent(std::string StudentID, std::string firstName,
                               std::string lastName, std::string emailAddress,
                               std::string age, int *daysOfCourses,
                               Degree degreeType) {
  setDegreeType(NETWORKING);
}

// overriden methods
Degree NetworkStudent::getDegreeProgram() { return NETWORKING; }
void NetworkStudent::setDegreeType(Degree d) { this->degreeType = NETWORKING; }
void NetworkStudent::print() {
  this->Student::print();
  std::cout << "NETWORKING\n";
}

// destructor
NetworkStudent::~NetworkStudent() {}
