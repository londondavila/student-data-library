#include "networkStudent.h"

NetworkStudent::NetworkStudent()
{
	setDegreeType(NETWORKING);
}
NetworkStudent::NetworkStudent(string StudentID, string firstName, string lastName, string emailAddress, string age, int* daysOfCourses, Degree degreeType)
{
	setDegreeType(NETWORKING);
}
Degree NetworkStudent::getDegreeProgram()
{
	return NETWORKING;
}
void NetworkStudent::setDegreeType(Degree d)
{
	this->degreeType = NETWORKING;
}
void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORKING\n";
}
NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;
}