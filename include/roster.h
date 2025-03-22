#pragma once
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
  Roster(int maxSize);

  void parse(std::string row);
  void add(std::string studentID, std::string firstName, std::string lastName,
           std::string emailAddress, std::string age, int daysInCourse1,
           int daysInCourse2, int daysInCourse3, Degree degreeType);
  bool remove(std::string studentID);
  void printAll();
  void printInvalidEmails();
  void printDaysInCourse(std::string studentID);
  void printByDegreeProgram(Degree d);

  ~Roster();

private:
  int index;
  Student *
      *classRosterArray; // originally Student** classRosterArray for dynamic
  int maxSize;           // ONLY NEEDED FOR DYNAMIC ALLOCATION
};