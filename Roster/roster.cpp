#include <string>
#include "Roster.h"

void Roster::parse(string StudentData) {
	size_t rhs = StudentData.find(",");
	string SId = StudentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	string FName = StudentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	string LName = StudentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	string SEmail = StudentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	int SAge = stoi(StudentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	int d1 = stod(StudentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	int d2 = stod(StudentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	int d3 = stod(StudentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);

	DegreeProg degree = SECURITY;

	if (StudentData.at(lhs) == 'S' && StudentData.at(lhs + 1) == 'E') degree = SECURITY;
	else if (StudentData.at(lhs) == 'S' && StudentData.at(lhs + 1) == 'O') degree = SOFTWARE;
	else if (StudentData.at(lhs) == 'N') degree = NETWORK;

	add(SId, FName, LName, SEmail, SAge, d1, d2, d3, degree);
}

void Roster::add(string SId, string FName, string LName, string SEmail, int SAge, int d1, int d2, int d3, DegreeProg degree) {
	int da[3] = { d1, d2, d3 };
	classRosterArray[++LastIndex] = new Student(SId, FName, LName, SEmail, SAge, da, degree);
}

void Roster::printAll() {
	cout << "ID" << '\t' << "First" << '\t' << "Last" << '\t' << "Email Address" << '\t' << '\t' << "Age" << '\t' << "Days Left" << '\t' << "Degree" << std::endl << std::endl;
	for (int i = 0; i <= Roster::LastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::remove(string studentID) {

	bool found = false;
	for (int i = 0; i <= Roster::LastIndex; i++) {
		if (classRosterArray[i]->getStudentid() == studentID) {
			found = true;
			if (i < studentDataTable - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[studentDataTable - 1];
				classRosterArray[studentDataTable - 1] = temp;
			}
			Roster::LastIndex--;
		}

	}
	if (found) {
		cout << "Student ID removed\n";
	}
	else cout << "Such a student with this ID was not found.\n";
}

void Roster::printInvalidEmails() {

	for (int i = 0; i <= Roster::LastIndex; i++) {
		string email = (classRosterArray[i]->getEmail());
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
			cout << email << "\n";
		}
	}
}

void Roster::printByDegreeType(DegreeProg degree) {
	for (int i = 0; i <= Roster::LastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProg() == degree) classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::LastIndex; i++) {
		if (classRosterArray[i]->getStudentid() == studentID) {
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3;
			cout << "\n";
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < studentDataTable; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}

}