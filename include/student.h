#pragma once
#include "degree.h"
#include <iostream>
#include <string>

class Student {
public:
  // constructor
  Student();
  // parameterized constructor
  Student(std::string ID, std::string fName, std::string lName,
          std::string eAddress, std::string stAge, int daysOfCourse[],
          Degree degreeType);

  // destructor
  ~Student();

  const static int daysArraySize = 3; // number of days to complete courses

  // setters
  void setStudentID(std::string ID);
  void setFirstName(std::string fName);
  void setLastName(std::string lName);
  void setEmail(std::string eAddress);
  void setAge(std::string stAge);
  void setDaysOfCourse(int days[]);
  virtual void setDegreeType(Degree d) = 0;

  // getters
  std::string getID();
  std::string getFirstName();
  std::string getLastName();
  std::string getEmail();
  std::string getAge();
  int *getCourseDays();

  // virtual functions
  virtual void print() = 0;
  virtual Degree getDegreeProgram() = 0;

protected:
  std::string studentID;
  std::string firstName;
  std::string lastName;
  std::string emailAddress;
  std::string age;
  int *daysOfCourse;
  Degree degreeType; // The enumerated value
};