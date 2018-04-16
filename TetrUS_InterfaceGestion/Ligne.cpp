#include "Ligne.h"

Ligne::Ligne()
{
	dimension = DIMENSIONLIGNE;

	lignes.resize(DIMENSIONLIGNE);
	matriceForme.resize(DIMENSIONLIGNE);

	lignes[0] = 6;
	lignes[1] = 0;
	lignes[2] = 0;
	lignes[3] = 0;

	matriceForme[0] = lignes;
	matriceForme[1] = lignes;
	matriceForme[2] = lignes;
	matriceForme[3] = lignes;
}

Ligne::~Ligne()
{
}