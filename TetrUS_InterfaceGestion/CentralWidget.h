#pragma once

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "Forme.h"
#include "Carre.h"
#include "Pyramide.h"
#include "L.h"
#include "Ligne.h"
#include "S.h"
#include "Z.h"
#include "LGauche.h"

//Defines du tableau
#define hauteur_tableau 20
#define largeur_tableau 10

//Define pour les formes
#define CARRE 1
#define L_VALUE 2
#define LGAUCHE 3
#define S_VALUE 4
#define Z_VALUE 5
#define LIGNE 6
#define PYRAMIDE 7


//Define pour lecture du clavier
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include "gestionjoueur.h"

//Q Librairies
#include <QEvent>
#include <QWidget>
#include <qpushbutton>
#include <qmenubar>
#include <qmenu>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTimer>

class CentralWidget : public QWidget
{
	Q_OBJECT

public:
	CentralWidget(GestionJoueur* pGestion, QWidget *parent = 0);
	~CentralWidget();

	//Creation du jeu
	bool table1[hauteur_tableau][largeur_tableau]; //Tableau pour tetris, grandeur definie par des define 
	bool initialise_table(); //Initialise le tableau au depart pour ne pas avoir des valeurs aleatoires

	//Refreshing game
	void refreshUI();
	void refreshGame();


	//Full lines and deletes. Gere le pointage aussi
	void delete_line(int deleted_line); //Supprimer la derniere ligne du tableau	
	bool full_line(int line_check); //Verifier que la derniere ligne est complete
	void check_lines();

	//Les fonctions du jeu
	bool iteration(); //Itere dans le temps. Deplace les blocs 
	bool translation(char direction); //translation vers la gauche('L') ou vers la droite('R')
	bool ajouterForme(Forme formeActuelle);	//Ajoute la forme voulue au tableau
	bool isFree(char direction, int horizontal, int vertical);	//regarde si l'espace adjacent est libre
	void move(char direction);	//Gere le mouvement d'une forme
	void run_game(); //Run time du jeu

	Forme* getFormeActuelle();
	Forme* getProchaineForme();
	void nouvelleFormeApparait();
	Forme* choixForme(int randomNumber);


	//Conditions pour jeu actif.
	bool activeGame = false; //Lorsque qu'on commence ou on fait pause pour le jeu
	bool alive = false; //Lorsqu'on echoue. You suck. 


private slots:
	void btnStart_Clicked();
	void btnPause_Clicked();
	void btnStop_Clicked();

private:
	//Variables du jeu
	int hauteur;
	int largeur;
	//int positionHorizontale; //position horizontale des elements a l'extreme gauche de la matrice de forme	} coin superieur gauche
	//int positionVerticale;	//position verticale des elements du haut de la matrice							} coin superieur gauche
	int positionLargeur; //position horizontale des elements a l'extreme gauche de la matrice de forme	} coin superieur gauche
	int positionHauteur;	//position verticale des elements du haut de la matrice							} coin superieur gauche
	int freeze_table[largeur_tableau];
	Forme buffer;
	Forme* formeActuelle;
	Forme* prochaineForme;
	int randomProchaineForme;
	int current_score; //Nombre de lignes supprimes lors de cette partie. 


	//Gestion du jeu et des joueurs
	void init();


	// Test pour tout régler de Jérôme
	int findLastDown(Forme* pForme, int i, int j, bool pNonVide);

	void processusJeu();

	GestionJoueur* gestion_;

	//Widgets
	QVBoxLayout* initNextBloc();
	QVBoxLayout* initHighscore();
	QVBoxLayout* initStats();
	QGridLayout* initJeu();

	QPushButton *btnStart_;
	QPushButton *btnPause_;
	QPushButton *btnStop_;

	QMessageBox *msgBox_;

	QWidget * widgetCentral_;
	QWidget *widgetJeu_;
	QWidget *widgetNextBloc_;
	QWidget *widgetHighscore_;
	QWidget *widgetStats_;

	QLabel *tetrusLabel_;

	QLabel *lblScore_;
	QLabel *lblHighscore_;

	QLabel *lblNom_;
	QLabel *lblNbPartie_;
	QLabel *lblNbVictoire_;
	QLabel *lblPourcentage_;
	QLabel *lblHighscoreJoueur_;

	QTableWidget *Tetris_;

	QTimer *timerJeu_;
	QTimer *timerPhoneme_;
};
