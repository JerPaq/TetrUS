#pragma once

#include "gestionjoueur.h"
#include "joueur.h"

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QFont>


class Reglements : public QDialog
{
	Q_OBJECT

public:
	Reglements(QWidget *parent = 0);
	~Reglements();

private slots:
	void btnOk_Clicked();

private:
	void init();
	QLabel *lblTitre_;
	QLabel *clavier_;
	QLabel *phonemes_;
	QLabel *lblPhotoClavier_;
	QLabel *lblPhotoPhoneme_;
	QPushButton *btnOk_;
};
