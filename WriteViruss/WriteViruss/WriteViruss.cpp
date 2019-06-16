// WriteViruss.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>
#include "Patient.h"


int main()
{
	Patient p;
	char t = 0;
	while (p.GetState == 1)
	{
		printf("Take Medicine (0 = No, 1 = YES");
		scanf("%c", &t);
		if (t == 1)
		{
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			p.TakeMedicine(medicine_resistance);
		}
	}
	system("pause");
    return 0;
}

