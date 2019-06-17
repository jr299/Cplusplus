#pragma once
#include <vector>
#include <list>

using namespace std;

class Viruss
{
public:
	Viruss();
	Viruss(char *dna, int resistance);
	virtual ~Viruss();
	Viruss(const Viruss *viruss);
	void LoadADNInformation();
	int ReduceResistance(int medicine_resistance);
	int GetResistance();
	
public:
	char *m_dna;
	int m_resistance;

public:
	virtual void DoBorn() = 0;
	virtual list<Viruss *> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual int InitResistance() =0;
};

