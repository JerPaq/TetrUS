#include "Carre.h"
#include <vector>

using namespace std;

Carre::Carre()
{
	dimension = DIMENSIONCARRE;
	
	lignes.resize(DIMENSIONCARRE);
	matriceForme.resize(DIMENSIONCARRE);

	lignes[0] = 1;
	lignes[1] = 1;

	matriceForme[0] = lignes;
	matriceForme[1] = lignes;

}

Carre::~Carre()
{
}