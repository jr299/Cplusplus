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

Student inputStudent()
{
	Student student;

	cout << "ID: ";
	cin >> student.id;
	//clean buffer
	fflush(stdin);

	cin.ignore();
	cout << "Name: ";
	getline(cin, student.name);
	//clean buffer
	fflush(stdin);

	cout << "Score: ";
	cin >> student.score;
	//clean buffer
	fflush(stdin);

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

void saveInfStudent(ofstream &fileout, Student student)
{
	string id = "id";
	string name = "name";
	string score = "score";
	fileout << id << ":" << student.id << "," << name << ":" << student.name << "," << score << ":" << student.score << endl;
}

void saveToFile(string filename, vector<Student> lstudent)
{
	ofstream fileout;
	fileout.open(filename);
	if (fileout.is_open())
	{
		fileout << "  DANH SACH TAT CA CAC SINH VIEN  " << endl;
		fileout << "==================================" << endl;

		for (int i = 0; i < lstudent.size(); i++)
		{
			saveInfStudent(fileout, lstudent[i]);
		}
		fileout.close();
	}
	else
	{
		cout << "Can't open file !" << endl;
	}

}

void loadInfStudent(ifstream &filein, Student student)
{
	string id = "id";
	string name = "name";
	string score = "score";
	getline(filein, id, ':');
	filein >> student.id;
	getline(filein, name, ':');
	getline(filein, student.name, ',');
	getline(filein, score, ':');
	filein >> student.score;
}

void loadFile(string filename, vector<Student> lstudent)
{
	lstudent.clear();

	ifstream filein;
	filein.open(filename);
	if (filein.is_open())
	{
		while (filein.eof() == false)
		{
			string temp;
			Student student;
			loadInfStudent(filein, student);
			getline(filein, temp);
			lstudent.push_back(student);
		}
	}
	else
	{
		cout << "Can't open file !" << endl;
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
		saveToFile("liststudent.txt", lstudent);
		cout << "File is saved!" << endl;
		break;
	case 4:
		loadFile("liststudent.txt", lstudent);
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

