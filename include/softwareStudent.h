#pragma once
#include "student.h"

class SoftwareStudent : public Student {
public:
  // constructor
  SoftwareStudent();
  // parameterized constructor
  SoftwareStudent(std::string StudentID, std::string firstName,
                  std::string lastName, std::string emailAddress,
                  std::string age, int *daysOfCourse, Degree dType);
  Degree getDegreeProgram();
  void setDegreeType(Degree d);
  void print();

  // destructor
  ~SoftwareStudent();
};
