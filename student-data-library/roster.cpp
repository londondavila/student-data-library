#include "roster.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"

Roster::Roster()
{
	this->maxSize = 0;
	this->lastIndex = -1;
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
		lastIndex++;
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
			cerr << "ERROR.\n";
			exit(-1);
		}

		int rightParse = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rightParse));
		
		int leftParse = rightParse + 1;
		rightParse = studentData[lastIndex].find(".", leftParse);
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

void Roster::remove(string studentID)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
}

void Roster::printByDegreeProgram(Degree d)
{
	cout << "Printing by degree program: \n ";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == d) this->classRosterArray[i]->print();
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; i++)
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
	delete this;
}

int main()
{
	cout << "C867 - Scripting and Programming Applications\n";
	cout << "C++\n";
	cout << "00081497\n";
	cout << "London Davila\n";

	Roster * dynamicRoster = new Roster(numStudents);
	cout << "Parsing data and adding students:\n";
	for (int i = 0; i < numStudents; i++)
	{
		dynamicRoster->parse(studentData[i]);
	}
	
	cout << "Printing students." << endl;
	dynamicRoster->printAll();

	/*cout << "Removing A3:\n";
	if (dynamicRoster->remove("A3")) dynamicRoster->printAll();
	else cout << "Student not found!\n";

	cout << "Removing A3:\n";
	if (dynamicRoster->remove("A3")) dynamicRoster->printAll();
	else cout << "Student not found!\n"; */

	//dynamicRoster->printByDegreeProgram(SECURITY);
	//dynamicRoster->printByDegreeProgram(SOFTWARE);
	//dynamicRoster->printByDegreeProgram(NETWORKING);

	//dynamicRoster->printInvalidEmails();

	return 0;
}