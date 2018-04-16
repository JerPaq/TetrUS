#pragma once

#include <nlohmann\json.hpp>
#include <iostream>
#include <fstream>
#include <list>
#include <QStringList>
#include "vecteur.h"
#include "Joueur.h"


using namespace std;

class GestionJoueur
{
public:
    GestionJoueur();
    ~GestionJoueur();

    list<string> listeNom();
    QStringList QlisteNom();

    void sauvegarder();
    bool charger();

    bool ajouterJoueur(string pNom);
    bool modifierNom(string pNom, string pNouveauNom);
    bool supprimerJoueur(string pNom);

    void selectionnerJoueur(string pNom);
	void selectionnerJoueur();
	Joueur* joueurSelect() const;

	int getHighscore();

private:
    string serialize(Joueur* pJoueur);
    Joueur* deserialize(string pString);

    Vecteur<Joueur>* monVecteur_;
    Joueur* joueurCourant_;
};
