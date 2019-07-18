#include "roster.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"

Roster::Roster()
{
	this->maxSize = 0;
	this->lastIndex = -1; // setting to empty
	this->classRosterArray = nullptr;
}
Roster::Roster(int maxSize)
{
	this->maxSize = maxSize;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[maxSize];
}
void Roster::parse(string row)
{
	if (lastIndex < maxSize) {
		lastIndex++; // start at 0
		int tempArrayDays[Student::daysArraySize];
		if (row.back() == 'E')
		{
			this->classRosterArray[lastIndex] = new SoftwareStudent();
			classRosterArray[lastIndex]->setDegreeType(SOFTWARE);
		}
		else if (row.back() == 'Y')
		{
			this->classRosterArray[lastIndex] = new SecurityStudent();
			classRosterArray[lastIndex]->setDegreeType(SECURITY);
		}
		else if (row.back() == 'G')
		{
			this->classRosterArray[lastIndex] = new NetworkStudent();
			classRosterArray[lastIndex]->setDegreeType(NETWORKING);
		}
		else
		{
			cerr << "ERROR. STUDENT TYPE BROKEN.\n";
			exit(-1);
		}

		int rightParse = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rightParse));
		
		int leftParse = rightParse + 1;
		rightParse = studentData[lastIndex].find(",", leftParse);
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[lastIndex].find(",", leftParse);
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[lastIndex].find(",", leftParse);
		classRosterArray[lastIndex]->setEmail(studentData[lastIndex].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[lastIndex].find(",", leftParse);
		classRosterArray[lastIndex]->setAge(studentData[lastIndex].substr(leftParse, rightParse - leftParse));

		// DAYS IN COURSE

		leftParse = rightParse + 1;
		rightParse = studentData[lastIndex].find(",", leftParse);
		tempArrayDays[0] = stoi(studentData[lastIndex].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[lastIndex].find(",", leftParse);
		tempArrayDays[1] = stoi(studentData[lastIndex].substr(leftParse, rightParse - leftParse));

		leftParse = rightParse + 1;
		rightParse = studentData[lastIndex].find(",", leftParse);
		tempArrayDays[2] = stoi(studentData[lastIndex].substr(leftParse, rightParse - leftParse));

		classRosterArray[lastIndex]->setDaysOfCourse(tempArrayDays);
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
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string studentID)
{
	bool exists = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			exists = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	return exists;
}

void Roster::printByDegreeProgram(Degree d)
{
	cout << "Printing by degree program:\n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == d) this->classRosterArray[i]->print();
	}
}

void Roster::printDaysInCourse(string studentID)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			int* avgDays = classRosterArray[i]->getCourseDays();
			cout << "Average days in course " << studentID << " are " << (avgDays[0] + avgDays[1] + avgDays[2]) / 3 << endl;
		}
		else
		{
			//cout << "Course not found.\n";
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		string emailCheck = classRosterArray[i]->getEmail();
		if (emailCheck.find(".") == string::npos ||
			emailCheck.find("@") == string::npos ||
			emailCheck.find(" ") != string::npos) cout << emailCheck << " is an invalid email.\n" << endl;
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

int main()
{
	cout << "C867 - Scripting and Programming Applications\n";
	cout << "C++\n";
	cout << "00081497\n";
	cout << "London Davila\n" << endl;

	Roster * classRoster = new Roster(numStudents);
	cout << "Parsing data and adding students:\n";
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parse(studentData[i]);
	}

	cout << "Data parsed.\n";
	
	cout << "Printing all students.\n" << endl;
	classRoster->printAll();

	cout << "Printing invalid student emails:\n";
	classRoster->printInvalidEmails();

	cout << "Printing average days in course for student A2:\n" << endl;
	classRoster->printDaysInCourse("A2");
	
	cout << "Printing students in the Software Program.\n";
	classRoster->printByDegreeProgram(SOFTWARE);
	
	//classRoster->printByDegreeProgram(SOFTWARE);
	//classRoster->printByDegreeProgram(NETWORKING);

	cout << "Removing student A3:\n";
	if (classRoster->remove("A3")) classRoster->printAll();
	else cout << "COULD NOT REMOVE, STUDENT NOT FOUND.\n";

	cout << "Removing student A3:\n";
	if (classRoster->remove("A3")) classRoster->printAll();
	else cout << "COULD NOT REMOVE, STUDENT NOT FOUND.\n";

	return 0;
}