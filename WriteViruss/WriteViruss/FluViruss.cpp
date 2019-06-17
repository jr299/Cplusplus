#include "stdafx.h"
#include "FluViruss.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

int bl = 0x0000ff;
int red = 0xff0000;

FluViruss::FluViruss()
{
	DoBorn();
	this->m_resistance = InitResistance();
}

FluViruss::FluViruss(int color, char * dna, int resistance) : Viruss(dna, resistance)
{
	this->m_color = color;
	this->m_dna = dna;
	this->m_resistance = resistance;
}

FluViruss::FluViruss(const FluViruss * fluviruss)
{
	this->m_color = fluviruss->m_color;
	this->m_dna = fluviruss->m_dna;
	this->m_resistance = fluviruss->m_resistance;
}

FluViruss::~FluViruss()
{
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

	if (ran == 0)
	{
		this->m_color = bl;
	}
	else
	{
		this->m_color = red;
	}
}

list<Viruss*> FluViruss::DoClone()
{
	list<Viruss*> vrclone;
	Viruss *vr = new FluViruss(this);
	vrclone.push_back(vr);
	return vrclone;
}

void FluViruss::DoDie()
{
	delete this;
}

int FluViruss::InitResistance()
{
	int min = 10;

	if (this->m_color == bl)
	{
		cout << "Blue ";
		int max = 15;
		this->m_resistance = rand() % (max - min + 1) + min;
	}
	else if (this->m_color == red)
	{
		cout << "Red ";
		int max = 20;
		this->m_resistance = rand() % (max - min + 1) + min;
	}
	else
	{
		cout << "Error!" << endl;
	}
	return this->m_resistance;
}
