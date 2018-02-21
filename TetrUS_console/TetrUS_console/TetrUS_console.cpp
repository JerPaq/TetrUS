// TetrUS_console.cpp : définit le point d'entrée pour l'application console.
//

#include <nlohmann\json.hpp>
#include <iostream>
#include <fstream>

#include "ObjTest.h";

using namespace std;
using json = nlohmann::json;


void sauvegarder(ObjTest* pObjet);
ObjTest* charger();
string serialize(ObjTest* pObj);
ObjTest* deserialize(string pString);

int main()
{

	ObjTest* monObj = new ObjTest();

	sauvegarder(monObj);
	
	delete monObj;

	monObj = charger();

	int i;
	cin >> i;

    return 0;
}



void sauvegarder(ObjTest* pObjet)
{
	ofstream myfile;
	myfile.open("ObjText.json");
	myfile << serialize(pObjet);
	myfile.close();
}

ObjTest* charger()
{
	ifstream myfile ("ObjText.json");
	string laChaine;
	getline(myfile, laChaine);
	myfile.close();
	return deserialize(laChaine);
}

string serialize(ObjTest* pObj)
{
	json temp = {
		{ "nbr1_", pObj->getNbr1() },
		{ "nbr2_", pObj->getNbr2() },
		{ "chaine_", pObj->getChaine() }
	};
	
	string laChaine = temp.dump();
	return laChaine;
}

ObjTest* deserialize(string pString)
{
	json temp = json::parse(pString);

	return new ObjTest(temp["nbr1_"], temp["nbr2_"], temp["chaine_"]);

}