#include "Ligne.h"

Ligne::Ligne()
{
	
}

Ligne::Ligne(int pId)
{
	id_ = pId;
	dimension = DIMENSIONLIGNE;

	lignes.resize(DIMENSIONLIGNE);
	matriceForme.resize(DIMENSIONLIGNE);

	lignes[0] = CASE({ pId, 6 });
	lignes[1] = CASE({ 0,0 });
	lignes[2] = CASE({ 0,0 });
	lignes[3] = CASE({ 0,0 });

	matriceForme[0] = lignes;
	matriceForme[1] = lignes;
	matriceForme[2] = lignes;
	matriceForme[3] = lignes;
}

Ligne::~Ligne()
{
}