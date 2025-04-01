#include <string>

#include "roster.cpp"

auto main() -> int {
  Roster *classRoster = new Roster(numStudents);

  std::cout << "\nParsing data and adding students:" << std::endl;

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
