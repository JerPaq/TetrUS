#pragma once
#include "Forme.h"

#define DIMENSION_L 3

class L : public Forme 
{
	public:
		L();
		~L();

	private:
		vector<int> ligne1;
		vector<int> ligne2;
		vector<int> ligne3;
		int matrice[DIMENSION_L][DIMENSION_L];

};
