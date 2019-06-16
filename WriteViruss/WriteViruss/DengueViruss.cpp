#include "stdafx.h"
#include "DengueViruss.h"
#include <iostream>

using namespace std;

DengueViruss::DengueViruss()
{
	this->m_protein[4] = NULL;
	this->m_dna = NULL;
	this->m_resistance = 0;
}

DengueViruss::DengueViruss(char protein[4], char * dna, int resistance) : Viruss(dna, resistance)
{
	DoBorn();
	this->m_resistance = InitResistance();
}

DengueViruss::~DengueViruss()
{
	DoDie();
	cout << "Destroy Dengue Virus" << endl;
}

void DengueViruss::SetProtein(char * protein)
{
	this->m_protein[4] = *protein;
}

char * DengueViruss::GetProtein()
{
	return this->m_protein;
}

void DengueViruss::DoBorn()
{
	this->m_dna = LoadADNInformation();

	int min = 0;
	int max = 2;
	int ran = rand() % (max - min + 1) + min;

	if (ran == 0)
	{
		this->m_protein[0] = 'N';
		this->m_protein[1] = 'S';
		this->m_protein[2] = '3';
		this->m_protein[3] = '\0';
	}
	else if(ran == 1)
	{
		this->m_protein[0] = 'N';
		this->m_protein[1] = 'S';
		this->m_protein[2] = '5';
		this->m_protein[3] = '\0';
	}
	else
	{
		this->m_protein[0] = 'E';
		this->m_protein[1] = '\0';
	}
}

Viruss * DengueViruss::DoClone()
{
	Viruss *vr = new DengueViruss();

	vr->m_dna = this->m_dna;
	vr->m_resistance = this->m_resistance;

	return vr;
}

void DengueViruss::DoDie()
{
	if (m_dna != nullptr)
	{
		delete[] m_dna;
	}
}

int DengueViruss::InitResistance()
{
	if (this->m_protein == "NS3")
	{
		int min = 1;
		int max = 10;
		this->m_resistance = rand() % (max - min + 1) + min;
	}
	else if (this->m_protein == "NS5")
	{
		int min = 11;
		int max = 20;
		this->m_resistance = rand() % (max - min + 1) + min;
	}
	else if (this->m_protein == "E")
	{
		int min = 21;
		int max = 30;
		this->m_resistance = rand() % (max - min + 1) + min;
	}
	else
	{
		cout << "Error!" << endl;
	}
	return this->m_resistance;
}
