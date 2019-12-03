//--------------------------------------------------------
//                    CS 215 - Fall 2018
//               Project 3: The New Link Blue
//--------------------------------------------------------
// Name: Dillon Sheppard
// Date: 11/18/19


#include <iostream>
#include "userint.h"

int main() {
	// create the app and start it!
	userint x;
	x.go();
	system("pause");
	return 0;
}


#include <iomanip>
#include <iostream>
#include <string>
#include "Menu.h"
using namespace std;

//constructor
menu::menu()
{
	num = 0;
	title = "";
	error = "";
}

//set error message
void menu::setErrorMsg(string newError)
{
	error = newError;
}

//set title to later be printed
void menu::setTitle(string newTitle)
{
	title = newTitle;
}

//add option function
void menu::addOption(char option, string descrip)
{
	if (num < MAX_CHARS) //there is enough room in the array
	{
		valMenu[num] = option;
		description[num] = descrip;
		num++;
	}
	else
	{
		cout << "no room for more options" << endl;
	}
}

//do menu
char menu::doMenu()
{
	cout << title << endl;
	//for loop to print the partial array of options and descriptions
	for (int i = 0; i < num; i++)
	{
		cout << valMenu[i] << " - " << description[i] << endl;
	}

	//validate the user is entering the correct data
	char in;
	string temp;
	cout << "Enter an option: ";
	cin >> temp;

	in = temp[0];	//used to get simply the first letter of the string
	in = toupper(in);	//uppercase the input

	if (validOption(in) == true)
	{
		return in;
	}
	else
	{
		while (validOption(in) == false)
		{
			cout << error << endl;
			cout << "Enter an option: ";
			cin >> in;
			in = toupper(in);
			if (validOption(in) == true)
			{
				return in;
				break;
			}

		}
	}
	
}

bool menu::validOption(char option)
{
	for (int i = 0; i < num; i++)
	{
		if (valMenu[i] == option)
		{
			return true;
		}
	}
	return false;
}
