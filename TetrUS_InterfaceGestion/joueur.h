#pragma once

#define JOUEUR
#include <string>
#include <nlohmann\json.hpp>

using namespace std;
using json = nlohmann::json;

class Joueur
{
private:
    string name_;
    int nbPartie_;
    int nbVictoire_;
    int highScore_;
    int pourcentage_;
public:
    Joueur();
    Joueur(string pName);
    Joueur(json pAttribut);
    json getAttributs();

    string getName();
    void modifierNom(string pNom);

	int getHighscore();
	int getPourcentage();

    bool setHighScore(int pHighscore);
    int augmenterPartie(bool pVictoire);
};
