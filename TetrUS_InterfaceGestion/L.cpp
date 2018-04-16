#include "L.h"

L::L()
{
	dimension = DIMENSION_L;

	lignes12.resize(DIMENSION_L);
	ligne3.resize(DIMENSION_L);
	matriceForme.resize(DIMENSION_L);

	lignes12[0] = 0;
	lignes12[1] = 2;
	lignes12[2] = 0;
	ligne3[0] = 0;
	ligne3[1] = 2;
	ligne3[2] = 2;

	matriceForme[0] = lignes12;
	matriceForme[1] = lignes12;
	matriceForme[2] = ligne3;
}

L::~L() 
{
}