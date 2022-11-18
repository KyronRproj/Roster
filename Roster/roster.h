#pragma once
#include "student.h"
#ifndef roster_h
#define roster_h
#include <stdio.h>

class Roster {
public:
	int LastIndex = -1;
	const static int studentDataTable = 5;
	Student* classRosterArray[studentDataTable];
	void parse(string StudentData);
	void add(string SId, string FName, string LName, string SEmail, int SAge, int d1, int d2, int d3, DegreeProg degree);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void remove(string studentID);
	void printByDegreeType(DegreeProg degree);
	~Roster();
};



#endif