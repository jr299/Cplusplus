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

struct Student
{
	int id;
	string name;
	float score;
};
typedef struct Student student;

vector<Student> lstudent;

void printMenu();

Student inputStudent();

void displayLStudents(vector<Student> lstudent);

void processMode(int choose);

void saveToFile(string fileName);

void loadFromFile(string fileName);

void replace(string &str, char to, char by);

int choose;

void printMenu()
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

bool isRepeat(vector<Student> lstudent, int ms)
{
	for (int i = 0; i < lstudent.size(); i++)
	{
		if (ms == lstudent[i].id)
		{
			return true;
		}
	}
	return false;
}

Student inputStudent()
{
	Student student;
	int ms;
	do {
		cout << "ID: ";
		cin >> ms;
		if (isRepeat(lstudent, ms))
		{
			cout << "ID you input already exist! Please input again!" << endl;
		}
		else
		{
			student.id = ms;
		}
	} while (isRepeat(lstudent, ms));

	cin.ignore();
	cout << "Name: ";
	getline(cin, student.name);

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
			student.score = d;
		}
	} while (d < 0.0 || d > 10.0);

	return student;
}

void displayInfStudent(Student student)
{
	cout << left << setw(10) << student.id << "|" << setw(15) << student.name << "|" << setw(6) << student.score << "||";
	cout << "\n";
	cout << "||----|----------|---------------|------||" << endl;
}

void displayLStudents(vector<Student> lstudent)
{
	cout << "DANH SACH TAT CA CAC SINH VIEN" << endl;
	cout << "__________________________________________" << endl;
	cout << left << "||" << setw(4) << "STT" << "|" << setw(10) << "ID" << "|" << setw(15) << "Name" << "|" << setw(6) << "Score" << "||" << "\n";
	cout << "||====|==========|===============|======||" << endl;
	for (int i = 0; i < lstudent.size(); i++)
	{
		cout << "||" << setw(4) << i + 1 << "|";
		displayInfStudent(lstudent[i]);
	}
}

void saveToFile(string fileName)
{
	ofstream outFile;
	outFile.open(fileName);
	if (outFile.is_open())
	{
		//save number element
		outFile << lstudent.size() << endl;

		for (int i = 0; i < lstudent.size(); i++)
		{
			Student st = lstudent.at(i);

			string name(st.name);

			replace(name, ' ', '_');

			outFile << st.id << " " << name << " " << st.score << endl;
		}
		outFile.close();
	}
	else
	{
		cout << "Can't open file!" << endl;
	}
}

void loadFromFile(string fileName)
{
	lstudent.clear();

	ifstream inFile;
	inFile.open(fileName);

	if (inFile.is_open())
	{
		int num;

		inFile >> num;

		for (int i = 0; i < num; i++)
		{
			Student st;

			inFile >> st.id;
			inFile >> st.name;
			inFile >> st.score;

			replace(st.name, '_', ' ');

			lstudent.push_back(st);
		}
		inFile.close();

	}
	else
	{
		cout << "can't open file!" << endl;
	}
}

void replace(string &str, char to, char by)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == to)
		{
			str.at(i) = by;
		}
	}
}

void processMode(int)
{
	Student student;
	switch (choose)
	{
	case 1:
		student = inputStudent();
		lstudent.push_back(student);
		break;
	case 2:
		displayLStudents(lstudent);
		break;
	case 3:
		saveToFile("save.txt");
		cout << "File is saved!" << endl;
		break;
	case 4:
		loadFromFile("save.txt");
		cout << "File is loaded!" << endl;
		break;
	}
}

int main()
{
	while (true)
	{
		//Print menu
		printMenu();

		//Input mode
		cin >> choose;
		fflush(stdin);

		//Process mode
		processMode(choose);

		if (choose == 0)
		{
			break;
		}
	}

	system("pause");
	return 0;
}