// MyPointOOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyPoint.h"
#include <iostream>

using namespace std;

int main()
{
	MyPoint *p0 = new MyPoint();
	MyPoint *p1 = new MyPoint();
	p1->SetX(1);
	p1->SetY(1);

	cout << "p0";
	p0->Display();

	cout << "p1";
	p1->Display();

	cout << "Distance between current point and p1: " << p0->Distance(*p1) << endl;

	delete p0;
	cout << " p0" << endl;
	delete p1;
	cout << " p1" << endl;

	system("pause");
    return 0;
}

