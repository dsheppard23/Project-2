#pragma once
//----------------------------------------------------------------------
//                         ScheduleList class
//----------------------------------------------------------------------
// this class gets numSchedules, prints schedules list, writes a new file
// searches through schedules using id and index
#include <iomanip>
#include <iostream>
#include <string>
#include "Schedule.h"
using namespace std;

const int MAX_SCHEDULES = 50;

class scheduleList
{
public:
	scheduleList();
	int getNumSchedules();
	schedule getSchedule(int index);
	schedule getSchedule(string id);
	void addSchedule(schedule one);
	void print();
	void read();
	void write();
	int dupCounter();

private:

	schedule object[MAX_SCHEDULES];
	int numScheds;
	int dupIncrementer;
};
