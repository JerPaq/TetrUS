#pragma once
#include <vector>
using namespace std;

class Forme
{
	public:
		Forme();
		virtual ~Forme();
		void rotation();		//Rotation d'une matrice de forme
		void afficher(ostream& o);	//Afficher une matrice de forme
		int getLength();
		int getElement(int i, int j);
		/*vector<int> at(int i);*/

	protected:
		int dimension;	//dimension de la forme en question
		vector<vector<int> > matriceForme;	//matrice dans laquelle on transfere la forme

	private:
		vector<vector<int> > matriceTransposee;	//matrice qui sera transposee pour effectuer la rotation
};
