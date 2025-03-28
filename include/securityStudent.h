#pragma once
#include "student.h"

class SecurityStudent : public Student {
public:
  // constructor
  SecurityStudent();
  // parameterized constructor
  SecurityStudent(const std::string &StudentID, const std::string &firstName,
                  const std::string &lastName, const std::string &emailAddress,
                  const std::string &age, int *daysOfCourse, Degree dType);
  Degree getDegreeProgram() override;
  void setDegreeType(Degree d) override; // pure virtual function
  void print() override;

  // superdestructor
  ~SecurityStudent();
};