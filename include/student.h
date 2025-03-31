#pragma once
#include <iostream>
#include <string>

#include "degree.h"

const static int DEFAULT_DAYS_ARRAY_SIZE = 3;

class Student {
 public:
  // constructor
  Student();

  // parameterized constructor
  Student(const std::string &ID, const std::string &fName,
          const std::string &lName, const std::string &eAddress,
          const std::string &stAge, Degree degreeType, int daysOfCourse[]);

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
  virtual void setDegreeType() = 0;

  // getters
  const std::string &getID() { return _studentID; }
  const std::string &getFirstName() { return _firstName; }
  const std::string &getLastName() { return _lastName; }
  const std::string &getEmail() { return _emailAddress; }
  const std::string &getAge() { return _age; }
  Degree getDegreeType() { return _degreeType; }
  int *getCourseDays() { return _daysOfCourse; }

  // virtual functions
  virtual void print() = 0;
  virtual Degree getDegreeProgram() = 0;

 protected:
  std::string _studentID;
  std::string _firstName;
  std::string _lastName;
  std::string _emailAddress;
  std::string _age;
  [[maybe_unused]] Degree _degreeType;  // enumerated value
  int *_daysOfCourse;
};
