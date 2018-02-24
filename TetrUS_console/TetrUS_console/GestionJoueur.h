#pragma once

#include <nlohmann\json.hpp>
#include <iostream>
#include <fstream>

#include "vecteur.h"
#include "Joueur.h";

using namespace std;

class GestionJoueur 
{
public:
	void sauvegarder(Vecteur<Joueur>* pVecteur);
	Vecteur<Joueur>* charger();
	GestionJoueur();
	~GestionJoueur();
private:
	string serialize(Joueur* pJoueur);
	Joueur* deserialize(string pString);
};