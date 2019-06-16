#pragma once
#include "Viruss.h"
class DengueViruss :
	public Viruss
{
private:
	char m_protein[4];
public:
	DengueViruss();
	~DengueViruss();
	void DoBorn();
	void DoClone();
	void DoDie();
	void InitResistance();
};

