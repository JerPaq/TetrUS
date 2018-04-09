#pragma once

#include "gestionjoueur.h"
#include "joueur.h"

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QMessageBox>


class NouveauJoueur : public QDialog
{
	Q_OBJECT

public:
	NouveauJoueur(GestionJoueur *pGestion, QWidget *parent = 0);
	~NouveauJoueur();

	bool isOk();

private slots:
	void txbNom_textEdited(const QString &arg1);
	void btnCreer_Clicked();
	void btnAnnuler_Clicked();

private:
	void init();

	bool ok_;

	QLabel *txtLabel_; 
	QLineEdit *txtNom_;
	QPushButton *btnAnnuler_;
	QPushButton *btnCreer_;

	GestionJoueur *gestion_;

	QMessageBox *msgBox_;
};
