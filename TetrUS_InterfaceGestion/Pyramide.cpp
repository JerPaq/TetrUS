#include "Pyramide.h"

Pyramide::Pyramide()
{

}

Pyramide::Pyramide(int pId)
{
	id_ = pId;
	dimension = DIMENSIONPYRAMIDE;

	ligne1.resize(DIMENSIONPYRAMIDE);
	ligne2.resize(DIMENSIONPYRAMIDE);
	ligne3.resize(DIMENSIONPYRAMIDE);
	matriceForme.resize(DIMENSIONPYRAMIDE);

	ligne1[0] = CASE({ 0, 0 });
	ligne1[1] = CASE({ pId, 7 });
	ligne1[2] = CASE({ 0, 0 });
	ligne2[0] = CASE({ pId, 7 });
	ligne2[1] = CASE({ pId, 7 });
	ligne2[2] = CASE({ pId, 7 });
	ligne3[0] = CASE({ 0, 0 });
	ligne3[1] = CASE({ 0, 0 });
	ligne3[2] = CASE({ 0, 0 });

	matriceForme[0] = ligne1;
	matriceForme[1] = ligne2;
	matriceForme[2] = ligne3;
}

Pyramide::~Pyramide()
{
}