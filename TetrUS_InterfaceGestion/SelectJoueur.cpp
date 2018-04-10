#include "selectjoueur.h"
#include <QGridLayout>

SelectJoueur::SelectJoueur(GestionJoueur *pGestion, QWidget *parent) : QDialog(parent)
{
	gestion_ = pGestion;
	ok_ = false;
	init();

}

SelectJoueur::~SelectJoueur()
{

}

bool SelectJoueur::isOk()
{
	return ok_;
}

void SelectJoueur::init()
{
	setWindowTitle("Selectionner Joueur");
	btnChoisir_ = new QPushButton("Choisir");
	btnAnnuler_ = new QPushButton("Annuler");
	btnModifier_ = new QPushButton("Modifier");
	btnSupprimer_ = new QPushButton("Supprimer");
	
	btnChoisir_->setEnabled(false);
	btnModifier_->setEnabled(false);
	btnSupprimer_->setEnabled(false);

	lsvJoueur_ = new QListWidget();
	for (QString nom : gestion_->QlisteNom())
	{
		QListWidgetItem *temp = new QListWidgetItem;
		temp->setText(nom);
		lsvJoueur_->addItem(temp);
	}
	connect(lsvJoueur_, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(joueurChoisi(QListWidgetItem*)));

	connect(btnAnnuler_, SIGNAL(clicked()), this, SLOT(btnAnnuler_Clicked()));
	connect(btnChoisir_, SIGNAL(clicked()), this, SLOT(btnChoisir_Clicked()));
	connect(btnModifier_, SIGNAL(clicked()), this, SLOT(btnModifier_Clicked()));
	connect(btnSupprimer_, SIGNAL(clicked()), this, SLOT(btnSupprimer_Clicked()));

	QGridLayout *SelectJoueurLayout_ = new QGridLayout();

	SelectJoueurLayout_->addWidget(lsvJoueur_, 0, 0, 1, 4);
	SelectJoueurLayout_->addWidget(btnChoisir_, 1, 0, 1, 1);
	SelectJoueurLayout_->addWidget(btnModifier_, 1, 1, 1, 1);
	SelectJoueurLayout_->addWidget(btnSupprimer_, 1, 2, 1, 1);
	SelectJoueurLayout_->addWidget(btnAnnuler_, 1, 3, 1, 1);

	setLayout(SelectJoueurLayout_);

}

void SelectJoueur::btnAnnuler_Clicked()
{
	close();
}

void SelectJoueur::btnChoisir_Clicked()
{
	gestion_->selectionnerJoueur(lsvJoueur_->currentItem()->text().toUtf8().constData());
	ok_ = true;
	close();
}

void SelectJoueur::btnModifier_Clicked()
{
	Joueur* temp = gestion_->joueurSelect();
	gestion_->selectionnerJoueur(lsvJoueur_->currentItem()->text().toUtf8().constData());
	dlgModifierJoueur_ = new ModifierJoueur(gestion_, this);
	dlgModifierJoueur_->exec();
	if (temp != nullptr)
	{
		gestion_->selectionnerJoueur(temp->getName());
	}
	else
	{
		gestion_->selectionnerJoueur();
	}

	if (dlgModifierJoueur_->isOk())
	{
		refreshList();
	}
}

void SelectJoueur::btnSupprimer_Clicked()
{
	msgBox_ = new QMessageBox();
	msgBox_->setText("Etes-vous certains de vouloir supprimer ce joueur?");
	msgBox_->setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
	msgBox_->setButtonText(QMessageBox::Cancel, "Non");
	msgBox_->setButtonText(QMessageBox::Save, "Oui");
	msgBox_->setDefaultButton(QMessageBox::Cancel);
	int ret = msgBox_->exec();

	switch (ret) {
	case QMessageBox::Save:
		if((gestion_->joueurSelect() != nullptr) && (gestion_->joueurSelect()->getName() == lsvJoueur_->currentItem()->text().toUtf8().constData()))
		{
			gestion_->selectionnerJoueur();
		}
		gestion_->supprimerJoueur(lsvJoueur_->currentItem()->text().toUtf8().constData());
		gestion_->sauvegarder();
		ok_ = true;
		refreshList();
		break;
	case QMessageBox::Cancel:
		break;
	default:
		break;
	}

}

void SelectJoueur::joueurChoisi(QListWidgetItem* item)
{
	if (item != nullptr)
	{
		btnChoisir_->setEnabled(true);
		btnModifier_->setEnabled(true);
		btnSupprimer_->setEnabled(true);
	}

}

void SelectJoueur::refreshList()
{
	lsvJoueur_->clear();
	for (QString nom : gestion_->QlisteNom())
	{
		QListWidgetItem *temp = new QListWidgetItem;
		temp->setText(nom);
		lsvJoueur_->addItem(temp);
	}
}