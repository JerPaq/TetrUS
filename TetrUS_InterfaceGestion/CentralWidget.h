#pragma once

#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include "Forme.h"
#include "Carre.h"
#include "Pyramide.h"
#include "L.h"
#include "Ligne.h"
#include "S.h"
#include "Z.h"
#include "LGauche.h"
#include "Windows.h"
#include "carte_FPGA.h"

//Defines
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
#include <Windows.h>
#include <qshortcut>

class CentralWidget : public QWidget
{
	Q_OBJECT

public:
	CentralWidget(GestionJoueur* pGestion, QWidget *parent = 0);
	~CentralWidget();

	void refreshUI();
	void refreshGame();

	//Delete manager
	void delete_line(int deleted_line); //Supprimer la derniere ligne du tableau	
	bool full_line(int line_check); //Verifier que une ligne est complete
	void check_lines(); //Combinaison des deux fonctions precedentes. 

	//Warning for game loss
	void loss_warning();
	void increase_score(int bonus);

	CASE table1[hauteur_tableau][largeur_tableau]; //Tableau pour tetris, grandeur definie par des define 

	bool initialise_table(); //Initialise le tableau au depart pour ne pas avoir des valeurs aleatoires
	bool iteration(); //Itere dans le temps. Deplace les blocs 
	bool translation(char direction); //translation vers la gauche('G') ou vers la droite('D')
	bool ajouterForme(Forme formeActuelle);	//Ajoute la forme voulue au tableau
	bool isFree(char direction, int horizontal, int vertical);	//regarde si l'espace adjacent est libre
	void move(char direction);	//Gere le mouvement d'une forme
	void run_game(); //Run time du jeu

	Forme* getFormeActuelle();
	Forme* getProchaineForme();
	void nouvelleFormeApparait();
	void summumShape();
	Forme* choixForme(int randomNumber);

private slots:
	void btnStart_Clicked();
	void btnPause_Clicked();
	void btnStop_Clicked();
	void left_press();
	void right_press();
	void up_press();
	void down_press();
	void processusJeu();
	void capterPhoneme();

private:
	void init();

	//// info sur jeu
	bool activeGame = false;
	bool alive = false;
	bool pause_ = false;

	//// compteur
	int compteurBloc_ = 0;
	int compteurIteration_ = 0;
	////

	int hauteur;
	int largeur;
	//int positionHorizontale; //position horizontale des elements a l'extreme gauche de la matrice de forme	} coin superieur gauche
	//int positionVerticale;	//position verticale des elements du haut de la matrice							} coin superieur gauche
	int positionLargeur; //position horizontale des elements a l'extreme gauche de la matrice de forme	} coin superieur gauche
	int positionHauteur;	//position verticale des elements du haut de la matrice							} coin superieur gauche
	Forme buffer;
	Forme* formeActuelle;
	Forme* prochaineForme;
	int randomProchaineForme;

	int current_score; //Pointage du match


	// Trouver dernier indice
	int findLastDown(Forme* pForme, int i, int j, bool pNonVide);
	int findLastLeft(Forme* pForme, int i, int j, bool pNonVide);
	int findLastRight(Forme* pForme, int i, int j, bool pNonVide);

	GestionJoueur* gestion_;
	Joueur* joueur_;

	QVBoxLayout* initNextBloc();
	QVBoxLayout* initHighscore();
	QVBoxLayout* initStats();
	QGridLayout* initJeu();

	QPushButton *btnStart_;
	QPushButton *btnPause_;
	QPushButton *btnStop_;

	QMessageBox *msgBox_;
	QMessageBox *losswarning_;
	QMessageBox *highscore_;

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

	QLabel *lblNextBloc_;

	QTableWidget *Tetris_;

	QTimer *timerJeu_;
	QTimer *timerPhoneme_;
	Carte_FPGA carte_fpga_;
};
