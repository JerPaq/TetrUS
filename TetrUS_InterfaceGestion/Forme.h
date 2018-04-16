#pragma once
#include <vector>
using namespace std;

struct CASE {    
	int id;
	int couleur;
};

class Forme
{
	public:
		Forme();
		virtual ~Forme();
		void rotation();		//Rotation d'une matrice de forme
		int getLength();
		CASE getElement(int i, int j);
		int getId();
		/*vector<int> at(int i);*/

	protected:
		int dimension;	//dimension de la forme en question
		int id_;
		vector<vector<CASE> > matriceForme;	//matrice dans laquelle on transfere la forme

	private:
		vector<vector<CASE> > matriceTransposee;	//matrice qui sera transposee pour effectuer la rotation
		
};
