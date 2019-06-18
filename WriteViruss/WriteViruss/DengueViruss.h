#pragma once
#include "Viruss.h"
#include <list>

class DengueViruss :
	public Viruss
{
private:
	char m_protein[4];
public:
	DengueViruss();
	DengueViruss(char protein[4], char *dna, int resistance);
	DengueViruss(const DengueViruss *denviruss);
	~DengueViruss();
	void SetProtein(char *protein);
	char* GetProtein();
	void DoBorn();
	list<Viruss*> DoClone();
	void DoDie();
	int InitResistance();
};

