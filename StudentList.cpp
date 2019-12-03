#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include "StudentList.h"
#include "Student.h"
using namespace std;

//constructor
studentList::studentList()
{
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		object[i];
	}

	numStudents = 0;
}

//print fuction
void studentList::print()
{
	cout << "=============== STUDENT LIST <" << numStudents << "> ===============" << endl;
	cout << "IDNUM HRS" << " " << setw(15) << left << "LAST " << " " << setw(15) << left << "FIRST" << endl;
	cout << "----- --- --------------- ---------------" << endl;

	//will have to get data from the file read first then come back to implement it into function
	for (int i = 0; i < numStudents; i++)
	{
		object[i].print();
	}

	cout << endl;
	system("pause");
	cout << endl;
}

//search function by string ID
student studentList::search(string ID)
{
	for (int i = 0; i < numStudents; i++)
	{
		if (ID == object[i].getID()) //student ID is found
		{
			return object[i];
		}
	}

	student a;  //empty student
	return a;
}

//search function by index
student studentList::search(int index)
{
	if (index >= 0 && index < numStudents) // index is in range
	{
		return object[index-1];
	}
	else //index is not in range return empty student
	{
		student empty;
		return empty; //return empty object
	}
}

//read function
void studentList::read()
{
	//create input file variable and open it
	ifstream g;
	string inputFile = "stuList.txt";
	g.open(inputFile);

	//declare variables and initialize them
	int students = 0;
	string id = "";
	string last = "";
	string first = "";
	int credits = 0;

	g >> students;
	numStudents = students;
	//read the file into variables using for Loop
	for (int i = 0; i < students; i++)
	{
		g >> id >> last >> first >> credits;
		object[i].setID(id);
		object[i].setLastName(last);
		object[i].setFirstName(first);
		object[i].setCredits(credits);
	}
}	
