#pragma once
//----------------------------------------------------------------------
//                         student class
//----------------------------------------------------------------------
// this class sets and gets the students name, ID and credits

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


  class student
{
public:
	student();
	string getID();
	string getFirstName();
	string getLastName();
	int getCredits();
	void setID(string newID);
	void setFirstName(string newFirst);
	void setLastName(string newLast);
	void setCredits(int newCreditHours);
	void print();

private:
	string id;
	string firstName;
	string lastName;
	int creditHours;
};
