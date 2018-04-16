#include "Carre.h"
#include <vector>

using namespace std;

Carre::Carre()
{

}

Carre::Carre(int pId)
{
	id_ = pId;
	dimension = DIMENSIONCARRE;
	
	lignes.resize(DIMENSIONCARRE);
	matriceForme.resize(DIMENSIONCARRE);

	lignes[0] = CASE({pId, 1});
	lignes[1] = CASE({ pId, 1 });

	matriceForme[0] = lignes;
	matriceForme[1] = lignes;

}

Carre::~Carre()
{
}