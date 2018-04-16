#pragma once
#include "Forme.h"

#define DIMENSION_L 3

class L : public Forme 
{
	public:
		L();
		L(int pId);
		~L();

	private:
		vector<CASE> lignes12;
		vector<CASE> ligne3;

};
