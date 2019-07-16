#pragma once
#include "student.h"

class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(
		string StudentID,
		string firstName,
		string lastName,
		string emailAddress,
		string age,
		int* daysOfCourse,
		Degree dType
	);
	Degree getDegreeProgram();
	void setDegreeType(Degree d);
	void print();

	~SecurityStudent(); // call superdestructor
};