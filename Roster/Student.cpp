#include "student.h"

Student::Student() {
	this->Studentid = "";
	this->FirstName = "";
	this->LastName = "";
	this->Email = "";
	this->age = 0;
	for (int i = 0; i < Days; i++) this->DaysLeft[i] = DaysLeft[i];
	this->degreeProg = DegreeProg::SECURITY;
}

Student::Student(string Studentid, string FirstName, string LastName, string Email, int age, int DaysLeft[], DegreeProg degreeProg) {
	this->Studentid = Studentid;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->Email = Email;
	this->age = age;
	for (int i = 0; i < Days; i++) this->DaysLeft[i] = DaysLeft[i];
	this->degreeProg = degreeProg;
}

Student::~Student() {}

string Student::getStudentid() {
	return this->Studentid;
}
string Student::getFirstName() {
	return this->FirstName;
}
string Student::getLastName() {
	return this->LastName;
}
string Student::getEmail() {
	return this->Email;
}
int Student::getAge() {
	return this->age;
}
int* Student::getDays() {
	return this->DaysLeft;
}
DegreeProg Student::getDegreeProg() {
	return this->degreeProg;
}

void Student::setStudentid(int Studentid) {
	this->Studentid = Studentid;
}
void Student::setFirstName(string FirstName) {
	this->FirstName = FirstName;
}
void Student::setLastName(string LastName) {
	this->LastName = LastName;
}
void Student::setEmail(string email) {
	this->Email = Email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDays(int DaysLeft[]) {
	for (int i = 0; i < Days; i++) this->DaysLeft[i] = DaysLeft[i];
}
void Student::setDegreeProg(DegreeProg degree) {
	this->degreeProg = degree;
}


void Student::print() {
	cout << this->getStudentid() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ", ";
	cout << this->getDays()[1] << ", ";
	cout << this->getDays()[2] << '\t';
	cout << DegreeProgStrings[this->getDegreeProg()] << "\n";
}