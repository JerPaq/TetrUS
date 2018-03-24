//Code des fonctions de tetris


#include "tableau.h"



Tetris_table::Tetris_table()
{
	largeur = largeur_tableau;
	hauteur = hauteur_tableau;
	formeActuelle = &buffer;
	prochaineForme = new Carre();
	srand(time(NULL));
	randomProchaineForme = rand() % 7;
}


Tetris_table::~Tetris_table()
{
	if(formeActuelle != NULL)
		delete[] formeActuelle;

	if(prochaineForme != NULL)
		delete[] prochaineForme;
}

bool Tetris_table::delete_line()
{
	for (int i = hauteur_tableau - 1; i >= 0; i--)
	{
		for (int j = 0; j < largeur_tableau; j++)
		{
			table1[i][j] = table1[i-1][j];
		}
	}

	for (int j = 0; j < largeur_tableau; j++)
		table1[0][j] = 0;

	return 0;
}

bool Tetris_table::full_line()
{
	for (int j = 0; j < largeur_tableau; j++)
	{
		if (table1[hauteur_tableau - 1][j] == 0)
			return 0;
	}
	return 1;
}

bool Tetris_table::initialise_table()
{
	for (int i = 0; i < hauteur_tableau; i++)
	{
		for (int j = 0; j < largeur_tableau; j++)
		{
			table1[i][j] = 0; 
		}
	}
	return 0; 
}

bool Tetris_table::iteration()
{
	for (int j = 0; j < largeur_tableau; j++)
	{
		if (table1[hauteur_tableau - 1][j] != 1)
		{
			for (int i = hauteur_tableau - 1; i > 0; i--)
			{
				table1[i][j] = table1[i - 1][j];
			}
			table1[0][j] = 0; 
		}
		/*else if (table1[hauteur_tableau - 1][j] == 1)
		{
			int hauteur_total = 1;
			for (int h = hauteur_tableau - 1; h > 0; h--)
			{

			}
		}*/

	}
	return 0;
}


bool Tetris_table::afficher_tableau()
{
	for (int i = 0; i < hauteur_tableau; i++)
	{
		cout << "| ";
		for (int j = 0; j < largeur_tableau; j++)
		{
			cout << table1[i][j] << " | ";
		}
		cout << endl;
	}
	cout << endl; 
	return 0; 
}


void Tetris_table::nouvelleFormeApparait()
{
	buffer = *prochaineForme;
	delete[] prochaineForme;

	prochaineForme = choixForme(randomProchaineForme);
	randomProchaineForme = rand() % 7;
}


Forme* Tetris_table::choixForme(int chiffreRandom)
{
	switch(chiffreRandom)
	{
		case PYRAMIDE : 
			return new Pyramide();

		case CARRE:
			return new Carre();

		case L_VALUE:
			return new L();

		case LGAUCHE:
			return new LGauche();

		case S_VALUE:
			return new S();

		case Z_VALUE:
			return new Z();

		case LIGNE:
			return new Ligne();

	}
	return NULL;


}

Forme* Tetris_table::getFormeActuelle()
{
	std::cout << "Prochaine Vague : " << endl;
	std::cout << "Forme actuelle: " << endl;
	if (formeActuelle == NULL)
	{
		std::cout << "NULL" << endl;
		return NULL;
	}

	return formeActuelle;
}

Forme* Tetris_table::getProchaineForme()
{
	std::cout << "Prochaine Forme: " << endl;
	if (prochaineForme == NULL)
	{
		std::cout << "NULL" << endl;
		return NULL;
	}
	return prochaineForme;
}