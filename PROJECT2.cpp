// PROJECT2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PROJECT2.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	while (1)
	{
		string command;
		cout << "write a function" << endl;
		cin >> command;

		if (command == "ImportFile")
		{
			string namefile;
			cout << "write the file name" << endl;
			cin >> namefile;
			ImportFile(namefile);
		}
		else if (command == "Exit")
		{
			Exit;
			exit;

		}
		else if (command == "SaveFile")
		{
			string namefile;
			cout << "write the file name" << endl;
			cin >> namefile;
			SaveFile(namefile);
		}
		else if (command == "PrintAll")
		{
			PrintAll();
		}
		else if (command == "ListLevels")
		{
			LEVELs* headl = NULL;
			ListLevels(headl);
		}
		else if (command == "List_in_Level")
		{
			LEVELs* headl = NULL;
			int n = 0;
			cout << "number of the level=" << endl;
			cin >> n;
			List_in_Level(headl, n);
		}
		else if (command == "add")
		{
			STUDENT* add(STUDENT * head, STUDENT * n);
		}
		else if (command == "set_name")
		{
			STUDENT* set_name(STUDENT * heads, LEVELs * headl, int ids, char* name[64]);
		}
		else if (command == "set_address")
		{
			STUDENT* set_address(STUDENT * heads, LEVELs * headl, int ids, char* address[64]);
		}
		else if (command == "set_major")
		{
			STUDENT* set_major(STUDENT * heads, LEVELs * headl, int ids, char* major[64]);
		}
		else if (command == "set_age")
		{
			STUDENT* set_age(STUDENT * heads, LEVELs * headl, int ids, int ages);
		}
		else if (command == "Delete")
		{
			STUDENT* Delete(STUDENT * heads, int idd);
		}
		else if (command == "set_level")
		{
			void set_level(LEVELs * headl, int idset, int level);
		}
		else
			cout << "try again and be careful" << endl;
	}
}

	