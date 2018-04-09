#include "NouveauJoueur.h"
#include <QPushButton>
#include <QWidget>
#include <qgridlayout>

NouveauJoueur::NouveauJoueur(GestionJoueur *pGestion, QWidget *parent) :QDialog(parent)
{
	gestion_ = pGestion;
	ok_ = false;
	init();

}

NouveauJoueur::~NouveauJoueur()
{

}

bool NouveauJoueur::isOk()
{
	return ok_;
}

void NouveauJoueur::init()
{
	btnAnnuler_ = new QPushButton("Annuler");
	btnCreer_ = new QPushButton("Creer");
	btnCreer_->setEnabled(false);
	btnCreer_->setDefault(true);
	txtLabel_ = new QLabel("Nom: ");
	txtNom_ = new QLineEdit();

	connect(btnAnnuler_, SIGNAL(clicked()), this, SLOT(btnAnnuler_Clicked()));
	connect(btnCreer_, SIGNAL(clicked()), this, SLOT(btnCreer_Clicked()));
	connect(txtNom_, SIGNAL(textEdited(QString)), this, SLOT(txbNom_textEdited(QString)));

	QGridLayout *NouveauJoueurLayout_ = new QGridLayout();
	NouveauJoueurLayout_->addWidget(txtLabel_, 0, 0, 1, 1);
	NouveauJoueurLayout_->addWidget(txtNom_, 0, 1, 1, 1);
	NouveauJoueurLayout_->addWidget(btnAnnuler_, 1, 1, 1, 1);
	NouveauJoueurLayout_->addWidget(btnCreer_, 1, 0, 1, 1);

	setLayout(NouveauJoueurLayout_);
}

void NouveauJoueur::txbNom_textEdited(const QString &arg1)
{
	if (arg1.length() > 0)
	{
		btnCreer_->setEnabled(true);
	}
	else
	{
		btnCreer_->setEnabled(false);
	}
}

void NouveauJoueur::btnCreer_Clicked()
{
	string nom = txtNom_->text().toUtf8().constData();
	if (gestion_->ajouterJoueur(string(nom)))
	{
		gestion_->selectionnerJoueur(nom);
		gestion_->sauvegarder();
		ok_ = true;
		close();
	}
	else
	{
		msgBox_ = new QMessageBox();
		msgBox_->setText("Ce nom existe deja.");
		msgBox_->setStandardButtons(QMessageBox::Save);
		msgBox_->setButtonText(QMessageBox::Save, "Ok");
		msgBox_->setDefaultButton(QMessageBox::Save);
		int ret = msgBox_->exec();
	}
	
}

void NouveauJoueur::btnAnnuler_Clicked()
{
	close();
}
