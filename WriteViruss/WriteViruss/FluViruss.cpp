#include "stdafx.h"
#include "FluViruss.h"
#include <iostream>

using namespace std;

int bl = 0x0000ff;
int red = 0xff0000;

FluViruss::FluViruss(int color, char * dna, int resistance) : Viruss(dna, resistance)
{
	DoBorn();
	this->m_resistance = InitResistance();
}

FluViruss::~FluViruss()
{
	cout << "Destroy Flu Virus" << endl;
}

void FluViruss::DoBorn()
{
	this->m_dna = LoadADNInformation();

	int min = 0;
	int max = 1;
	int ran = rand() % (max - min + 1) + min;

	if (ran = 0)
	{
		this->m_color = bl;
	}
	else
	{
		this->m_color = red;
	}
}

void FluViruss::DoDie()
{
	if (m_dna != nullptr)
	{
		delete[] m_dna;
	}
}

int FluViruss::InitResistance()
{
	int min = 10;

	if (this->m_color == bl)
	{
		int max = 15;
		this->m_resistance = rand() % (max - min + 1) + min;
	}
	else if (this->m_color == red)
	{
		int max = 20;
		this->m_resistance = rand() % (max - min + 1) + min;
	}
	else
	{
		cout << "Error!" << endl;
	}
	return this->m_resistance;
}
