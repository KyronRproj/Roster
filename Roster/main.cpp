#include <iostream>
#include "roster.h"
using namespace std;
int main() {
	cout << "Class: Scripting and Programming - Applications - C867\nPrograming language: C++\nWGU student ID: 002954557\nName: Kyron Royster\n\n";

	Roster classRoster;

	const string Data[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erikson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Kyron,Royster,kroys10@wgu.edu,24,0,52,51,SOFTWARE"
	};

	const int DataSize = 5;
	for (int i = 0; i < DataSize; i++) classRoster.parse(Data[i]);
	classRoster.printAll();
	cout << std::endl;
	cout << "Invalid Emails:\n";
	classRoster.printInvalidEmails();
	cout << std::endl;
	cout << "Average number of days left catagorized by Student ID:\n";
	for (int i = 0; i < DataSize; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentid());
	}
	cout << std::endl;
	classRoster.printByDegreeType(SOFTWARE);
	cout << std::endl;
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
}

