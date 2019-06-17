#include "stdafx.h"
#include "Viruss.h"
#include <iostream>
#include <fstream>

using namespace std;

Viruss::Viruss()
{
	this->m_dna = NULL;
	this->m_resistance = 0;
}

Viruss::Viruss(char *dna, int resistance)
{
	this->m_dna = dna;
	this->m_resistance = resistance;
}


Viruss::Viruss(const Viruss * viruss)
{
	this->m_dna = viruss->m_dna;
	this->m_resistance = viruss->m_resistance;
}

char * Viruss::LoadADNInformation()
{
	this->m_dna = NULL;
	ifstream inFile;
	inFile.open("ATGX.bin");

	if (inFile.is_open())
	{
		char a[100];
		inFile >> a;
		this->m_dna = (char *)a;

		cout << "Load success: " << this->m_dna << endl;
	}
	else
	{
		cout << "Load error!" << endl;
	}
	inFile.close();

	return this->m_dna;
}

int Viruss::ReduceResistance(int medicine_resistance)
{
	this->m_resistance = this->m_resistance - medicine_resistance;
	
	return this->m_resistance;
}

Viruss::~Viruss()
{
	cout << "Destroy Virus" << endl;
}
