#pragma once

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

private slots:
	void btnStart_Clicked();
	void btnPause_Clicked();
	void btnStop_Clicked();

private:
	void init();

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
