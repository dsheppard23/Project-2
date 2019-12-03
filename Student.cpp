#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
using namespace std;

//constructor
student::student()
{
	id = "";
	firstName = "";
	lastName = "";
	creditHours = 0;
}

//Set ID Names and Credits
void student::setCredits(int newCreditHours)
{
	creditHours = newCreditHours;
}

void student::setFirstName(string newFirstName)
{
	firstName = newFirstName;
}

void student::setLastName(string newLastName)
{
	lastName = newLastName;
}

void student::setID(string newID)
{
	id = newID;
}

//get ID, Names and Credits
string student::getID() 
{
	return id;
}

string student::getFirstName()
{
	return firstName;
}

string student::getLastName()
{
	return lastName;
}

int student::getCredits()
{
	return creditHours;
}

void student::print() //print 
{
	cout << setw(5) << left << id << " " << setw(3) << right << creditHours << " " << setw(15) << left << lastName << " " << setw(15) << left << firstName << endl;

}
