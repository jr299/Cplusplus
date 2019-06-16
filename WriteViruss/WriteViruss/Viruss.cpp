#include "stdafx.h"
#include "Viruss.h"
#include <iostream>

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
	int fsize = 0;
	FILE *fp;

	fp = fopen("ATGX.bin", "r");
	if (fp)
	{
		fseek(fp, 0, SEEK_END);
		fsize = ftell(fp);
		rewind(fp);

		m_dna = new char[fsize + 1];
		fread(m_dna, 1, fsize, fp);
		m_dna[fsize] = '\0';
		fclose(fp);

		cout << "Load success: " << m_dna << endl;
	}
	else
	{
		cout << "Load error!" << endl;
	}
	return m_dna;
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
