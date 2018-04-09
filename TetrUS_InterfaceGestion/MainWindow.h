#pragma once
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "NouveauJoueur.h"
#include "SelectJoueur.h"
#include "gestionjoueur.h"
#include "CentralWidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
	void menuQuitter_Clicked();
	void menuNouveauJoueur_Clicked();
	void menuGestionJoueur_Clicked();
private:
	void init();
	CentralWidget * widgetCentral_;
	QMenu * menuFichier_;
	QMenu * menuJoueur_;
	QAction *actQuitter_;
	QAction *actNouveauJoueur_;
	QAction *actGestionJoueur_;
	NouveauJoueur *dlgNouveauJoueur_;
	SelectJoueur *dlgSelectJoueur_;
	GestionJoueur *gestion_;
};