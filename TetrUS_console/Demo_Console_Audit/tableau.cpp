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

bool Tetris_table::translation(char direction)
{
	int grandeur = formeActuelle->getLength();
	int i;
	int j;
	
	if (direction == 'G')
	{
		for (i = 0; i < grandeur; i++)
		{
			for (j = 0; j < grandeur; j++)
			{
				if (formeActuelle->getElement(i, j) == 0)
					continue;

				else if (!isFree(direction, i, j))
				{
					return false;
				}
				break;
			}

		}

	}
	else if (direction == 'D')
	{
		for (i = 0; i < grandeur; i++)
		{
			for (j = (grandeur - 1); j >= 0; j--)
			{
				if (formeActuelle->getElement(i, j) == 0)
					continue;
				else if (!isFree(direction, i, j))
				{
					cout << j;
					return false;
				}
				break;
			}
		}
	}
	else
		return false;


	move(direction);
	return true;
	
}

void Tetris_table::move(char direc)
{
	int grandeur = formeActuelle->getLength();
	int i;
	int j;
	int lastOfLine;
	int firstOfLine = 0;
	if (direc == 'G')
	{
		for (i = 0; i < grandeur; i++)
		{
			for (j = 0; j < grandeur; j++)
			{
				if (formeActuelle->getElement(i, j) != 0)
				{
					table1[positionVerticale + i][positionHorizontale + j - 1] = formeActuelle->getElement(i, j);
					lastOfLine = j;
				}
			}
			table1[positionVerticale + i][positionHorizontale + lastOfLine] = 0;
		}
		positionHorizontale--;
	}

	else if (direc == 'D')
	{
		for (i = 0; i < grandeur; i++)
		{
			for (j = (grandeur -1); j >= 0; j--)
			{
				if (formeActuelle->getElement(i, j) != 0)
				{
					table1[positionVerticale + i][positionHorizontale + j + 1] = formeActuelle->getElement(i, j);
					firstOfLine = j;
				}
			}
			table1[positionVerticale + i][positionHorizontale + firstOfLine] = 0;
		}
		positionHorizontale++;
	}
}

bool Tetris_table::isFree(char direction, int vertical, int horizontal)
{
	if (direction == 'G')
	{
		if(table1[positionVerticale + vertical][positionHorizontale + horizontal - 1] == 1)
		{
			return false;
		}
	}
	else
	{
		if (table1[positionVerticale + vertical][positionHorizontale + horizontal + 1] == 1)
		{
			return false;
		}
	}
	
	return true;
}

bool Tetris_table::ajouterForme(Forme forme) 
{
	int grandeur = forme.getLength();
	positionHorizontale = (largeur_tableau / 2) - 1;
	positionVerticale = 1;
	int i;
	int j;

	for (i = 0; i < grandeur; i++)
	{
		for (j = 0; j < grandeur; j++)
		{
			if (table1[positionVerticale + i][j + positionHorizontale] == 0) {
				table1[positionVerticale + i][j + positionHorizontale] = forme.getElement(i, j);
			}
		}
	}
	return true;
}


bool Tetris_table::afficher_tableau(ostream& os)
{
	for (int i = 0; i < hauteur_tableau; i++)
	{
		os << "| ";
		for (int j = 0; j < largeur_tableau; j++)
		{
			os << table1[i][j] << " | ";
		}
		os << endl;
	}
	os << endl; 
	return 0; 
}


void Tetris_table::nouvelleFormeApparait()
{
	buffer = *prochaineForme;
	delete[] prochaineForme;
	ajouterForme(buffer);

	prochaineForme = choixForme(randomProchaineForme);
	randomProchaineForme = rand() % 8;
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

		default:
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