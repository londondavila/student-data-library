#pragma once

#include "student.h"

class NetworkStudent : public Student
{
public:
	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent(); // call superdestructor
};