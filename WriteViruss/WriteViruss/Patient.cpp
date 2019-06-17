#include "stdafx.h"
#include "Patient.h"
#include <cstdlib>
#include <ctime>
#include "Viruss.h"
#include "FluViruss.h"
#include "DengueViruss.h"
#include <iostream>

using namespace std;

int Patient::medicine_resistance = rand() % 60 + 1;

Patient::Patient()
{
	DoStart();
	this->m_state = 1;
}

Patient::Patient(int resistance, list<Viruss*> viruslist, int state)
{
	this->m_resistance = resistance;
	this->m_virusList = viruslist;
	this->m_state = state;
}


Patient::~Patient()
{
	cout << "Patien was die" << endl;
}

int Patient::InitResistance()
{
	int min = 1000;
	int max = 9000;
	return this->m_resistance = rand() % (max - min + 1) + min;
}

void Patient::DoStart()
{
	int numvirus = rand() % 11 + 10;
	for (int i = 0; i < numvirus; i++)
	{
		int typevirus = rand() % 2;

		if (typevirus == 0)
		{
			Viruss *fvr = new FluViruss();
			this->m_virusList.push_back(fvr);
			cout << "Flu virus " << i << endl;
		}
		if (typevirus == 1)
		{
			Viruss *dvr = new DengueViruss();
			this->m_virusList.push_back(dvr);
			cout << "Dengue virus " << i << endl;
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	list<Viruss*>::iterator ind;
	for (ind = m_virusList.begin(); ind != m_virusList.end(); ind++)
	{
		(*ind)->ReduceResistance(medicine_resistance);
		if ((*ind)->ReduceResistance(medicine_resistance) > 0)
		{
			list<Viruss*> vrclone = (*ind)->DoClone();
			this->m_virusList.insert(this->m_virusList.end(), vrclone.begin(), vrclone.end());
		}
		else
		{
			(*ind)->DoDie();
			this->m_virusList.remove((*ind));
		}
	}
	int sum = 0;
	for (ind = m_virusList.begin(); ind != m_virusList.end(); ind++)
	{
		sum += (*ind)->m_resistance;
	}
	if (this->m_resistance < sum)
	{
		DoDie();
	}

}

void Patient::DoDie()
{
	delete this;
}

int Patient::GetState()
{
	return this->m_state;
}
