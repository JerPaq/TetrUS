#include "S.h"

S::S()
{
	dimension = DIMENSION_S;

	ligne1.resize(DIMENSION_S);
	ligne2.resize(DIMENSION_S);
	ligne3.resize(DIMENSION_S);
	matriceForme.resize(DIMENSION_S);

	ligne1[0] = 0;
	ligne1[1] = 1;
	ligne1[2] = 0;
	ligne2[0] = 0;
	ligne2[1] = 1;
	ligne2[2] = 1;
	ligne3[0] = 0;
	ligne3[1] = 0;
	ligne3[2] = 1;

	matriceForme[0] = ligne1;
	matriceForme[1] = ligne2;
	matriceForme[2] = ligne3;

}

S::~S() 
{
}