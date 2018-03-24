#include "tableau.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	int b;
	ofstream output;
	output.open("SortieFormes.txt", ios_base::out);

	if (output.is_open())
	{
		//Tests CARRE
		output << "TESTS CARRE\n";
		Forme* f = new Carre();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		delete[] f;

		//Tests Pyramide
		output << "TESTS PYRAMIDE\n";
		f = new Pyramide();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		delete[] f;

		//Tests L
		output << "TESTS L\n";
		f = new L();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		delete[] f;


		//Tests LGauche
		output << "TESTS LGauche\n";
		f = new LGauche();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		delete[] f;


		//Tests Ligne
		output << "TESTS LIGNE\n";
		f = new Ligne();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		delete[] f;

		//Tests S
		output << "TESTS S\n";
		f = new S();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		delete[] f;

		//Tests Z
		output << "TESTS Z\n";
		f = new Z();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		f->rotation();
		f->afficher(output);
		delete[] f;
	}

	//TESTS TABLEAU
	output << "TESTS GENERATION ALEATOIRE DE FORMES" << endl;
	Tetris_table background;
	background.nouvelleFormeApparait();
	output << "Premiere vague" << endl;
	output << "Forme actuelle" << endl;
	background.getFormeActuelle()->afficher(output);
	output << "Prochaine Forme" << endl;
	background.getProchaineForme()->afficher(output);

	background.nouvelleFormeApparait();
	output << "Prochaine vague" << endl;
	output << "Forme actuelle" << endl;
	background.getFormeActuelle()->afficher(output);
	output << "Prochaine Forme" << endl;
	background.getProchaineForme()->afficher(output);

	background.nouvelleFormeApparait();
	output << "Prochaine vague" << endl;
	output << "Forme actuelle" << endl;
	background.getFormeActuelle()->afficher(output);
	output << "Prochaine Forme" << endl;
	background.getProchaineForme()->afficher(output);

	background.nouvelleFormeApparait();
	output << "Prochaine vague" << endl;
	output << "Forme actuelle" << endl;
	background.getFormeActuelle()->afficher(output);
	output << "Prochaine Forme" << endl;
	background.getProchaineForme()->afficher(output);

	background.nouvelleFormeApparait();
	output << "Prochaine vague" << endl;
	output << "Forme actuelle" << endl;
	background.getFormeActuelle()->afficher(output);
	output << "Prochaine Forme" << endl;
	background.getProchaineForme()->afficher(output);
		
	std::cin >> b;
	return 0;

}