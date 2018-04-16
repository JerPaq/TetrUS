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
	//void rotation(vector<vector<CASE>> table1);		//Rotation d'une matrice de forme
	//void rotation(vector<vector<CASE>> table1, int posH, int posV);
	void rotation(CASE table[][10], int posH, int posV);
	int getLength();
	CASE getElement(int i, int j);
	int getId();
	/*vector<int> at(int i);*/

protected:
	int dimension;	//dimension de la forme en question
	int id_;
	vector<vector<CASE> > matriceForme;	//matrice dans laquelle on transfere la forme

};
