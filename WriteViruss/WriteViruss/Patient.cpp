#include "stdafx.h"
#include "Patient.h"


Patient::Patient()
{
}

Patient::Patient(int resistance, list<Viruss*> viruslist, int state)
{
	this->m_resistance = resistance;
	this->m_virusList = viruslist;
	this->m_state = state;
}


Patient::~Patient()
{
}

int Patient::InitResistance()
{
	int min = 1000;
	int max = 9000;
	return this->m_resistance = rand() % (max - min + 1) + min;
}
