#pragma once
#include<string>
#ifndef student_h
#define student
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "degree.h"
using std::string;
using std::cout;

class Student {
public:
	const static int Days = 3;
private:
	string Studentid;
	string FirstName;
	string LastName;
	string Email;
	int age;
	int DaysLeft[Days];
	DegreeProg degreeProg;
public:
	Student();
	Student(string Studentid, string FirstName, string LastName, string Email, int age, int DaysLeft[], DegreeProg degreeProg);
	~Student();

	string getStudentid();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeProg getDegreeProg();

	void setStudentid(int Studentid);
	void setFirstName(string FirstName);
	void setLastName(string LastName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int DaysLeft[]);
	void setDegreeProg(DegreeProg degree);
	void print();

};


#endif