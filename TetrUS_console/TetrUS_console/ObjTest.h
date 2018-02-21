#pragma once

#define OBJTEST
#include <string>

using namespace std;

class ObjTest
{
public:
	ObjTest();
	ObjTest(int pNbr1, int pNbr2, string pChaine);
	~ObjTest();

	int getNbr1();
	int getNbr2();
	string getChaine();
private:
	int nbr1_;
	int nbr2_;
	string chaine_;
};