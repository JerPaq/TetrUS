#pragma once
#include "Forme.h"

#define DIMENSION_Z 3

class Z : public Forme
{
	public:
		Z();
		~Z();
		
	private:
		vector<int> ligne1;
		vector<int> ligne2;
		vector<int> ligne3;


};