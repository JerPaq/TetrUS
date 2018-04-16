#pragma once

#include "Forme.h"
#include <vector>
#define DIMENSIONCARRE 2

using namespace std;


class Carre : public Forme
{
	public:
		Carre();
		Carre(int pId);
		~Carre();
		
	private:
		vector<CASE> lignes;

};
