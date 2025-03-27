#include "student.h"

#include <algorithm>
#include <iostream>

// default constructor
Student::Student()
    : studentID(""),
      firstName(""),
      lastName(""),
      emailAddress(""),
      age(""),
      degreeType(Degree::SOFTWARE),  // placeholder
      daysOfCourse(new int[daysArraySize]{0}) {}

// parameterized constructor
Student::Student(const std::string &ID, const std::string &fName,
                 const std::string &lName, const std::string &eAddress,
                 const std::string &stAge, int daysOfCourse[],
                 Degree degreeType)
    : studentID(ID),
      firstName(fName),
      lastName(lName),
      emailAddress(eAddress),
      age(stAge),
      degreeType(degreeType),
      daysOfCourse(new int[daysArraySize]) {
  std::copy(daysOfCourse, daysOfCourse + daysArraySize, this->daysOfCourse);
}

// setters
void Student::setStudentID(const std::string &ID) { studentID = ID; }
void Student::setFirstName(const std::string &fName) { firstName = fName; }
void Student::setLastName(const std::string &lName) { lastName = lName; }
void Student::setEmail(const std::string &eAddress) { emailAddress = eAddress; }
void Student::setAge(const std::string &stAge) { age = stAge; }
void Student::setDaysOfCourse(int daysOfCourse[]) {
  // 'this' pointer retrieving object in parameters
  std::copy(daysOfCourse, daysOfCourse + daysArraySize, this->daysOfCourse);
}

// getters
const std::string &Student::getID() { return studentID; }
const std::string &Student::getFirstName() { return firstName; }
const std::string &Student::getLastName() { return lastName; }
const std::string &Student::getEmail() { return emailAddress; }
const std::string &Student::getAge() { return age; }
int *Student::getCourseDays() { return daysOfCourse; }

void Student::print() {
  std::cout << "Student ID: " << studentID << "\t"
            << "First Name: " << firstName << "\t"
            << "Last Name: " << lastName << "\t"
            << "Email Address: " << emailAddress << "\t"
            << "Age: " << age << "\t Days In Course: {" << daysOfCourse[0]
            << ", " << daysOfCourse[1] << ", " << daysOfCourse[2] << "} "
            << "Degree Program: " << degreeType << std::endl;
}

Student::~Student() {
  delete[] daysOfCourse;
  daysOfCourse = nullptr;
}