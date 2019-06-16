#pragma once
#include "Viruss.h"
#include <list>

using namespace std;

class Patient
{
private:
	int m_resistance;
	list <Viruss *> m_virusList;
	int m_state;

public:
	static int medicine_resistance;

public:
	Patient();
	Patient(int, list <Viruss *>, int);
	~Patient();
	int InitResistance();
	void DoStart();
	void TakeMedicine(int medicine_resistance);
	void ReduceResistance(int medicine_resistance);
	void DoDie();
	int GetState();
};

