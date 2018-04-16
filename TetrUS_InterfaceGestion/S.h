#pragma once
#include "Forme.h"

#define DIMENSION_S 3

class S : public Forme
{
	public:
		S();
		S(int pId);
		~S();

	private:
		vector<CASE> ligne1;
		vector<CASE> ligne2;
		vector<CASE> ligne3;
};