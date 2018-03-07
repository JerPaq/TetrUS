#pragma once

#include <nlohmann\json.hpp>
#include <iostream>
#include <fstream>
#include <list>

#include "vecteur.h"
#include "Joueur.h";

using namespace std;

class GestionJoueur 
{
public:
	GestionJoueur();
	~GestionJoueur();

	list<string> listeNom();

	void sauvegarder();
	bool charger();
	
	bool ajouterJoueur(string pNom);
	bool modifierNom(string pNom, string pNouveauNom);
	bool supprimerJoueur(string pNom);

	void selectrionnerJoueur(string pNom);


private:
	string serialize(Joueur* pJoueur);
	Joueur* deserialize(string pString);

	Vecteur<Joueur>* monVecteur_;
	Joueur* joueurCourant_;
};