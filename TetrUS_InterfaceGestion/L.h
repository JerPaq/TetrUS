#pragma once
#include "Forme.h"

#define DIMENSION_L 3

class L : public Forme 
{
	public:
		L();
		~L();

	private:
		vector<int> lignes12;
		vector<int> ligne3;

};
