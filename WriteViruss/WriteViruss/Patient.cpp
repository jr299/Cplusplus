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
	auto member_virusList = this->m_virusList.begin();
	int size = this->m_virusList.size();
	for (int i = 0; i < size; i++)
	{
		if ((*member_virusList)->ReduceResistance(medicine_resistance) <= 0)
		{
			(*member_virusList)->DoDie();
			this->m_virusList.erase(member_virusList++);
		}
		else
		{
			list<Viruss*> virusclone = (*member_virusList)->DoClone();
			this->m_virusList.insert(this->m_virusList.end(), virusclone.begin(), virusclone.end());
			member_virusList++;
		}
	}

	/*list<Viruss*>::iterator ind;
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
	}*/
	//int sumresistence = 0;
	//auto member_virusList = this->m_virusList.begin();	// khai báo con trỏ trỏ đến vị trí đầu list
	//for (int i = 0; i < this->m_virusList.size(); i++)
	//{
	//	sumresistence += (*member_virusList)->GetResistance();
	//	member_virusList++;
	//}
	//if (this->m_resistance < sumresistence)
	//{
	//	DoDie();
	//}
}

void Patient::DoDie()
{
	delete this;
}

int Patient::GetState()
{
	return this->m_state;
}
