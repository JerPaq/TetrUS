#pragma once
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "NouveauJoueur.h"
#include "SelectJoueur.h"
#include "gestionjoueur.h"
#include "CentralWidget.h"
#include "Reglements.h"
#include <QPalette>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
	void menuQuitter_Clicked();
	void menuReglements_Clicked();
	void menuNouveauJoueur_Clicked();
	void menuGestionJoueur_Clicked();
private:
	void init();
	CentralWidget * widgetCentral_;
	QMenu * menuFichier_;
	QMenu * menuJoueur_;
	QAction *actQuitter_;
	QAction *actReglement_;
	QAction *actNouveauJoueur_;
	QAction *actGestionJoueur_;
	NouveauJoueur *dlgNouveauJoueur_;
	SelectJoueur *dlgSelectJoueur_;
	Reglements *dlgReglements_;
	GestionJoueur *gestion_;
};