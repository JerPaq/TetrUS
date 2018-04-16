#include "Z.h"

Z::Z() 
{
	dimension = DIMENSION_Z;

	ligne1.resize(DIMENSION_Z);
	ligne2.resize(DIMENSION_Z);
	ligne3.resize(DIMENSION_Z);
	matriceForme.resize(DIMENSION_Z);

	ligne1[0] = 0;
	ligne1[1] = 0;
	ligne1[2] = 5;
	ligne2[0] = 0;
	ligne2[1] = 5;
	ligne2[2] = 5;
	ligne3[0] = 0;
	ligne3[1] = 5;
	ligne3[2] = 0;

	matriceForme[0] = ligne1;
	matriceForme[1] = ligne2;
	matriceForme[2] = ligne3;
}

Z::~Z()
{
}