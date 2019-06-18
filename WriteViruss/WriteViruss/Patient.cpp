#include "stdafx.h"
#include "Patient.h"
#include <cstdlib>
#include <ctime>
#include "Viruss.h"
#include "FluViruss.h"
#include "DengueViruss.h"
#include <iostream>

using namespace std;

Patient::Patient()
{
	InitResistance();
	DoStart();
}

Patient::Patient(int resistance, list<Viruss*> viruslist, int state)
{
	this->m_resistance = resistance;
	this->m_virusList = viruslist;
	this->m_state = state;
}


Patient::~Patient()
{
	cout << "Destroy Patient" << endl;
}

void Patient::InitResistance()
{
	this->m_resistance = rand() % 8001 + 1000;
}

void Patient::DoStart()
{
	
	this->m_state = 1;
	int numvirus = rand() % 11 + 10;

	for (int i = 0; i < numvirus; i++)
	{
		int typevirus = rand() % 2;

		if (typevirus == 0)
		{
			Viruss *fvr = new FluViruss();
			this->m_virusList.push_back(fvr);
			cout << "==> Flu virus " << i + 1 << endl;
			cout << "----------------------------------" << endl;
		}
		if (typevirus == 1)
		{
			Viruss *dvr = new DengueViruss();
			this->m_virusList.push_back(dvr);
			cout << "==> Dengue virus " << i + 1 << endl;
			cout << "----------------------------------" << endl;
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	cout << "Medicine: " << medicine_resistance << endl;
	list<Viruss*>::iterator ind = m_virusList.begin();
	int size = m_virusList.size();

	cout << "Size list begin: " << size << endl;

	int l_resis_vr;
	int sum_resis_vr = 0;
	list<Viruss*> vrclone;

	for (int i = 0; i < size; i++)
	{
		l_resis_vr = (*ind)->ReduceResistance(medicine_resistance);

		cout << "Virus(medicine): " << l_resis_vr << endl;
		
		if (l_resis_vr <= 0)
		{
			(*ind)->DoDie();
			m_virusList.erase(ind++);	
		}
		else
		{
			vrclone = (*ind++)->DoClone();
			m_virusList.insert(m_virusList.end(), vrclone.begin(), vrclone.end());
		}
	}

	cout << "Size final list: " << m_virusList.size() << endl;
	//check state Patient
	for (ind = m_virusList.begin(); ind != m_virusList.end(); ind++)
	{
		sum_resis_vr += (*ind)->m_resistance;
	}

	cout << "Total Virus resistance: " << sum_resis_vr << endl;
	cout << "Patient reistance: " << this->m_resistance << endl;

	if (this->m_resistance < sum_resis_vr)
	{
		DoDie();
	}
	
	int state = GetState();
	if (state == 0)
	{
		cout << "Patient - DIE" << endl;
	}
	else
	{
		cout << "Patient - ALIVE" << endl;
	}
	
}

void Patient::DoDie()
{
	delete this;
	this->m_state = 0;
}



int Patient::GetState()
{
	return this->m_state;
}
