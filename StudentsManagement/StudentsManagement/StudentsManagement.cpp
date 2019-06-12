// StudentsManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define SMAX 100
#define NFILE "save.txt"

struct Student
{
	int id;
	string name;
	float score;
};
typedef struct Student student;

int choose;

Student *lstudent = new Student[SMAX];
Student *pstudent = lstudent;

void PrintMenu();
bool IsRepeat(int ms);
void InputStudent();
void DisplayInfStudent(Student student);
void DisplayStudent();
void SaveToFile(string fileName);
void LoadFromFile(string fileName);
void Replace(string &str, char to, char by);
void ProcessMode(int);


int len = sizeof(lstudent) / sizeof(lstudent[0]);

void PrintMenu()
{
	cout << "------------------MENU------------------" << endl;
	cout << "    1. Input" << endl;
	cout << "    2. Display" << endl;
	cout << "    3. Save to file" << endl;
	cout << "    4. Load from file" << endl;
	cout << "    0. Exit" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Choose: ";
}

int IDStudent(Student student)
{
	return student.id;
}

bool IsRepeat(int ms)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (ms == IDStudent(lstudent[i]))
		{
			return true;
		}
	}
	return false;
}

void InputStudent()
{
	pstudent = &lstudent[len++];

	int ms;
	do {
		cout << "ID: ";
		cin >> ms;
		if (IsRepeat(ms))
		{
			cout << "ID you input already exist! Please input again!" << endl;
		}
		else
		{
			pstudent->id = ms;
		}
	} while (IsRepeat(ms));

	cin.ignore();
	cout << "Name: ";
	getline(cin, pstudent->name);

	float d;
	do {
		cout << "Score: ";
		cin >> d;

		if (d < 0.0 || d > 10.0)
		{
			cout << "You input wrong! Please input again!" << endl;
		}
		else
		{
			pstudent->score = d;
		}
	} while (d < 0.0 || d > 10.0);
}

void DisplayInfStudent(Student student)
{
	cout << left << setw(10) << student.id << "|" << setw(15) << student.name << "|" << setw(6) << student.score << "||";
	cout << "\n";
	cout << "||----|----------|---------------|------||" << endl;
}

void DisplayStudent()
{
	cout << "List of all student" << endl;
	cout << "__________________________________________" << endl;
	cout << left << "||" << setw(4) << "STT" << "|" << setw(10) << "ID" << "|" << setw(15) << "Name" << "|" << setw(6) << "Score" << "||" << "\n";
	cout << "||====|==========|===============|======||" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "||" << setw(4) << i + 1 << "|";
		DisplayInfStudent(lstudent[i]);
	}
}

void SaveToFile(string fileName)
{
	ofstream outFile;
	outFile.open(fileName);
	if (outFile.is_open())
	{
		//save number
		outFile << len << endl;
		
		for (int i = 0; i < len; i++)
		{
			pstudent = &lstudent[i];

			string name(pstudent->name);
			Replace(name, ' ', '_');


			outFile << pstudent->id << " " << name << " " << pstudent->score << endl;
		}

		outFile.close();
	}
	else
	{
		cout << "Can't open file!" << endl;
	}
}

void LoadFromFile(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);

	if (inFile.is_open())
	{

		inFile >> len;

		for (int i = 0; i < len; i++)
		{
			pstudent = &lstudent[i];
			inFile >> (pstudent)->id;

			string name;
			inFile >> name;
			Replace(name, '_', ' ');
			(pstudent)->name = name;

			inFile >> (pstudent)->score;
		}

		inFile.close();
	}
	else
	{
		cout << "Can't open file!" << endl;
	}
}

void Replace(string &str, char to, char by)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == to)
		{
			str.at(i) = by;
		}
	}
}

void ProcessMode(int)
{
	switch (choose)
	{
	case 1:
		InputStudent();
		break;
	case 2:
		DisplayStudent();
		break;
	case 3:
		SaveToFile(NFILE);
		cout << "File is saved!" << endl;
		break;
	case 4:
		LoadFromFile(NFILE);
		cout << "File is loaded!" << endl;
		DisplayStudent();
		break;
	case 0:
		cout << "Goodbye!" << endl;
		break;
	default:
		cout << "Mode isn't available!" << endl;
		break;
	}
}

int main()
{
	while (true)
	{
		//Print menu
		PrintMenu();

		//Input mode
		cin >> choose;

		//Process mode
		ProcessMode(choose);

		if (choose == 0)
		{
			delete[] lstudent;

			break;
		}

	}
	system("pause");
	return 0;
}