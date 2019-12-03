#pragma once
//----------------------------------------------------------------------
//                         Menu class
//----------------------------------------------------------------------
// 

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAX_CHARS = 10;

class menu
{
public:
	menu();
	void addOption(char option, string descrip);
	char doMenu();
	bool validOption(char option);
	void setTitle(string newTitle);
	void setErrorMsg(string newError);
private:
	char valMenu[MAX_CHARS];
	string description[MAX_CHARS]; //parrallel partial array
	int num; //incrementer
	string title;
	string error;
};
