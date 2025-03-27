#include <string>

#include "networkStudent.h"
#include "roster.h"
#include "securityStudent.h"
#include "softwareStudent.h"

Roster::Roster() {
  this->maxSize = 0;
  this->index = -1;  // setting to empty
  this->classRosterArray = nullptr;
}

// parameterized constructor
Roster::Roster(int maxSize) {
  this->maxSize = maxSize;
  this->index = -1;
  this->classRosterArray = new Student *[maxSize];
}

// copy constructor
Roster::Roster(const Roster &other)
    : maxSize(other.maxSize),
      index(other.index),
      classRosterArray(new Student *[other.maxSize]) {
  for (int i = 0; i <= other.index; ++i) {
    // perform shallow copy of pointers
    this->classRosterArray[i] = other.classRosterArray[i];
  }
}

// copy assignment operator
Roster &Roster::operator=(const Roster &other) {
  if (this == &other) {  // self-assignment check
    return *this;
  }

  // cleanup current resources
  delete[] this->classRosterArray;

  // deep copy resources from "other"
  this->index = other.index;
  this->maxSize = other.maxSize;
  this->classRosterArray = new Student *[other.maxSize];
  for (int i = 0; i <= other.index; ++i) {
    this->classRosterArray[i] = other.classRosterArray[i];  // Shallow copy
  }

  return *this;
}

void Roster::parse(const std::string &row) {
  std::cout << "Parsing row: " << row << std::endl;
  std::cout << "Current index: " << index << ", Max size: " << maxSize
            << std::endl;

  if (index < maxSize) {
    index++;  // start at 0
    int tempArrayDays[Student::getDefaultDaysArraySize()];
    if (row.back() == 'E') {
      this->classRosterArray[index] = new SoftwareStudent();
      classRosterArray[index]->setDegreeType(SOFTWARE);
    } else if (row.back() == 'Y') {
      this->classRosterArray[index] = new SecurityStudent();
      classRosterArray[index]->setDegreeType(SECURITY);
    } else if (row.back() == 'G') {
      this->classRosterArray[index] = new NetworkStudent();
      classRosterArray[index]->setDegreeType(NETWORKING);
    } else {
      std::cerr << "ERROR: STUDENT TYPE BROKEN.\n";
      exit(-1);
    }

    int rightParse = studentData[index].find(",");
    classRosterArray[index]->setStudentID(
        studentData[index].substr(0, rightParse));

    int leftParse = rightParse + 1;
    rightParse = studentData[index].find(",", leftParse);
    classRosterArray[index]->setFirstName(
        studentData[index].substr(leftParse, rightParse - leftParse));

    leftParse = rightParse + 1;
    rightParse = studentData[index].find(",", leftParse);
    classRosterArray[index]->setLastName(
        studentData[index].substr(leftParse, rightParse - leftParse));

    leftParse = rightParse + 1;
    rightParse = studentData[index].find(",", leftParse);
    classRosterArray[index]->setEmail(
        studentData[index].substr(leftParse, rightParse - leftParse));

    leftParse = rightParse + 1;
    rightParse = studentData[index].find(",", leftParse);
    classRosterArray[index]->setAge(
        studentData[index].substr(leftParse, rightParse - leftParse));

    // DAYS IN COURSE

    leftParse = rightParse + 1;
    rightParse = studentData[index].find(",", leftParse);
    tempArrayDays[0] =
        stoi(studentData[index].substr(leftParse, rightParse - leftParse));

    leftParse = rightParse + 1;
    rightParse = studentData[index].find(",", leftParse);
    tempArrayDays[1] =
        stoi(studentData[index].substr(leftParse, rightParse - leftParse));

    leftParse = rightParse + 1;
    rightParse = studentData[index].find(",", leftParse);
    tempArrayDays[2] =
        stoi(studentData[index].substr(leftParse, rightParse - leftParse));

    classRosterArray[index]->setDaysOfCourse(tempArrayDays);
  } else {
    std::cerr << "ERROR\n";
    exit(-1);
  }
}

void Roster::add(const std::string &studentID, const std::string &firstName,
                 const std::string &lastName, const std::string &emailAddress,
                 const std::string &age, int daysOfCourse1, int daysOfCourse2,
                 int daysOfCourse3, Degree degreeType) {
  if (index < maxSize) {
    index++;

    switch (degreeType) {
      case SOFTWARE:
        classRosterArray[index] = new SoftwareStudent(
            studentID, firstName, lastName, emailAddress, age,
            new int[Student::getDefaultDaysArraySize()]{
                daysOfCourse1, daysOfCourse2, daysOfCourse3},
            degreeType);
        break;
      case SECURITY:
        classRosterArray[index] = new SecurityStudent(
            studentID, firstName, lastName, emailAddress, age,
            new int[Student::getDefaultDaysArraySize()]{
                daysOfCourse1, daysOfCourse2, daysOfCourse3},
            degreeType);
        break;
      case NETWORKING:
        classRosterArray[index] = new NetworkStudent(
            studentID, firstName, lastName, emailAddress, age,
            new int[Student::getDefaultDaysArraySize()]{
                daysOfCourse1, daysOfCourse2, daysOfCourse3},
            degreeType);
        break;
      default:
        std::cerr << "ERROR: Invalid degree type." << std::endl;
        exit(-1);
    }
  } else {
    std::cerr << "ERROR: Roster is full." << std::endl;
  }
}

void Roster::printAll() {
  for (int i = 0; i <= this->index; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(const std::string &studentID) {
  bool exists = false;
  for (int i = 0; i <= index; i++) {
    if (this->classRosterArray[i]->getID() == studentID) {
      exists = true;
      this->classRosterArray[i] = this->classRosterArray[index];
      index--;
    }
  }
  return exists;
}

void Roster::printByDegreeProgram(Degree d) {
  // cout << "Printing by degree program:\n";
  for (int i = 0; i <= index; i++) {
    if (this->classRosterArray[i]->getDegreeProgram() == d)
      this->classRosterArray[i]->print();
  }
}

void Roster::printDaysInCourse(const std::string &studentID) {
  for (int i = 0; i <= index; i++) {
    if (this->classRosterArray[i]->getID() == studentID) {
      const int *avgDays = classRosterArray[i]->getCourseDays();
      std::cout << "\nAverage days of courses for student " << studentID
                << " is " << (avgDays[0] + avgDays[1] + avgDays[2]) / 3
                << " days." << std::endl;
    } else {
      // cout << "Course not found.\n";
    }
  }
}

void Roster::printInvalidEmails() {
  for (int i = 0; i <= index; i++) {
    std::string emailCheck = classRosterArray[i]->getEmail();
    if (emailCheck.find(".") == std::string::npos ||
        emailCheck.find("@") == std::string::npos ||
        emailCheck.find(" ") != std::string::npos)
      std::cout << emailCheck << " is an invalid email." << std::endl;
  }
}

Roster::~Roster() {
  // delete array itself
  delete[] classRosterArray;
}

auto main() -> int {
  Roster *classRoster = new Roster(numStudents);

  std::cout << "\nParsing data and adding students:\n";

#pragma unroll
  for (int i = 0; i < numStudents; i++) {
    classRoster->parse(studentData[i]);
  }

  std::cout << "\nData parsed.\n";

  std::cout << "\nPrinting all students.\n" << std::endl;
  classRoster->printAll();

  std::cout << "\nPrinting invalid student emails:\n" << std::endl;
  classRoster->printInvalidEmails();

  std::cout << "\nPrinting average days in course for student A2:\n";
  classRoster->printDaysInCourse("A2");

  std::cout << "\nPrinting students in the Software Program.\n" << std::endl;
  classRoster->printByDegreeProgram(SOFTWARE);

  std::cout << "\nRemoving student A3:\n\n";
  if (classRoster->remove("A3")) {
    classRoster->printAll();
  } else {
    std::cout << "ERROR: COULD NOT REMOVE, STUDENT NOT FOUND.\n";
  }

  std::cout << "\nRemoving student A3:\n\n";
  if (classRoster->remove("A3")) {
    classRoster->printAll();
  } else {
    std::cout << "ERROR: COULD NOT REMOVE, STUDENT NOT FOUND.\n";
  }

  return 0;
}