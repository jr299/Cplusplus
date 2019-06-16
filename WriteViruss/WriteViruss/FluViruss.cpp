#include "stdafx.h"
#include "FluViruss.h"
#include <iostream>

using namespace std;

int bl = 0x0000ff;
int red = 0xff0000;

FluViruss::FluViruss()
{
	this->m_color = 0x000000;
	this->m_dna = NULL;
	this->m_resistance = 0;
}

FluViruss::FluViruss(int color, char * dna, int resistance) : Viruss(dna, resistance)
{
	DoBorn();
	this->m_resistance = InitResistance();
}

FluViruss::~FluViruss()
{
	DoDie();
	cout << "Destroy Flu Virus" << endl;
}

void FluViruss::SetColor(int color)
{
	this->m_color = color;
}

int FluViruss::GetColor()
{
	return this->m_color;
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

Viruss FluViruss::DoClone()
{
	FluViruss *vr = new FluViruss();

	vr->m_color = this->m_color;
	vr->m_dna = this->m_dna;
	vr->m_resistance = this->m_resistance;

	return vr;
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
