#pragma once
#include "student.h"

class SecurityStudent : public Student {
public:
  // constructor
  SecurityStudent();
  // parameterized constructor
  SecurityStudent(std::string StudentID, std::string firstName,
                  std::string lastName, std::string emailAddress,
                  std::string age, int *daysOfCourse, Degree dType);
  Degree getDegreeProgram();
  void setDegreeType(Degree d);
  void print();

  // superdestructor
  ~SecurityStudent();
};