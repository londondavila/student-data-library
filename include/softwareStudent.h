#pragma once
#include "student.h"

class SoftwareStudent : public Student {
public:
  SoftwareStudent();
  SoftwareStudent(string StudentID, string firstName, string lastName,
                  string emailAddress, string age, int *daysOfCourse,
                  Degree dType);
  Degree getDegreeProgram();
  void setDegreeType(Degree d);
  void print();

  ~SoftwareStudent(); // call superdestructor
};