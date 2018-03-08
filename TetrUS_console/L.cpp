#include "L.h"

L::L()
{
	dimension = DIMENSION_L;

	ligne1.resize(DIMENSION_L);
	ligne2.resize(DIMENSION_L);
	ligne3.resize(DIMENSION_L);
	matriceForme.resize(DIMENSION_L);

	ligne1[0] = 0;
	ligne1[1] = 1;
	ligne1[2] = 0;
	ligne2[0] = 0;
	ligne2[1] = 1;
	ligne2[2] = 0;
	ligne3[0] = 0;
	ligne3[1] = 1;
	ligne3[2] = 1;

	matriceForme[0] = ligne1;
	matriceForme[1] = ligne2;
	matriceForme[2] = ligne3;
}

L::~L() 
{
}