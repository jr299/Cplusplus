#pragma once
class MyPoint
{
public:
	MyPoint();
	MyPoint(int, int);
	void Display();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	float Distance(MyPoint &);
	~MyPoint();
private:
	int mPosX;
	int mPosY;
};

