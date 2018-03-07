#include "Joueur.h"

Joueur::Joueur()
{
	name_ = "";
	nbPartie_ = 0;
	nbVictoire_ = 0;
	highScore_ = 0;
	pourcentage_ = 0;
}

Joueur::Joueur(string pName)
{
	name_ = pName;
	nbPartie_ = 0;
	nbVictoire_ = 0;
	highScore_ = 0;
	pourcentage_ = 0;
}

Joueur::Joueur(json pAttribut)
{
	string temp = pAttribut["Name"];
	name_ = temp;
	nbPartie_ = pAttribut["NbPartie"];
	nbVictoire_ = pAttribut["NbVictoire"];
	highScore_ = pAttribut["Highscore"];
	pourcentage_ = pAttribut["Pourcentage"];
}

json Joueur::getAttributs()
{
	json attribut = {
		{"Name", name_},
		{"NbPartie", nbPartie_},
		{"NbVictoire", nbVictoire_},
		{"Highscore", highScore_},
		{"Pourcentage", pourcentage_}
	};
	return attribut;
}

string Joueur::getName()
{
	return name_;
}

void Joueur::modifierNom(string pNom)
{
	name_ = pNom;
}

bool Joueur::setHighScore(int pHighscore)
{
	if (pHighscore > highScore_)
	{
		highScore_ = pHighscore;
		return true;
	}
	return false;
}

void Joueur::augmenterPartie(bool pVictoire)
{
	nbPartie_++;
	if (pVictoire)
	{
		nbVictoire_++;
	}
	pourcentage_ = nbVictoire_ / nbPartie_ * 100;
}
