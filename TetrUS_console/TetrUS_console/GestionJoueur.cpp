#include "GestionJoueur.h"

void GestionJoueur::sauvegarder(Vecteur<Joueur>* pVecteur)
{
	ofstream myfile;
	myfile.open("ObjText.json");
	for (int i = 0; i < pVecteur->getTaille(); i++)
	{
		myfile << serialize(pVecteur->get(i)) << "\n";
	}
	myfile.close();
}

Vecteur<Joueur>* GestionJoueur::charger()
{
	ifstream myfile("ObjText.json");
	string laChaine;
	Vecteur<Joueur>* vecteurTemp = new Vecteur<Joueur>();
	Joueur* temp;

	if (myfile.is_open())
	{
		while (getline(myfile, laChaine))
		{
			temp = deserialize(laChaine);
			vecteurTemp->ajouter(temp);
		}
		myfile.close();
	}
	return vecteurTemp;
}

string GestionJoueur::serialize(Joueur* pJoueur)
{
	string laChaine = pJoueur->getAttributs().dump();
	return laChaine;

	return string();
}

Joueur* GestionJoueur::deserialize(string pString)
{
	json attribut = json::parse(pString);

	return new Joueur(attribut);
}

GestionJoueur::GestionJoueur(){}

GestionJoueur::~GestionJoueur(){}
