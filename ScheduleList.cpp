#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "ScheduleList.h"
#include "Schedule.h"
using namespace std;

//constructor
scheduleList::scheduleList()
{
	for (int i = 0; i < MAX_SCHEDULES; i++)
	{
		object[i];
	}

	dupIncrementer = 0;
}

int scheduleList::getNumSchedules()
{
	return numScheds;
}

schedule scheduleList::getSchedule(int index)
{
	if (index >= 0 && index < numScheds)
	{
		return object[index];
	}
	else
	{
		schedule a;
		return a;
	}
}

schedule scheduleList::getSchedule(string id)
{
	schedule a;
	for (int i = 0; i < MAX_SCHEDULES; i++)
	{
		if (id == object[i].getID())
		{
			return object[i];
		}
	}

	return a;
}

void scheduleList::addSchedule(schedule one)
{
	string temp = one.getID();
	for (int i = 0; i < numScheds; i++)
	{
		if (getSchedule(i).getID() == temp)
		{
			object[i] = one;
		}
	}


	if (numScheds < MAX_SCHEDULES)
	{
		object[numScheds] = one;
		numScheds++;
	}
	else
	{
		cout << "ERROR!\n";
	}
	
}

void scheduleList::print()
{
	cout << "=============== ALL SCHEDULES <" << numScheds << "> ===============" << endl;
	cout << "STUID #C COURSE IDS" << endl;
	cout << "----- -- -------------------------------------------" << endl;

	for (int i = 0; i < numScheds; i++) //for loop to iterate through items and print!
	{
		/*	when dropping or adding a course this would work, but when i went to print ALL schedules there would be a 
			duplicated student id with the correct schedule. To counter this I checked the student ID's and if they were
			the same I would have it not print the duplicate.
		*/
		bool a = true;
		for (int j = i + 1; j < numScheds; j++)
		{
			if (object[i].getID() == object[j].getID())
			{
				a = false;
				break;
			}
		}
		if (a == true)
		{
			object[i].print();
			cout << endl;
			
		}
	}

	cout << endl;
	system("pause");
	cout << endl;
}

void scheduleList::read()
{
	//create input file and open it
	ifstream f;
	string inputFile = "schedList.txt";
	f.open(inputFile);

	//declare variables and initialize them
	int numSchedules = 0;


	f >> numSchedules;
	numScheds = numSchedules;

	string stuID, courseID;
	int numC;

	//nested for loop to get data
	for (int i = 0; i < numSchedules; i++)
	{
		schedule temp;
		f >> stuID >> numC;
		temp.setID(stuID);
		for (int j = 0; j < numC; j++) //this loop is for grabbing multiple courses
		{
			f >> courseID;
			temp.addCourse(courseID);
		}

		object[i] = temp;
	}

}

void scheduleList::write()
{
	dupCounter(); //this calls the function to count duplicate ID's

	//open output file and start to format
	ofstream g;
	string outputFile = "schedList_1.txt";
	g.open(outputFile);

	g << (numScheds - dupIncrementer) << endl;
	for (int i = 0; i < (numScheds - dupIncrementer); i++)
	{	
			g << object[i].getID() << " " << object[i].getNumCourses() << " ";

			for (int j = 0; j < object[i].getNumCourses(); j++)
			{
				g << object[i].getCourseID(j) << " ";
			}
			g << endl;
	}

	g.close();
}

//this function is used to count the duplicate ID's found. 
int scheduleList::dupCounter()
{
	bool a = true;

	for (int i = 0; i < numScheds; i++)
	{
		for (int j = i + 1; j < numScheds; j++)
		{
			if (object[j].getID() == object[i].getID())
			{
				dupIncrementer++;
				break;
			}
		}
	}

	return dupIncrementer;
}
