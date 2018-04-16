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
	//return matriceForme.at(i).at(j);
	return matriceForme[i][j];
}

int Forme::getId()
{
	return id_;
}

void Forme::rotation(CASE table[][10], int positionLargeur, int positionHauteur)
{
	//int i;
	//int j;
	//int largeur = 10;
	//int hauteur = 18;
	//bool collision = false;
	//vector<vector<CASE> > matriceTransposee;

	//table[1][1] = getElement(0, 0);

	//matriceTransposee.resize(dimension);	//On donne la bonne dimension a la transposee
	//matriceTransposee = matriceForme;	//On ajoute un vecteur a chaque element afin d'avoir un tableau multidimentionnel (on l'egal a matriceForme pour refaire les choses 2 fois)

	////int ligneDeZeros = 0;
	//for (i = 0; i < dimension; i++)
	//{
	//	for (j = 0; j < dimension; j++)
	//	{
	//		if (table[i + positionHauteur][j + positionLargeur].id != 0 && table[i + positionHauteur][j + positionLargeur].id != id_)
	//			collision = true;
	//		
	//		matriceTransposee[i][j] = matriceForme[j][i];
	//	}
	//}
	////Changement des lignes aux extremites (necessaire pour que la rotation fonctionne)
	//CASE temporary;
	//
	//for (j = 0; j < dimension; j++) 
	//{
	//	temporary = matriceTransposee[j][0];
	//	matriceTransposee[j][0] = matriceTransposee[j][(dimension-1)];
	//	matriceTransposee[j][(dimension-1)] = temporary;
	//}
	//
	//if(collision == false)
	//	matriceForme = matriceTransposee;	//On applique la rotation a la matrice de forme	



	int i;
	int j;
	int largeur = 10;
	int hauteur = 18;
	bool collision = false;
	vector<vector<CASE> > matriceTransposee;

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
		matriceTransposee[j][0] = matriceTransposee[j][(dimension - 1)];
		matriceTransposee[j][(dimension - 1)] = temporary;
	}

	for (i = 0; i < dimension; i++)
	{
		for (j = 0; j < dimension; j++)
		{
			if (table[i + positionHauteur][j + positionLargeur].id != 0 && table[i + positionHauteur][j + positionLargeur].id != id_)
				collision = true;
		}
	}

	if (collision == false)
	{
		if (table[i + positionHauteur][j + positionLargeur].id != 0 && table[i + positionHauteur][j + positionLargeur].id != id_)
		{
			table[i + positionHauteur][j + positionLargeur].id = 0;
			table[i + positionHauteur][j + positionLargeur].couleur = 0;
		}
		matriceForme = matriceTransposee;	//On applique la rotation a la matrice de forme	

	}

}

