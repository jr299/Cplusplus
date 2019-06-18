#pragma once
#include "Viruss.h"
#include <list>

class FluViruss : public Viruss
{
private:
	int m_color;

public:
	FluViruss();
	FluViruss(int color, char *dna, int resistance);
	FluViruss(const FluViruss *fluviruss);
	~FluViruss();
	void SetColor(int color);
	int GetColor();
	void DoBorn();
	list<Viruss*> DoClone();
	void DoDie();
	int InitResistance();
};
