#pragma once
#include "Forme.h"

#define DIMENSIONLIGNE 4

class Ligne : public Forme
{
	public:
		Ligne();
		~Ligne();

	private:
		vector<int> lignes;
};
