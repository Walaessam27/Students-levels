#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct STUDENT {
	char name[64] = "";
	char address[64] = "";
	char major[64] = "";
	int id = 0;
	int age = 0;
	int level = 0;
	STUDENT* next_student = NULL;
};

struct LEVELs {
	int id = 0;
	int level = 0;
	STUDENT* head_student = NULL;
	LEVELs* next_level = NULL;
};

STUDENT* add(STUDENT* head, STUDENT* n)
{
	cout << "write n=";
	cin >> n->id;
	STUDENT* p1, * p2 = NULL;
	if (head == NULL) {
		head = n;
		return head;
	}
	if (n->id < head->id)
	{
		n->next_student = head;
		head = n;
		return head;
	}
	p1 = p2 = head;
	while (p2 != NULL)
	{
		if (n->id < p2->id)
		{
			n->next_student = p2;
			p1->next_student = n;
			return head;
		}
		else
		{
			p1 = p2;
			p2 = p2->next_student;
		}

	}
	n->next_student = p2;
	p1->next_student = n;
	return head;
}
STUDENT* set_name(STUDENT* heads, LEVELs* headl, int ids,char *name[64])
{
	cout << "write id and name=";
	cin >> ids >> name[64];
	STUDENT* p1 = heads;
	LEVELs* p2 = headl;
	int s = 0;
	while (p2 != NULL)//level
	{
		if (p1 == NULL)
		{
			p1->id = ids;
			strcpy(p1->name, name[64]);
			break;
		}
		while (p1 != NULL)//student
		{ if (p1->id == ids)
			{
				strcpy(p1->name, name[64]);
				break;
			}
			else p1->next_student;
		}
		p2 = p2->next_level;
	}
	if (s == 0)
	{
		cout << "there is no id =" << ids << endl;
	}
}
STUDENT* set_address(STUDENT* heads, LEVELs* headl, int ids, char* address[64])
{
	cout << "write id and address=";
	cin >> ids >> address[64];
	STUDENT* p1 = heads;
	LEVELs* p2 = headl;
	int s = 0;
	while (p2 != NULL)//level
	{
		if (p1 == NULL)
		{
			p1->id = ids;
			strcpy(p1->name, address[64]);
			break;
		}
		
		while (p1 != NULL)//student
		{ if (p1->id == ids)
			{
				strcpy(p1->name, address[64]);
				break;
			}
			else p1->next_student;
		}
		p2 = p2->next_level;
	}
	if (s == 0)
	{
		cout << "there is no id =" << ids << endl;
	}
}
STUDENT* set_major(STUDENT* heads, LEVELs* headl, int ids, char* major[64])
{
	cout << "write id and major=";
	cin >> ids >> major[64];
	STUDENT* p1 = heads;
	LEVELs* p2 = headl;
	int s = 0;
	
	while (p2 != NULL)//level
	{
		if (p1 == NULL)
		{
			p1->id = ids;
			strcpy(p1->name, major[64]);
			break;
		}
		while (p1 != NULL)//student
		{
			if (p1->id == ids)
			{
				strcpy(p1->name, major[64]);
				break;
			}
			else p1->next_student;
		}
		p2 = p2->next_level;
	}
	if (s == 0)
	{
		cout << "there is no id =" << ids << endl;
	}
}
STUDENT* set_age(STUDENT* heads, LEVELs* headl, int ids, int ages)
{ 
	cout << "write id and the age=";
	cin >> ids >> ages;
	STUDENT* p1 = heads;
	LEVELs* p2 = headl;
	int s = 0;
	while (p2 != NULL)//level
	{
		if (p1 == NULL)
		{
			p1->id = ids;
			p1->age = ages;
			break;
		}
		while (p1 != NULL)//student
		{
			 if (p1->id == ids)
			{
				p1->age = ages;
				s = 1;
				break;
			}
			else p1->next_student;
		}
		p2 = p2->next_level;
	}
	if (s == 0)
	{
		cout << "there is no id =" << ids << endl;
	}
}
STUDENT* Delete(STUDENT* heads, int idd)
{
	cout << "write id=";
	cin >> idd;
	LEVELs* p2 = NULL;
	int s = 0;
	while (p2 != NULL)//level
	{
		if (heads == NULL)
		{
			cout << "there is nothing to delete" << endl;
		}
		STUDENT* p1, * p3, * temp = heads;
		while (p1 != NULL)//student
		{
			if (heads->id == idd)
			{
				heads = heads->next_student;
				s = 1;
				delete temp;
				return heads;
			}
			while (temp != NULL)
			{
				if (temp->id == idd)
				{
					p3->next_student = temp->next_student;
					s = 1;
					delete temp;
					return heads;
				}
				else
				{
					p3 = temp;
					temp = temp->next_student;
				}
			}p1 = p1->next_student;
		}
		p2 = p2->next_level;
	}
	if (s == 0)
	{
		cout << "there is no id =" << idd << endl;
	}

}
void set_level(LEVELs* headl, int idset, int level)
{
	cout << "write id and the level=";
	cin >> idset >> level;
	LEVELs* p1 = headl;
	STUDENT* p2 = p1->head_student;
	STUDENT* p3 = p1->head_student;
	STUDENT* headset;
	while (p1 != NULL) {
		p2 = p1->head_student;
		while (p2 != NULL)
		{
			if (p2->id == idset)
			{
				p3 = p2;
				headset = p1->head_student;
			}
			p2 = p2->next_student;
		}
		p1 = p1->next_level;
	}

	p1 = headl;
	p2 = p1->head_student;
}
void Exit()
{
	STUDENT* ps;
	LEVELs* pl;
	ofstream output1("StudentFile.txt", ios::out);
	while (pl != NULL)//level
	{
		while (ps != NULL)//student
		{
			output1 << ps->name << ps->address << ps->major << ps->id << ps->age << ps->level << endl;
			 ps->next_student;
		}
		pl = pl->next_level;
	}
}
void ImportFile(string namefile)
{
	STUDENT* ps;
	LEVELs* pl;
	ifstream input1(namefile, ios::in);
	while (pl != NULL)//level
	{
		while (ps != NULL)//student
		{
			input1 >> ps->name >> ps->address >> ps->major >> ps->id >> ps->age >> ps->level;
			ps->next_student;
		}
		pl = pl->next_level;
	}
}
void SaveFile(string namefile)
{
	STUDENT* ps;
	LEVELs* pl;
	ofstream output1("output1.txt", ios::out);
	while (pl != NULL)//level
	{
		while (ps != NULL)//student
		{
			output1 << ps->name << ps->address << ps->major << ps->id << ps->age << ps->level << endl;
			ps->next_student;
		}
		pl = pl->next_level;
	}
}
STUDENT* PrintAll()
{
	STUDENT* ps;
	LEVELs* pl;
	while (pl != NULL)//level
	{
		while (ps != NULL)//student
		{
			cout << ps->name << ps->address << ps->major << ps->id << ps->age << ps->level << endl;
			ps->next_student;
		}
		pl = pl->next_level;
	}
}
LEVELs* ListLevels(LEVELs* headl)
{
	int s = 0;
	LEVELs* p;
	while (p != NULL)//levels
	{
		cout << p->level << endl;
		s++;
	}
	p = p->next_level;
	cout << "the number of available levels is=" << s << endl;
}
LEVELs* List_in_Level(LEVELs* headl,int n)
{   
	LEVELs* p;
	STUDENT* p1;
	while (p != NULL)//levels
	{
		if (p->level == n)
		{
			while (p1 != NULL)
			{
				cout << p1->name << p1->address << p1->major << p1->id << p1->age << p1->level << endl;
			}
		}
		else 
	    p = p->next_level;
	}
	
	
}
 
