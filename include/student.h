#pragma once
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
  // CONSTRUCTORS //
  Student();
  Student(string ID, string fName, string lName, string eAddress, string stAge,
          int daysOfCourse[], Degree degreeType);

  const static int daysArraySize = 3; // number of days to complete courses
  // SETTERS //
  void setStudentID(string ID);
  void setFirstName(string fName);
  void setLastName(string lName);
  void setEmail(string eAddress);
  void setAge(string stAge);
  void setDaysOfCourse(int days[]);
  virtual void setDegreeType(Degree d) = 0;

  // GETTERS //
  string getID();
  string getFirstName();
  string getLastName();
  string getEmail();
  string getAge();
  int *getCourseDays();

  // VIRTUAL PRINT //
  virtual void print() = 0;

  ~Student(); // DESTRUCTOR

  // VIRTUAL PROGRAM //
  virtual Degree getDegreeProgram() = 0;

protected:
  string studentID;
  string firstName;
  string lastName;
  string emailAddress;
  string age;
  int *daysOfCourse;
  Degree degreeType; // The enumerated value
};