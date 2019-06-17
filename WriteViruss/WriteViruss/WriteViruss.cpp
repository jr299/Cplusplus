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
		cout<<"Take Medicine (0 = No, 1 = YES";
		cin >> t;
		if (t == 1)
		{
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			p->TakeMedicine(medicine_resistance);
		}
	}
	system("pause");
    return 0;
}

