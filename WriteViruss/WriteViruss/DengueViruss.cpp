#include "stdafx.h"
#include "DengueViruss.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

DengueViruss::DengueViruss()
{
	DoBorn();
	this->m_resistance = InitResistance();
}

DengueViruss::DengueViruss(char protein[4], char * dna, int resistance) : Viruss(dna, resistance)
{
	this->m_protein[4] = protein[4];
	this->m_dna = dna;
	this->m_resistance = resistance;
}

DengueViruss::DengueViruss(const DengueViruss * denviruss)
{
	this->m_protein[0] = denviruss->m_protein[0];
	this->m_protein[1] = denviruss->m_protein[1];
	this->m_protein[2] = denviruss->m_protein[2];
	this->m_protein[3] = denviruss->m_protein[3];
	this->m_dna = denviruss->m_dna;
	this->m_resistance = denviruss->m_resistance;
}

DengueViruss::~DengueViruss()
{
	//DoDie();
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
	LoadADNInformation();
	cout << "ADN: " << this->m_dna << endl;
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

list<Viruss*> DengueViruss::DoClone()
{
	list<Viruss*> vrclone;
	Viruss *vr1 = new DengueViruss(this);
	Viruss *vr2 = new DengueViruss(this);
	vrclone.push_back(vr1);
	vrclone.push_back(vr2);
	return vrclone;
}

void DengueViruss::DoDie()
{
	delete this;
}

int DengueViruss::InitResistance()
{
	cout << "Protein: " << this->m_protein << endl;
	if (this->m_protein[2] == '3')
	{
		int min = 1;
		int max = 10;
		this->m_resistance = rand() % (max - min + 1) + min;
		cout << "RESISTANCE (1-10): " << this->m_resistance << endl;
	}
	else if (this->m_protein[2] == '5')
	{
		int min = 11;
		int max = 20;
		this->m_resistance = rand() % (max - min + 1) + min;
		cout << "RESISTANCE (11-20): " << this->m_resistance << endl;
	}
	else if (this->m_protein[0] == 'E')
	{
		int min = 21;
		int max = 30;
		this->m_resistance = rand() % (max - min + 1) + min;
		cout << "RESISTANCE (21-30): " << this->m_resistance << endl;
	}
	else
	{
		cout << "Error!" << endl;
	}
	return this->m_resistance;
}
