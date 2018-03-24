//Classe tableau pour tetris

#include <iostream>
#include <ctime>
#include <windows.h>
#include <math.h>
#include "Forme.h"
#include "Forme.h"
#include "Carre.h"
#include "Pyramide.h"
#include "L.h"
#include "Ligne.h"
#include "S.h"
#include "Z.h"
#include "LGauche.h"

//Defines
#define hauteur_tableau 25
#define largeur_tableau 20
#define PYRAMIDE 0
#define CARRE 1
#define L_VALUE 2
#define LGAUCHE 3
#define S_VALUE 4
#define Z_VALUE 5
#define LIGNE 6

using namespace std;

class Tetris_table {
	public :
		Tetris_table();
		~Tetris_table();
		bool delete_line(); //Supprimer la derniere ligne du tableau	
		bool full_line(); //Verifier que la derniere ligne est complete

		bool table1[hauteur_tableau][largeur_tableau] = { 0 }; //Tableau pour tetris, grandeur definie par des define 

		bool afficher_tableau(); //Affiche le tableau
		bool initialise_table(); //Initialise le tableau au depart pour ne pas avoir des valeurs aleatoires
		bool iteration(); //Itere dans le temps. Deplace les blocs 

		Forme* getFormeActuelle();
		Forme* getProchaineForme();
		void nouvelleFormeApparait();
		Forme* choixForme(int randomNumber);
		
	private : 
		int hauteur;
		int largeur;
		Forme buffer;
		Forme* formeActuelle;
		Forme* prochaineForme;
		int randomProchaineForme;
};

