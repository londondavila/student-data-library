#include "student.h"

#include <algorithm>
#include <iostream>

// default constructor
Student::Student()
    : _studentID(""),
      _firstName(""),
      _lastName(""),
      _emailAddress(""),
      _age(""),
      _degreeType(Degree::UNDEFINED),  // placeholder
      _daysOfCourse(new int[Student::getDefaultDaysArraySize()]{0}) {}

// parameterized constructor
Student::Student(const std::string &ID, const std::string &fName,
                 const std::string &lName, const std::string &eAddress,
                 const std::string &stAge, int daysOfCourse[], Degree dType)
    : _studentID(ID),
      _firstName(fName),
      _lastName(lName),
      _emailAddress(eAddress),
      _age(stAge),
      _degreeType(Degree::UNDEFINED),
      _daysOfCourse(new int[Student::getDefaultDaysArraySize()]) {
  std::copy(daysOfCourse, daysOfCourse + Student::getDefaultDaysArraySize(),
            this->_daysOfCourse);
}

// setters
void Student::setStudentID(const std::string &ID) { _studentID = ID; }
void Student::setFirstName(const std::string &fName) { _firstName = fName; }
void Student::setLastName(const std::string &lName) { _lastName = lName; }
void Student::setEmail(const std::string &eAddress) {
  _emailAddress = eAddress;
}
void Student::setAge(const std::string &stAge) { _age = stAge; }
void Student::setDaysOfCourse(int daysOfCourse[]) {
  // 'this' pointer retrieving object in parameters
  std::copy(daysOfCourse, daysOfCourse + Student::getDefaultDaysArraySize(),
            this->_daysOfCourse);
}
void Student::setDegreeType() { _degreeType = UNDEFINED; }

// getter
void Student::print() {
  std::cout << "Student ID: " << _studentID << "\t"
            << "First Name: " << _firstName << "\t"
            << "Last Name: " << _lastName << "\t"
            << "Email Address: " << _emailAddress << "\t"
            << "Age: " << _age << "\t Days In Course: {" << _daysOfCourse[0]
            << ", " << _daysOfCourse[1] << ", " << _daysOfCourse[2] << "} "
            << "Degree Program: " << _degreeType << std::endl;
}

Student::~Student() {
  delete[] _daysOfCourse;
  _daysOfCourse = nullptr;
}