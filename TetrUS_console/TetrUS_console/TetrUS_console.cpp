// TetrUS_console.cpp : définit le point d'entrée pour l'application console.
//

#include <nlohmann\json.hpp>
#include <iostream>
#include <fstream>

#include "vecteur.h"
#include "ObjTest.h"
#include "Joueur.h"
#include "GestionJoueur.h"

using namespace std;
using json = nlohmann::json;


//void sauvegarder(Vecteur<ObjTest>* pObjet);
//Vecteur<ObjTest>* charger();
//string serialize(ObjTest* pObj);
//ObjTest* deserialize(string pString);

int main()
{
	GestionJoueur gestion;
	Vecteur<Joueur>* monVecteur = new Vecteur<Joueur>();

	monVecteur->ajouter(new Joueur(string("Mylene")));
	monVecteur->ajouter(new Joueur(string("Jerome")));
	monVecteur->ajouter(new Joueur(string("Malcolm")));
	monVecteur->ajouter(new Joueur(string("Grandillo")));

	gestion.sauvegarder(monVecteur);

	monVecteur->viderVecteur();
	delete monVecteur;

	monVecteur = gestion.charger();

	cout << monVecteur->get(0)->getName() << " " << monVecteur->get(1)->getName() << " " << 
		    monVecteur->get(2)->getName() << " " << monVecteur->get(3)->getName() << " ";

	

	//int i;
	//cin >> i;

    return 0;
}



//void sauvegarder(Vecteur<ObjTest>* pVecteur)
//{
//	ofstream myfile;
//	myfile.open("ObjText.json");
//	for (int i = 0; i < pVecteur->getTaille(); i++)
//	{
//		myfile << serialize(pVecteur->get(i)) << "\n";
//	}
//	myfile.close();
//}
//
//Vecteur<ObjTest>* charger()
//{
//	ifstream myfile ("ObjText.json");
//	string laChaine;
//	Vecteur<ObjTest>* vecteurTemp = new Vecteur<ObjTest>();
//	ObjTest* temp;
//
//	if (myfile.is_open())
//	{
//		while (getline(myfile, laChaine))
//		{
//			temp = deserialize(laChaine);
//			vecteurTemp->ajouter(temp);
//		}
//		myfile.close();
//	}
//	return vecteurTemp;
//
//}
//
//string serialize(ObjTest* pObj)
//{
//	json temp = {
//		{ "nbr1_", pObj->getNbr1() },
//		{ "nbr2_", pObj->getNbr2() },
//		{ "chaine_", pObj->getChaine() }
//	};
//	
//	string laChaine = temp.dump();
//	return laChaine;
//}
//
//ObjTest* deserialize(string pString)
//{
//	json temp = json::parse(pString);
//
//	return new ObjTest(temp["nbr1_"], temp["nbr2_"], temp["chaine_"]);
//
//}

/*ObjTest* monObj1 = new ObjTest(1,1,"1");
ObjTest* monObj2 = new ObjTest(2, 2, "2");
ObjTest* monObj3 = new ObjTest(3, 3, "3");

Vecteur<ObjTest>* monVecteur = new Vecteur<ObjTest>();
monVecteur->ajouter(monObj1);
monVecteur->ajouter(monObj2);
monVecteur->ajouter(monObj3);

sauvegarder(monVecteur);

delete monObj1;
delete monObj2;
delete monObj3;

monVecteur->viderVecteur();
delete monVecteur;

monVecteur = charger();

monObj1 = monVecteur->get(0);
monObj2 = monVecteur->get(1);
monObj3 = monVecteur->get(2);

cout << monObj1->getChaine() << " " << monObj2->getChaine() << " " << monObj3->getChaine();*/