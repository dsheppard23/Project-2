#pragma once
//----------------------------------------------------------------------
//                         schedule class
//----------------------------------------------------------------------
// this class sets and gets ID, adds and drops courses and prints a students schedule

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAX_Courses = 50;

class schedule
{
public:
	schedule();
	void setID(string newID);
	string getCourseID(int index);
	string getID();
	int getNumCourses();
	int addCourse(string addCourseID);
	int dropCourse(string dropCourseID);
	void print();

private:
	string studentID;
	string courseID[MAX_Courses];
	int numCourses;
};
