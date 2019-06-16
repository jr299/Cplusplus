#pragma once
#include "Patient.h"
class Viruss
{
public:
	Viruss();
	Viruss(char *dna, int resistance);
	virtual ~Viruss();
	//~Viruss();
	//Viruss(const Viruss &viruss);
	Viruss(const Viruss *viruss);
	char *LoadADNInformation();
	int ReduceResistance(int medicine_resistance);
	
public:
	char *m_dna;
	int m_resistance;

protected:
	virtual void DoBorn() = 0;
	virtual Viruss* DoClone() = 0;
	virtual void DoDie() = 0;
	virtual int InitResistance() = 0;
};

