#include "roster.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"

Roster::Roster()
{
	this->maxSize = 0;
	this->index = -1; // setting to empty
	this->classRosterArray = nullptr;
}
Roster::Roster(int maxSize)
{
	this->maxSize = maxSize;
	this->index = -1;
	this->classRosterArray = new Student*[maxSize];
}
void Roster::parse(string row)
{
	if (index < maxSize) {
		index++; // start at 0
		int tempArrayDays[Student::daysArraySize];
		if (row.back() == 'E')
		{
			this->classRosterArray[index] = new SoftwareStudent();
			classRosterArray[index]->setDegreeType(SOFTWARE);
		}
		else if (row.back() == 'Y')
		{
			this->classRosterArray[index] = new SecurityStudent();
			classRosterArray[index]->setDegreeType(SECURITY);
		}
		else if (row.back() == 'G')
		{
			this->classRosterArray[index] = new NetworkStudent();
			classRosterArray[index]->setDegreeType(NETWORKING);
		}
		else
		{
			cerr << "ERROR: STUDENT TYPE BROKEN.\n";
			exit(-1);
		}

		int rightParse = studentData[index].find(",");
		classRosterArray[index]->setStudentID(studentData[index].substr(0, rightParse));
		
		int leftParse = rightParse + 1;
		rightParse = studentData[index].find(",", leftParse);
		classRosterArray[index]->setFirstName(studentData[index].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[index].find(",", leftParse);
		classRosterArray[index]->setLastName(studentData[index].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[index].find(",", leftParse);
		classRosterArray[index]->setEmail(studentData[index].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[index].find(",", leftParse);
		classRosterArray[index]->setAge(studentData[index].substr(leftParse, rightParse - leftParse));

		// DAYS IN COURSE

		leftParse = rightParse + 1;
		rightParse = studentData[index].find(",", leftParse);
		tempArrayDays[0] = stoi(studentData[index].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[index].find(",", leftParse);
		tempArrayDays[1] = stoi(studentData[index].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[index].find(",", leftParse);
		tempArrayDays[2] = stoi(studentData[index].substr(leftParse, rightParse - leftParse));

		classRosterArray[index]->setDaysOfCourse(tempArrayDays);
	}
	else
	{
		cerr << "ERROR\n";
		exit(-1);
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, string age, int daysOfCourse1, int daysOfCourse2, int daysOfCourse3, Degree degreeType)
{
	int studentDaysOfCourse[Student::daysArraySize];
	studentDaysOfCourse[0] = daysOfCourse1;
	studentDaysOfCourse[1] = daysOfCourse2;
	studentDaysOfCourse[2] = daysOfCourse3;
}

void Roster::printAll()
{
	for (int i = 0; i <= this->index; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string studentID)
{
	bool exists = false;
	for (int i = 0; i <= index; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			exists = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[index];
			index--;
		}
	}
	return exists;
}

void Roster::printByDegreeProgram(Degree d)
{
	//cout << "Printing by degree program:\n";
	for (int i = 0; i <= index; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == d) this->classRosterArray[i]->print();
	}
}

void Roster::printDaysInCourse(string studentID)
{
	for (int i = 0; i <= index; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			int* avgDays = classRosterArray[i]->getCourseDays();
			cout << "\nAverage days of courses for student " << studentID << " is " << (avgDays[0] + avgDays[1] + avgDays[2]) / 3 << " days." << endl;
		}
		else
		{
			//cout << "Course not found.\n";
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= index; i++)
	{
		string emailCheck = classRosterArray[i]->getEmail();
		if (emailCheck.find(".") == string::npos ||
			emailCheck.find("@") == string::npos ||
			emailCheck.find(" ") != string::npos) cout << emailCheck << " is an invalid email." << endl;
	}
}

Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this; // dynamic destructor
}

auto main() -> int
{
	Roster * classRoster = new Roster(numStudents);

	cout << "\nParsing data and adding students:\n";
	
	#pragma unroll
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parse(studentData[i]);
	}

	cout << "\nData parsed.\n";
	
	cout << "\nPrinting all students.\n" << endl;
	classRoster->printAll();

	cout << "\nPrinting invalid student emails:\n" << endl;
	classRoster->printInvalidEmails();

	cout << "\nPrinting average days in course for student A2:\n";
	classRoster->printDaysInCourse("A2");
	
	cout << "\nPrinting students in the Software Program.\n" << endl;
	classRoster->printByDegreeProgram(SOFTWARE);

	cout << "\nRemoving student A3:\n\n";
	if (classRoster->remove("A3")) {
		classRoster->printAll();
	} else {
		cout << "ERROR: COULD NOT REMOVE, STUDENT NOT FOUND.\n";
	}

	cout << "\nRemoving student A3:\n\n";
	if (classRoster->remove("A3")) {
		classRoster->printAll();
	} else {
		cout << "ERROR: COULD NOT REMOVE, STUDENT NOT FOUND.\n";
	}

	return 0;
}