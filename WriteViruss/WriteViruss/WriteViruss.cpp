// WriteViruss.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "Patient.h"
#include <iostream>

using namespace std;

int main()
{
	Patient *p = new Patient();
	int t;
	while (p->GetState() == 1)
	{
		cout<<"Take Medicine (1: YES / OTHER: EXIT): ";
		cin >> t;
		if (t == 1)
		{
			int medicine_resistance = rand() % 60 + 1;
			p->TakeMedicine(medicine_resistance);
		}
		else
		{
			break;
		}
	}
	delete p;
	p = NULL;
	system("pause");
    return 0;
}

