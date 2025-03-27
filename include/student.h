#pragma once
#include <iostream>
#include <string>

#include "degree.h"

class Student {
 public:
  // constructor
  Student();

  // parameterized constructor
  Student(const std::string &ID, const std::string &fName,
          const std::string &lName, const std::string &eAddress,
          const std::string &stAge, int daysOfCourse[], Degree degreeType);

  // copy constructor
  Student(const Student &other);

  // copy assignment operator
  Student &operator=(const Student &other);

  // destructor
  ~Student();

  // setters
  void setStudentID(const std::string &ID);
  void setFirstName(const std::string &fName);
  void setLastName(const std::string &lName);
  void setEmail(const std::string &eAddress);
  void setAge(const std::string &stAge);
  void setDaysOfCourse(int days[]);
  virtual void setDegreeType(Degree degreeType) = 0;

  // getters
  const std::string &getID() { return studentID; }
  const std::string &getFirstName() { return firstName; }
  const std::string &getLastName() { return lastName; }
  const std::string &getEmail() { return emailAddress; }
  const std::string &getAge() { return age; }
  int *getCourseDays() { return daysOfCourse; }
  const static int getDefaultDaysArraySize() { return defaultDaysArraySize; }
  Degree getDegreeType() { return degreeType; }

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
  const static int defaultDaysArraySize = 3;
  Degree degreeType;  // enumerated value
};