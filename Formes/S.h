#pragma once
#include "Forme.h"

#define DIMENSION_S 3

class S : public Forme
{
	public:
		S();
		~S();

	private:
		vector<int> ligne1;
		vector<int> ligne2;
		vector<int> ligne3;
		int matrice[DIMENSION_S][DIMENSION_S];
};