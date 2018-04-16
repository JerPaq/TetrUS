#include "Forme.h"
#include <math.h>
#include <iostream>

using namespace std;

Forme::Forme()
{
}


Forme::~Forme()
{
}

int Forme::getLength()
{
	return dimension;
}

CASE Forme::getElement(int i, int j)
{
	return matriceForme.at(i).at(j);
}

int Forme::getId()
{
	return id_;
}

void Forme::rotation()
{
	int i;
	int j;

	matriceTransposee.resize(dimension);	//On donne la bonne dimension a la transposee
	matriceTransposee = matriceForme;	//On ajoute un vecteur a chaque element afin d'avoir un tableau multidimentionnel (on l'egal a matriceForme pour refaire les choses 2 fois)

	//int ligneDeZeros = 0;
	for (i = 0; i < dimension; i++)
	{
		for (j = 0; j < dimension; j++)
		{
	
			matriceTransposee[i][j] = matriceForme[j][i];
		}
	}
	//Changement des lignes aux extremites (necessaire pour que la rotation fonctionne)
	CASE temporary;
	
		for (j = 0; j < dimension; j++) 
		{
			temporary = matriceTransposee[j][0];
			matriceTransposee[j][0] = matriceTransposee[j][(dimension-1)];
			matriceTransposee[j][(dimension-1)] = temporary;
		}
		
		matriceForme = matriceTransposee;	//On applique la rotation a la matrice de forme	
}

