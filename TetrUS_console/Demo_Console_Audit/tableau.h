//Classe tableau pour tetris

#include <iostream>
#include <windows.h>

//Defines
#define hauteur_tableau 5
#define largeur_tableau 5

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

		void square(); //Insere un carre
		void L_shape(); //Insere un L
		void L_shape2(); //Insere un L a une autre position
		void line(); //Insere une ligne
		
	private : 
		int hauteur = hauteur_tableau;
		int largeur = largeur_tableau;
};

