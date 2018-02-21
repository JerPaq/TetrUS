#include "ObjTest.h"

ObjTest::ObjTest()
{
	nbr1_ = 1;
	nbr2_ = 2;
	chaine_ = "chaine";
}

ObjTest::ObjTest(int pNbr1, int pNbr2, string pChaine)
{
	nbr1_ = pNbr1;
	nbr2_ = pNbr2;
	chaine_ = pChaine;
}

ObjTest::~ObjTest()
{
}

int ObjTest::getNbr1()
{
	return nbr1_;
}

int ObjTest::getNbr2()
{
	return nbr2_;
}

string ObjTest::getChaine()
{
	return chaine_;
}
