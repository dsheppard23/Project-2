#pragma once
//----------------------------------------------------------------------
//                         course class
//----------------------------------------------------------------------
// this class sets and gets ID, DEPT, courseNum, credits and title
// it also reads the catalog file and prints the catalog 
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class course
{
public:
	course();
	void setID(string newID);
	void setDepartment(string newDepartment);
	void setNumber(int newNumber);
	void setCredits(int newCredits);
	void setTitle(string newTitle);
	string getID();
	string getDeparment();
	int getNumber();
	int getCredits();
	string getTitle();
	void print();

private:
	string id;
	string department;
	int courseNumber;
	int creditHours;
	string title;
};
