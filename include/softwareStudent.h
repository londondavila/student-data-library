#pragma once
#include "student.h"

class SoftwareStudent : public Student {
public:
  // constructor
  SoftwareStudent();
  // parameterized constructor
  SoftwareStudent(const std::string &StudentID, const std::string &firstName,
                  const std::string &lastName, const std::string &emailAddress,
                  const std::string &age, int *daysOfCourse, Degree dType);
  Degree getDegreeProgram() override;
  void setDegreeType(Degree d) override; // pure virtual function
  void print() override;

  // destructor
  ~SoftwareStudent();
};
