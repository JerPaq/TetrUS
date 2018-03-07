#pragma once

#define VECTEUR_H

#include <iostream>

using namespace std;

template <typename Type> 
class Vecteur
{
private:
	Type* *debut_;
	int capacite_;
	int taille_;


public:
	Vecteur();
	~Vecteur();

	int getCapacite();
	int getTaille();
	void viderVecteur();
	bool estVide();
	bool ajouter(Type* pForme);
	void retirer(int pIndex);
	Type* get(int pIndex);
	void afficherVecteur(ostream & s);

	Type* operator[](int pIndex);
};

///////////////////////////////////////////////////////////
///// Contenue de .cpp
///////////////////////////////////////////////////////////


template <typename Type>
Vecteur<typename Type>::Vecteur()
{
	capacite_ = 1;
	debut_ = new Type*[capacite_];
	taille_ = 0;
}

template <typename Type>
Vecteur<typename Type>::~Vecteur()
{
	for (int i = 0; i < taille_; i++)
	{
		delete debut_[i];
	}
	delete[] debut_;
}

template <typename Type>
int Vecteur<typename Type>::getCapacite()
{
	return capacite_;
}

template <typename Type>
int Vecteur<typename Type>::getTaille()
{
	return taille_;
}

template <typename Type>
void Vecteur<typename Type>::viderVecteur()
{
	taille_ = 0;
}

template <typename Type>
bool Vecteur<typename Type>::estVide()
{
	return taille_ > 0 ? false : true;
}

template <typename Type>
bool Vecteur<typename Type>::ajouter(Type* pForme)
{
	if (taille_ == capacite_)
	{
		capacite_ = capacite_ * 2;

		Type* *temp = new Type*[capacite_];

		for (int i = 0; i < taille_; i++)
		{
			temp[i] = debut_[i];
		}

		delete[] debut_;
		debut_ = temp;

	}
	debut_[taille_] = pForme;
	taille_++;

	return true;
}

template <typename Type>
void Vecteur<typename Type>::afficherVecteur(ostream & s)
{
	for (int i = 0; i < taille_; i++)
	{
		debut_[i]->afficher(s);;
	}
}

template <typename Type>
void Vecteur<typename Type>::retirer(int pIndex)
{

	/*if (pIndex > taille_)
	{
		return NULL;
	}*/

	delete debut_[pIndex];

	for (int i = pIndex; i < taille_; i++)
	{
		debut_[i] = debut_[i + 1];
	}

	taille_--;
	//return ptrTemp;
}

template <typename Type>
Type* Vecteur<typename Type>::get(int pIndex)
{
	return debut_[pIndex];
}

template <typename Type>
Type* Vecteur<typename Type>::operator[](int pIndex)
{
	return get(pIndex);
}