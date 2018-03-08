#pragma once
#include "Forme.h"
#define DIMENSIONPYRAMIDE 3

class Pyramide : public Forme
{
	public:
		Pyramide();
		~Pyramide();

	private:
		vector<int> ligne1;
		vector<int> ligne2;
		vector<int> ligne3;
		int matrice[DIMENSIONPYRAMIDE][DIMENSIONPYRAMIDE];
};