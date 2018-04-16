#include "LGauche.h"

LGauche::LGauche()
{
}

LGauche::LGauche(int pId) 
{
	id_ = pId;
	dimension = DIMENSIONLGAUCHE;

	lignes12.resize(DIMENSIONLGAUCHE);
	ligne3.resize(DIMENSIONLGAUCHE);
	matriceForme.resize(DIMENSIONLGAUCHE);

	lignes12[0] = CASE({ 0, 0 });
	lignes12[1] = CASE({ pId, 3 });
	lignes12[2] = CASE({ 0, 0 });
	ligne3[0] = CASE({ pId, 3 });
	ligne3[1] = CASE({ pId, 3 });
	ligne3[2] = CASE({ 0, 0 });

	matriceForme[0] = lignes12;
	matriceForme[1] = lignes12;
	matriceForme[2] = ligne3;
}

LGauche::~LGauche()
{
}