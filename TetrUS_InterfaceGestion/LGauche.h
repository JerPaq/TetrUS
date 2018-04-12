#pragma once
#include "Forme.h"

#define DIMENSIONLGAUCHE 3

class LGauche : public Forme
{
	public:
		LGauche();
		~LGauche();

	private:
		vector<int> lignes12;
		vector<int> ligne3;

};