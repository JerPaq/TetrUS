#include "S.h"

S::S()
{

}

S::S(int pId)
{
	id_ = pId;
	dimension = DIMENSION_S;

	ligne1.resize(DIMENSION_S);
	ligne2.resize(DIMENSION_S);
	ligne3.resize(DIMENSION_S);
	matriceForme.resize(DIMENSION_S);

	ligne1[0] = CASE({ 0, 0 });
	ligne1[1] = CASE({ pId, 4 });
	ligne1[2] = CASE({ 0, 0 });
	ligne2[0] = CASE({ 0, 0 });
	ligne2[1] = CASE({ pId, 4 });
	ligne2[2] = CASE({ pId, 4 });
	ligne3[0] = CASE({ 0, 0 });
	ligne3[1] = CASE({ 0, 0 });
	ligne3[2] = CASE({ pId, 4 });

	matriceForme[0] = ligne1;
	matriceForme[1] = ligne2;
	matriceForme[2] = ligne3;

}

S::~S() 
{
}