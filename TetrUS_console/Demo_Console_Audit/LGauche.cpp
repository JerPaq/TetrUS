#include "LGauche.h"

LGauche::LGauche() 
{
	dimension = DIMENSIONLGAUCHE;

	lignes12.resize(DIMENSIONLGAUCHE);
	ligne3.resize(DIMENSIONLGAUCHE);
	matriceForme.resize(DIMENSIONLGAUCHE);

	lignes12[0] = 0;
	lignes12[1] = 1;
	lignes12[2] = 0;
	ligne3[0] = 1;
	ligne3[1] = 1;
	ligne3[2] = 0;

	matriceForme[0] = lignes12;
	matriceForme[1] = lignes12;
	matriceForme[2] = ligne3;
}

LGauche::~LGauche()
{
}