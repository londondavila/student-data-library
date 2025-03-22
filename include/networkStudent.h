#pragma once
#include "student.h"

class NetworkStudent : public Student {
public:
  NetworkStudent();
  NetworkStudent(std::string StudentID, std::string firstName,
                 std::string lastName, std::string emailAddress,
                 std::string age, int *daysOfCourse, Degree dType);
  Degree getDegreeProgram();
  void setDegreeType(Degree d);
  void print();

  // destructor
  ~NetworkStudent();
};