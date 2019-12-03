#pragma once
//----------------------------------------------------------------------
//                         Catalog class
//----------------------------------------------------------------------
// this class sets, gets and prints ID, Department, Number, Credits
// and Titles for courses

#include <iomanip>
#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

const int MAX_COURSES = 50;
const int CRS_NOT_FOUND = -1;

class catalog
{
public:
	catalog();
	int getNumCourses();
	course getCourse(int num);
	int search(string numID);
	void print();
	void read();

private:
	course objects[MAX_COURSES];
	int numCourses;
};
