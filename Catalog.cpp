#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include "Catalog.h"
using namespace std;

//constructor
catalog::catalog()
{
	for (int i = 0; i < MAX_COURSES; i++)
	{
		objects[i];
	}

	numCourses = 0;
}

//getNumCourses
int catalog::getNumCourses()
{
	return numCourses;
}

//get course function
course catalog::getCourse(int num)
{
	if (num < numCourses || num >= 0)
	{
		//return course 
		course a = objects[num];
		return a;
	}
	else
	{
		//return empty course
		course b;
		return b;
	}
}

//search function
int catalog::search(string numID)
{
	for (int i = 0; i < numCourses; i++)
	{
		if (objects[i].getID() == (numID))  //course is found
		{
			return i;
		}
	}
	//course is not found
	return -1;
}

//print function
void catalog::print()
{
	cout << endl;


	cout << "=============== COURSE CATALOG ===============" << endl;
	cout << setw(5) << left << "ID" << " " << setw(4) << left << "DEPT" << " " << setw(4) << left << "NUMB" << " " << setw(3) << right << "HRS" << " " << setw(20) << left << "TITLE" << endl;
	cout << "----- ---- ---- --- --------------------" << endl;
	//for loop
	for (int i = 0; i < numCourses - 1; i++)
	{
		objects[i].print();
	}

	cout << "=========== # Courses Listed: " << numCourses - 1 << " ===========" << endl; // input numcourses once read function is complete along with for loop

	cout << endl;
	system("pause");
	cout << endl;
}

//read function for catalog.txt and also used again in print
void catalog::read()
{
	//create input file variable and open it
	ifstream f;
	string inputfile = "Catalog.txt";
	f.open(inputfile);

	//declare variables and intialize them
	string ID;
	string department;
	string title;
	int courseNumber;
	int creditHours = 1;
	
	while (creditHours != -1) {

		//get files input
		f >> ID >> department >> courseNumber >> creditHours;
		
		getline(f, title); //titles contain spaces
		if (creditHours == -1)
		{
			return;
		}
		//in partial array of objects, collect data and put them into gets
		objects[numCourses].setID(ID);
		objects[numCourses].setDepartment(department);
		objects[numCourses].setNumber(courseNumber);
		objects[numCourses].setCredits(creditHours);
		objects[numCourses].setTitle(title); //title may contain spaces
		numCourses++;
	}

}
