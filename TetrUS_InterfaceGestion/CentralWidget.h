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

//Defines
#define hauteur_tableau 20
#define largeur_tableau 10

#define PYRAMIDE 0
#define CARRE 1
#define L_VALUE 2
#define LGAUCHE 3
#define S_VALUE 4
#define Z_VALUE 5
#define LIGNE 6

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

class CentralWidget : public QWidget
{
	Q_OBJECT

public:
	CentralWidget(GestionJoueur* pGestion, QWidget *parent = 0);
	~CentralWidget();

	void refreshUI();
	void refreshGame();

	bool delete_line(); //Supprimer la derniere ligne du tableau	
	bool full_line(); //Verifier que la derniere ligne est complete

	bool table1[hauteur_tableau][largeur_tableau] = { 0 }; //Tableau pour tetris, grandeur definie par des define 

	bool afficher_tableau(ostream& o); //Affiche le tableau
	bool initialise_table(); //Initialise le tableau au depart pour ne pas avoir des valeurs aleatoires
	bool iteration(); //Itere dans le temps. Deplace les blocs 
	bool translation(char direction); //translation vers la gauche('G') ou vers la droite('D')
	bool ajouterForme(Forme formeActuelle);	//Ajoute la forme voulue au tableau
	bool isFree(char direction, int horizontal, int vertical);	//regarde si l'espace adjacent est libre
	void move(char direction);	//Gere le mouvement d'une forme

	Forme* getFormeActuelle();
	Forme* getProchaineForme();
	void nouvelleFormeApparait();
	Forme* choixForme(int randomNumber);

private slots:
	void btnStart_Clicked();
	void btnPause_Clicked();
	void btnStop_Clicked();

private:
	void init();

	int hauteur;
	int largeur;
	int positionHorizontale; //position horizontale des elements a l'extreme gauche de la matrice de forme	} coin superieur gauche
	int positionVerticale;	//position verticale des elements du haut de la matrice							} coin superieur gauche
	Forme buffer;
	Forme* formeActuelle;
	Forme* prochaineForme;
	int randomProchaineForme;

	GestionJoueur* gestion_;

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
};
