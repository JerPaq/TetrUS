#pragma once
#include "Forme.h"

#define DIMENSION_Z 3

class Z : public Forme
{
	public:
		Z();
		Z(int pId);
		~Z();
		
	private:
		vector<CASE> ligne1;
		vector<CASE> ligne2;
		vector<CASE> ligne3;


};