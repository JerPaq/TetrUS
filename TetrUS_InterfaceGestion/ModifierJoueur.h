#pragma once
#include <QDialog>
#include "gestionjoueur.h"
#include "joueur.h"
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QMessageBox>


class ModifierJoueur : public QDialog
{
	Q_OBJECT

public:
	ModifierJoueur(GestionJoueur *pGestion, QWidget *parent = 0);
	~ModifierJoueur();

	bool isOk();

private slots:
	void txbNom_textEdited(const QString &arg1);
	void btnModifier_Clicked();
	void btnAnnuler_Clicked();

private:
	void init();
	
	bool ok_ = false;

	QLabel * txtLabel_;
	QLineEdit * txtNom_;
	QPushButton * btnAnnuler_;
	QPushButton * btnModifier_;

	GestionJoueur *gestion_;

	QMessageBox *msgBox_;
};
