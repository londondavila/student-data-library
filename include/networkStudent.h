#pragma once
#include <string>

#include "student.h"

class NetworkStudent : public Student {
 public:
  NetworkStudent();
  NetworkStudent(const std::string &StudentID, const std::string &firstName,
                 const std::string &lastName, const std::string &emailAddress,
                 const std::string &age, int *daysOfCourse, Degree degreeType);

  void setDegreeType(Degree d);
  Degree getDegreeProgram() override;
  void print() override;

  // destructor
  ~NetworkStudent();
};