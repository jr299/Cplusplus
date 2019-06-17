#pragma once
#include "Viruss.h"
#include <list>
#include "FluViruss.h"
#include "DengueViruss.h"

using namespace std;

class Patient
{
private:
	int m_resistance;
	list <Viruss*> m_virusList;
	int m_state;

public:
	Patient();
	Patient(int, list <Viruss *>, int);
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int medicine_resistance);
	void DoDie();
	int GetState();
};

