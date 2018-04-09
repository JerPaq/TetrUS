#include "GestionJoueur.h"

GestionJoueur::GestionJoueur()
{
	monVecteur_ = new Vecteur<Joueur>();
	joueurCourant_ = nullptr;
}

GestionJoueur::~GestionJoueur()
{
	delete monVecteur_;
}

void GestionJoueur::sauvegarder()
{
    ofstream myfile;
    myfile.open("./les_joueurs.json");
    for (int i = 0; i < monVecteur_->getTaille(); i++)
    {
        myfile << serialize(monVecteur_->get(i)) << "\n";
    }
    myfile.close();
}

bool GestionJoueur::charger()
{
    ifstream myfile("./les_joueurs.json");
    string laChaine;
    Joueur* temp;

    if (myfile.is_open())
    {
        while (getline(myfile, laChaine))
        {
            temp = deserialize(laChaine);
            monVecteur_->ajouter(temp);
        }
        myfile.close();
        return true;
    }
    else
    {
        return false;
    }

}

bool GestionJoueur::ajouterJoueur(string pNom)
{
    for (string nom : listeNom())
    {
        if (pNom.compare(nom) == 0)
        {
            return false;
        }
    }
    monVecteur_->ajouter(new Joueur(string(pNom)));
    return true;
}

bool GestionJoueur::modifierNom(string pNom, string pNouveauNom)
{
    for (string nom : listeNom())
    {
        if (pNouveauNom.compare(nom) == 0)
        {
            return false;
        }
    }
    for (int i = 0; i < monVecteur_->getTaille(); i++)
    {
        if (monVecteur_->get(i)->getName().compare(pNom) == 0)
        {
            monVecteur_->get(i)->modifierNom(pNouveauNom);
            return true;
        }
    }
    return false;
}

bool GestionJoueur::supprimerJoueur(string pNom)
{
    for (int i = 0; i < monVecteur_->getTaille(); i++)
    {
        if (monVecteur_->get(i)->getName().compare(pNom) == 0)
        {
            monVecteur_->retirer(i);
            return true;
        }
    }
    return false;
}

void GestionJoueur::selectionnerJoueur(string pNom)
{
    for (int i = 0; i < monVecteur_->getTaille(); i++)
    {
        if (monVecteur_->get(i)->getName().compare(pNom) == 0)
        {
            joueurCourant_ = monVecteur_->get(i);
        }
    }
}

void GestionJoueur::selectionnerJoueur()
{
	joueurCourant_ = nullptr;
}

list<string> GestionJoueur::listeNom()
{
    list<string> listNom;
    for (int i = 0; i < monVecteur_->getTaille(); i++)
    {
        listNom.push_back(monVecteur_->get(i)->getName());
    }
    listNom.sort();
    return listNom;
}

QStringList GestionJoueur::QlisteNom()
{
    QStringList listNom;
    for (int i = 0; i < monVecteur_->getTaille(); i++)
    {
        listNom.push_back(QString::fromStdString(monVecteur_->get(i)->getName()));
    }
    listNom.sort();
    return listNom;
}

string GestionJoueur::serialize(Joueur* pJoueur)
{
    string laChaine = pJoueur->getAttributs().dump();
    return laChaine;

    return string();
}

Joueur* GestionJoueur::deserialize(string pString)
{
    json attribut = json::parse(pString);

    return new Joueur(attribut);
}

Joueur* GestionJoueur::joueurSelect() const
{	
	return joueurCourant_;
}

int GestionJoueur::getHighscore()
{
	int score = 0;
	for (int i = 0; i < monVecteur_->getTaille(); i++)
	{
		if (score < monVecteur_->get(i)->getHighscore())
		{
			score = monVecteur_->get(i)->getHighscore();
		}
	}
	return score;
}
