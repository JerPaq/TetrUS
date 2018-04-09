#pragma once
#define SELECTJOUEUR_H

#include "gestionjoueur.h"
#include "ModifierJoueur.h"
#include <QDialog>
#include <QPushButton>
#include <QListView>
#include <QListWidget>
#include <QStringListModel>
#include <QMessageBox>

class SelectJoueur : public QDialog
{
	Q_OBJECT

public:
	SelectJoueur(GestionJoueur *pGestion, QWidget *parent = 0);
	~SelectJoueur();

	bool isOk();

private slots:
	void btnAnnuler_Clicked();
	void btnChoisir_Clicked();
	void btnModifier_Clicked();
	void btnSupprimer_Clicked();
	void joueurChoisi(QListWidgetItem* item);
	
private:
	void init();
	void refreshList();

	bool ok_ = false;

	QListWidget * lsvJoueur_;
	QPushButton * btnAnnuler_;
	QPushButton * btnChoisir_;
	QPushButton * btnModifier_;
	QPushButton * btnSupprimer_;
	ModifierJoueur * dlgModifierJoueur_;
	QMessageBox *msgBox_;

	GestionJoueur *gestion_;

};