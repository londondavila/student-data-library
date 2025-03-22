#include "student.h"
#include <iostream>

Student::Student() {
  this->studentID = "";
  this->firstName = "";
  this->lastName = "";
  this->emailAddress = "";
  this->age = "";
  this->daysOfCourse = new int[daysArraySize];
  for (int i = 0; i < daysArraySize; i++)
    this->daysOfCourse[i] = 0;
}

Student::Student(std::string ID, std::string fName, std::string lName,
                 std::string eAddress, std::string stAge, int daysOfCourse[],
                 Degree degreeType) {
  this->studentID = ID;
  this->firstName = fName;
  this->lastName = lName;
  this->emailAddress = eAddress;
  this->age = stAge;
  this->daysOfCourse = new int[daysArraySize];
  for (int i = 0; i < daysArraySize; i++)
    this->daysOfCourse[i] = daysOfCourse[i];
}

// SETTERS //
void Student::setStudentID(std::string ID) { studentID = ID; }
void Student::setFirstName(std::string fName) { firstName = fName; }
void Student::setLastName(std::string lName) { lastName = lName; }
void Student::setEmail(std::string eAddress) { emailAddress = eAddress; }
void Student::setAge(std::string stAge) { age = stAge; }
void Student::setDaysOfCourse(int daysOfCourse[]) {
  for (int i = 0; i < daysArraySize; i++)
    this->daysOfCourse[i] = daysOfCourse[i];
  // 'this' pointer retrieving object in parameters
}
// GETTERS //
std::string Student::getID() { return studentID; }
std::string Student::getFirstName() { return firstName; }
std::string Student::getLastName() { return lastName; }
std::string Student::getEmail() { return emailAddress; }
std::string Student::getAge() { return age; }
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
  if (daysOfCourse != nullptr) {
    delete[] daysOfCourse;
    daysOfCourse = nullptr;
  }
}