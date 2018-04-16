#pragma once
#include "Forme.h"
#define DIMENSIONPYRAMIDE 3

class Pyramide : public Forme
{
	public:
		Pyramide();
		Pyramide(int pId);
		~Pyramide();

	private:
		vector<CASE> ligne1;
		vector<CASE> ligne2;
		vector<CASE> ligne3;
};