#include "ModifierJoueur.h"
#include <QPushButton>
#include <QWidget>
#include <qgridlayout>

ModifierJoueur::ModifierJoueur(GestionJoueur *pGestion, QWidget *parent) :QDialog(parent)
{
	gestion_ = pGestion;
	init();
}

ModifierJoueur::~ModifierJoueur()
{

}

void ModifierJoueur::init()
{
	setWindowTitle("Modifier Joueur");
	btnAnnuler_ = new QPushButton("Annuler");
	btnModifier_ = new QPushButton("Modifier");
	txtLabel_ = new QLabel("Nom: ");
	txtNom_ = new QLineEdit(QString::fromStdString(gestion_->joueurSelect()->getName()));

	connect(btnAnnuler_, SIGNAL(clicked()), this, SLOT(btnAnnuler_Clicked()));
	connect(btnModifier_, SIGNAL(clicked()), this, SLOT(btnModifier_Clicked()));
	connect(txtNom_, SIGNAL(textEdited(QString)), this, SLOT(txbNom_textEdited(QString)));

	QGridLayout *ModifierJoueurLayout_ = new QGridLayout();
	ModifierJoueurLayout_->addWidget(txtLabel_, 0, 0, 1, 1);
	ModifierJoueurLayout_->addWidget(txtNom_, 0, 1, 1, 1);
	ModifierJoueurLayout_->addWidget(btnAnnuler_, 1, 1, 1, 1);
	ModifierJoueurLayout_->addWidget(btnModifier_, 1, 0, 1, 1);

	setLayout(ModifierJoueurLayout_);
}

void ModifierJoueur::btnAnnuler_Clicked()
{
	close();
}

void ModifierJoueur::btnModifier_Clicked()
{
	string nom = txtNom_->text().toUtf8().constData();
	if (gestion_->modifierNom(gestion_->joueurSelect()->getName(), string(nom)))
	{
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
void ModifierJoueur::txbNom_textEdited(const QString &arg1)
{
	if (arg1.length() > 0)
	{
		btnModifier_->setEnabled(true);
	}
	else
	{
		btnModifier_->setEnabled(false);
	}
}
bool ModifierJoueur::isOk()
{
	return ok_;
}