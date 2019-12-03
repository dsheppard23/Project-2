#include <iomanip>
#include <iostream>
#include <string>
#include "Schedule.h"
using namespace std;

//constructor
schedule::schedule()
{
	studentID = "";
	numCourses = 0;

	//for loop to initialize string array
	for (int i = 0; i < MAX_Courses; i++)
	{
		courseID[i] = "";
	}
}

void schedule::setID(string newID)
{
	studentID = newID;
}

string schedule::getCourseID(int index)
{
	//cout << numCourses << endl;
	if (index >= 0 && index < numCourses)
	{
		return courseID[index];
	}
	else
	{
		string a = "";
		return a;
	}
}

string schedule::getID()
{
	return studentID;
}

int schedule::getNumCourses()
{
	return numCourses;
}

//addcourse method
int schedule::addCourse(string addCourseID)
{
	if (numCourses < MAX_Courses)
	{
		courseID[numCourses] = addCourseID;
		numCourses++;
		return 0;
	}
	else
	{
		return -1;
	}
}

//drop method
int schedule::dropCourse(string dropCourseID) 
{
	for (int i = 0; i < numCourses; i++)
	{
		if (courseID[i] == dropCourseID) //validate the course is found
		{
			courseID[i] = ""; // delete the ID
			for (; i < numCourses; i++)
			{
				courseID[i] = courseID[i + 1];
				courseID[i + 1] = "";
			}
			
			numCourses--;
			return 0;
		}
		
	}
	return -1;
}

//print method
void schedule::print()
{
	cout << setw(5) << left << studentID << " " << setw(2) << right << numCourses << " ";
	for (int i = 0; i < numCourses; i++)
	{
		cout << courseID[i] << " ";
	}
}
