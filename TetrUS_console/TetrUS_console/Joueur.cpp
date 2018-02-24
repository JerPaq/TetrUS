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
