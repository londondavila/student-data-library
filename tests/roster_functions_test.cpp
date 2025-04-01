// Parsing data and adding students:
// Parsing row: A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY
// Current index: -1, Max size: 5
// Parsing row: A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORKING
// Current index: 0, Max size: 5
// Parsing row: A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE
// Current index: 1, Max size: 5
// Parsing row: A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY
// Current index: 2, Max size: 5
// Parsing row: A5,London,Davila,london.davila@gmail.com,21,23,31,33,SOFTWARE
// Current index: 3, Max size: 5

// Data parsed.

// Printing all students.

// Student ID: A1  First Name: John        Last Name: Smith        Email
// Address: John1989@gm ail.com      Age: 20  Days In Course: {30, 35, 40}
// Degree Program: 0 SECURITY Student ID: A2  First Name: Suzan       Last Name:
// Erickson     Email Address: Erickson_1990@gmailcom   Age: 19  Days In Course:
// {50, 30, 40} Degree Program: 1 NETWORKING Student ID: A3  First Name: Jack
// Last Name: Napoli       Email Address: The_lawyer99yahoo.com    Age: 19  Days
// In Course: {20, 40, 33} Degree Program: 2 SOFTWARE Student ID: A4  First
// Name: Erin        Last Name: Black        Email Address:
// Erin.black@comcast.net   Age: 22  Days In Course: {50, 58, 40} Degree
// Program: 0 SECURITY Student ID: A5  First Name: London      Last Name: Davila
// Email Address: london.davila@gmail.com  Age: 21  Days In Course: {23, 31, 33}
// Degree Program: 2 SOFTWARE

// Printing invalid student emails:

// John1989@gm ail.com is an invalid email.
// Erickson_1990@gmailcom is an invalid email.
// The_lawyer99yahoo.com is an invalid email.

// Printing average days in course for student A2:

// Average days of courses for student A2 is 40 days.

// Printing students in the Software Program.

// Student ID: A3  First Name: Jack        Last Name: Napoli       Email
// Address: The_lawyer99yahoo.com    Age: 19  Days In Course: {20, 40, 33}
// Degree Program: 2 SOFTWARE Student ID: A5  First Name: London      Last Name:
// Davila       Email Address: london.davila@gmail.com  Age: 21  Days In Course:
// {23, 31, 33} Degree Program: 2 SOFTWARE

// Removing student A3:

// Student ID: A1  First Name: John        Last Name: Smith        Email
// Address: John1989@gm ail.com      Age: 20  Days In Course: {30, 35, 40}
// Degree Program: 0 SECURITY Student ID: A2  First Name: Suzan       Last Name:
// Erickson     Email Address: Erickson_1990@gmailcom   Age: 19  Days In Course:
// {50, 30, 40} Degree Program: 1 NETWORKING Student ID: A5  First Name: London
// Last Name: Davila       Email Address: london.davila@gmail.com  Age: 21  Days
// In Course: {23, 31, 33} Degree Program: 2 SOFTWARE Student ID: A4  First
// Name: Erin        Last Name: Black        Email Address:
// Erin.black@comcast.net   Age: 22  Days In Course: {50, 58, 40} Degree
// Program: 0 SECURITY

// Removing student A3:

// ERROR: COULD NOT REMOVE, STUDENT NOT FOUND.

#include <gtest/gtest.h>  // NOLINT(clang-diagnostic-error)

#include <string>

#include "../src/roster.cpp"

// set up mock data
const int NUM_STUDENTS = 5;
const std::string STUDENT_DATA[NUM_STUDENTS] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORKING",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,London,Davila,london.davila@gmail.com,21,23,31,33,SOFTWARE"};

// test fixture for Roster
class RosterTest : public ::testing::Test {
 protected:
  Roster* classRoster;

  void SetUp() override {
    classRoster = new Roster(NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; i++) {
      classRoster->parse(STUDENT_DATA[i]);
    }
  }

  void TearDown() override { delete classRoster; }
};

// test for `printAll()`
TEST_F(RosterTest, PrintAll) {
  testing::internal::CaptureStdout();
  classRoster->printAll();
  std::string output = testing::internal::GetCapturedStdout();

  // verify that all students are printed
  EXPECT_NE(output.find("Student ID: A1"), std::string::npos);
  EXPECT_NE(output.find("Student ID: A2"), std::string::npos);
  EXPECT_NE(output.find("Student ID: A3"), std::string::npos);
  EXPECT_NE(output.find("Student ID: A4"), std::string::npos);
  EXPECT_NE(output.find("Student ID: A5"), std::string::npos);
}

// test for `printInvalidEmails()`
TEST_F(RosterTest, PrintInvalidEmails) {
  testing::internal::CaptureStdout();
  classRoster->printInvalidEmails();
  std::string output = testing::internal::GetCapturedStdout();

  // verify invalid emails are printed
  EXPECT_NE(output.find("John1989@gm ail.com"), std::string::npos);
  EXPECT_NE(output.find("Erickson_1990@gmailcom"), std::string::npos);
  EXPECT_NE(output.find("The_lawyer99yahoo.com"), std::string::npos);
}

// test for `printDaysInCourse()`
TEST_F(RosterTest, PrintDaysInCourse) {
  testing::internal::CaptureStdout();
  classRoster->printDaysInCourse("A2");
  std::string output = testing::internal::GetCapturedStdout();

  // verify average days in course for student A2
  EXPECT_NE(output.find("Average days of courses for student A2 is 40"),
            std::string::npos);
}

// test for `printByDegreeProgram()`
TEST_F(RosterTest, PrintByDegreeProgram) {
  testing::internal::CaptureStdout();
  classRoster->printByDegreeProgram(SOFTWARE);
  std::string output = testing::internal::GetCapturedStdout();

  // verify students in the SOFTWARE program are printed
  EXPECT_NE(output.find("Student ID: A3"), std::string::npos);
  EXPECT_NE(output.find("Student ID: A5"), std::string::npos);
}

// test for `remove()` - successful removal
TEST_F(RosterTest, RemoveStudentSuccess) {
  EXPECT_TRUE(classRoster->remove("A3"));

  testing::internal::CaptureStdout();
  classRoster->printAll();
  std::string output = testing::internal::GetCapturedStdout();

  // verify student A3 is removed
  EXPECT_EQ(output.find("Student ID: A3"), std::string::npos);
}

// test for `remove()` - failure case
TEST_F(RosterTest, RemoveStudentFailure) {
  EXPECT_FALSE(classRoster->remove("A6"));  // A6 does not exist
  // EXPECT_NE(output.find("ERROR: COULD NOT REMOVE, STUDENT NOT FOUND."),
  // std::string::npos);

  testing::internal::CaptureStdout();
  classRoster->printAll();
  std::string output = testing::internal::GetCapturedStdout();

  // verify no changes to the roster
  EXPECT_NE(output.find("Student ID: A1"), std::string::npos);
  EXPECT_NE(output.find("Student ID: A5"), std::string::npos);
}
