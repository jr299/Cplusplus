#pragma once
#include "Viruss.h"
class FluViruss :
	public Viruss
{
private:
	int m_color;

public:
	//FluViruss();
	FluViruss(int color, char *dna, int resistance);
	~FluViruss();
	void DoBorn();
	Viruss DoClone();
	void DoDie();
	int InitResistance();
};

