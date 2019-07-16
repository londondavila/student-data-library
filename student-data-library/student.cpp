#include "student.h"
#include <iomanip>

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = "";
	this->daysOfCourse = new int[daysArraySize];
	for (int i = 0; i < daysArraySize; i++) this->daysOfCourse[i] = 0;
}

Student::Student(string ID, string fName, string lName, string eAddress, string stAge, int daysOfCourse[], Degree degreeType)
{
	this->studentID = ID;
	this->firstName = fName;
	this->lastName = lName;
	this->emailAddress = eAddress;
	this->age = stAge;
	this->daysOfCourse = new int[daysArraySize];
	for (int i = 0; i < daysArraySize; i++) this->daysOfCourse[i] = daysOfCourse[i];
}

// SETTERS //
void Student::setStudentID(string ID)
{
	studentID = ID;
}
void Student::setFirstName(string fName)
{
	firstName = fName;
}
void Student::setLastName(string lName)
{
	lastName = lName;
}
void Student::setEmail(string eAddress)
{
	emailAddress = eAddress;
}
void Student::setAge(string stAge)
{
	age = stAge;
}
void Student::setDaysOfCourse(int daysOfCourse[]) {
	for (int i = 0; i < daysArraySize; i++)
		this->daysOfCourse[i] = daysOfCourse[i];
	// 'this' pointer retrieving object in parameters
}
// GETTERS //
string Student::getID()
{
	return studentID;
}
string Student::getFirstName()
{
	return firstName;
}
string Student::getLastName()
{
	return lastName;
}
string Student::getEmail()
{
	return emailAddress;
}
string Student::getAge()
{
	return age;
}
int* Student::getCourseDays()
{
	return daysOfCourse;
}

void Student::print()
{
	cout << "Student ID: " << studentID << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Email Address: " << emailAddress << "\t";
	cout << "Age: " << age << "\t Days In Course: {";
	cout << daysOfCourse[0] << ", ";
	cout << daysOfCourse[1] << ", ";
	cout << daysOfCourse[2] << "} ";
	cout << "Degree Program: " << degreeType << "\t";
}

Student::~Student()
{
	if (daysOfCourse != nullptr) {
		delete[] daysOfCourse;
		daysOfCourse = nullptr;
	}
}