#pragma once
#include "Forme.h"

#define DIMENSIONLGAUCHE 3

class LGauche : public Forme
{
	public:
		LGauche();
		LGauche(int pId);
		~LGauche();

	private:
		vector<CASE> lignes12;
		vector<CASE> ligne3;

};