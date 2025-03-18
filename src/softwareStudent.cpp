#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent()
{
	setDegreeType(SOFTWARE);
}
SoftwareStudent::SoftwareStudent(string StudentID, string firstName, string lastName, string emailAddress, string age, int* daysOfCourses, Degree degreeType)
{
	setDegreeType(SOFTWARE);
}
Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}
void SoftwareStudent::setDegreeType(Degree d)
{
	this->degreeType = SOFTWARE;
}
void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE\n";
}
SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}