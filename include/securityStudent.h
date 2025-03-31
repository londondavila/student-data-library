#pragma once
#include <string>

#include "student.h"

class SecurityStudent : public Student {
 public:
  // constructor
  SecurityStudent();
  // parameterized constructor
  SecurityStudent(const std::string &StudentID, const std::string &firstName,
                  const std::string &lastName, const std::string &emailAddress,
                  const std::string &age, Degree degreeType, int *daysOfCourse);

  Degree getDegreeProgram() override;
  void setDegreeType() override;
  void print() override;

  // superdestructor
  ~SecurityStudent();
};
