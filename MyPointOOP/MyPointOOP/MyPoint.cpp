#include "stdafx.h"
#include "MyPoint.h"
#include <math.h>
#include <string>
#include <iostream>


MyPoint::MyPoint()
{
	this->mPosX = 0;
	this->mPosY = 0;
}

MyPoint::MyPoint(int x, int y)
{
	this->mPosX = x;
	this->mPosY = y;
}


void MyPoint::Display()
{
	printf("(%d;%d)\n", this->mPosX, this->mPosY);
}

void MyPoint::SetX(int x)
{
	this->mPosX = x;
}

int MyPoint::GetX()
{
	return this->mPosX;
}

void MyPoint::SetY(int y)
{
	this->mPosY = y;
}

int MyPoint::GetY()
{
	return this->mPosY;
}

float MyPoint::Distance(MyPoint &p)
{
	return sqrt(pow((this->mPosX - p.GetX()), 2) + pow((this->mPosY - p.GetY()), 2));
}

MyPoint::~MyPoint()
{
	std::cout << "Destructor" ;
}
