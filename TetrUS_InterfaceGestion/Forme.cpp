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

int Forme::getElement(int i, int j)
{
	return matriceForme.at(i).at(j);
}


//vector<int> Forme::at(int i)
//{
//	return matriceForme.at(i);
//}

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
	int temporary;
	
		for (j = 0; j < dimension; j++) 
		{
			temporary = matriceTransposee[j][0];
			matriceTransposee[j][0] = matriceTransposee[j][(dimension-1)];
			matriceTransposee[j][(dimension-1)] = temporary;
		}
		
		matriceForme = matriceTransposee;	//On applique la rotation a la matrice de forme	
}

void Forme::afficher(ostream& o)
{
	for (int i = 0; i < dimension; i++)
	{

		for (int j = 0; j < dimension; j++)
		{
			o << matriceForme[i][j] << "  ";
		}
		o << endl;
	}
	o << endl;
}