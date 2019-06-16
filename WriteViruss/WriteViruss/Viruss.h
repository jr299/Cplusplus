#pragma once
#include "Patient.h"
class Viruss
{
public:
	//Viruss();
	Viruss(char *dna, int resistance);
	virtual ~Viruss();
	//~Viruss();
	//Viruss(Viruss &viruss);
	Viruss(Viruss *viruss);
	char *LoadADNInformation();
	int ReduceResistance(int medicine_resistance);
	
public:
	char *m_dna;
	int m_resistance;

protected:
	virtual void DoBorn();
	virtual Viruss DoClone();
	virtual void DoDie();
	virtual int InitResistance();
};

