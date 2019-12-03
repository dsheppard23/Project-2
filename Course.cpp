#include <iomanip>
#include <string>
#include <iostream>
#include "Course.h"
using namespace std;

//constructor
course::course()
{
	id = "";
	department = "";
	courseNumber = 0;
	creditHours = 0;
	title = "";
}

//set ID, Department, Number, Credits and Title
void course::setID(string newID)
{
	id = newID;
}

void course::setDepartment(string newDepartment)
{
	department = newDepartment;
}

void course::setNumber(int newNumber)
{
	courseNumber = newNumber;
}

void course::setCredits(int newCredits)
{
	if (newCredits <= 0)
	{
		creditHours = 0;
	}
	else
	{
		creditHours = newCredits;
	}
}

void course::setTitle(string newTitle)
{
	title = newTitle; //use getline in cin to get spaces
}

//get ID, Department, Number, Credits and Title
string course::getID()
{
	return id;
}

string course::getDeparment()
{
	return department;
}

int course::getNumber()
{
	return courseNumber;
}

int course::getCredits()
{
	return creditHours;
}

string course::getTitle()
{
	return title;
}

//print 
void course::print()
{
	cout << setw(5) << id << " " << setw(4) << left << department << " " << setw(4) << left << courseNumber << " " << setw(3) << right << creditHours << " " << setw(20) << left << title << endl;
}
