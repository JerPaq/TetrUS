#include "Ligne.h"

Ligne::Ligne()
{
	dimension = DIMENSIONLIGNE;

	lignes.resize(DIMENSIONLIGNE);
	matriceForme.resize(DIMENSIONLIGNE);

	lignes[0] = 0;
	lignes[1] = 0;
	lignes[2] = 1;
	lignes[3] = 0;

	matriceForme[0] = lignes;
	matriceForme[1] = lignes;
	matriceForme[2] = lignes;
	matriceForme[3] = lignes;
}

Ligne::~Ligne()
{
}