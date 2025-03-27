#pragma once
#include <string>

#include "student.h"

const int numStudents = 5;

const std::string studentData[numStudents] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORKING",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,London,Davila,london.davila@gmail.com,21,23,31,33,SOFTWARE"};

class Roster {
 public:
  Roster();
  explicit Roster(int maxSize);

  // copy constructor
  Roster(const Roster &other);

  // assignment operator
  Roster &operator=(const Roster &other);

  void parse(const std::string &row);
  void add(const std::string &studentID, const std::string &firstName,
           const std::string &lastName, const std::string &emailAddress,
           const std::string &age, int daysInCourse1, int daysInCourse2,
           int daysInCourse3, Degree degreeType);
  bool remove(const std::string &studentID);
  void printAll();
  void printInvalidEmails();
  void printDaysInCourse(const std::string &studentID);
  void printByDegreeProgram(Degree d);

  ~Roster();

 private:
  // dynamically allocated array
  Student **classRosterArray = nullptr;
  // iteration or tracking index
  int index = 0;
  // default size, can be set dynamically
  int maxSize = numStudents;
};