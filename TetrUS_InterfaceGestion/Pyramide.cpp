#include "Pyramide.h"

Pyramide::Pyramide()
{
	dimension = DIMENSIONPYRAMIDE;

	ligne1.resize(DIMENSIONPYRAMIDE);
	ligne2.resize(DIMENSIONPYRAMIDE);
	ligne3.resize(DIMENSIONPYRAMIDE);
	matriceForme.resize(DIMENSIONPYRAMIDE);

	ligne1[0] = 0;
	ligne1[1] = 7;
	ligne1[2] = 0;
	ligne2[0] = 7;
	ligne2[1] = 7;
	ligne2[2] = 7;
	ligne3[0] = 0;
	ligne3[1] = 0;
	ligne3[2] = 0;

	matriceForme[0] = ligne1;
	matriceForme[1] = ligne2;
	matriceForme[2] = ligne3;
}

Pyramide::~Pyramide()
{
}