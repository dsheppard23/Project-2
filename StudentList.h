#pragma once
//----------------------------------------------------------------------
//                         StudentList class
//----------------------------------------------------------------------
//this class prints the student list, searches through the array and 
// reads the stuList file


#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
using namespace std;

const int MAX_STUDENTS = 50;

class studentList
{
public:
	studentList();
	void print();
	student search(string id);
	student search(int index);
	void read();

private:
	student object[MAX_STUDENTS];
	int numStudents;

};
