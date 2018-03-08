#pragma once

#include "Forme.h"
#include <vector>
#define DIMENSIONCARRE 2

using namespace std;


class Carre : public Forme
{
	public:
		Carre();
		~Carre();
		
	private:
		vector<int> lignes;
		int matrice[DIMENSIONCARRE][DIMENSIONCARRE];

};
