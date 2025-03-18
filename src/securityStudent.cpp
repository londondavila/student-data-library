#include <iostream>
#include "securityStudent.h"

SecurityStudent::SecurityStudent()
{
	setDegreeType(SECURITY);
}
SecurityStudent::SecurityStudent(string StudentID, string firstName, string lastName, string emailAddress, string age, int* daysOfCourses, Degree degreeType)
{
	setDegreeType(SECURITY);
}
Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}
void SecurityStudent::setDegreeType(Degree d)
{
	this->degreeType = SECURITY;
}
void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY\n";
}
SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
}