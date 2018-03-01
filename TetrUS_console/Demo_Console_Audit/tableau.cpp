//Code des fonctions de tetris


#include "tableau.h"



Tetris_table::Tetris_table()
{

}


Tetris_table::~Tetris_table()
{

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


//Objets dans le tableau, il faut le transformer en classe eventuellement. 
void Tetris_table::square()
{
	table1[0][0] = 1;
	table1[0][1] = 1;
	table1[1][1] = 1; 
	table1[1][0] = 1; 
}

void Tetris_table::L_shape()
{
	table1[0][2] = 1;
	table1[1][2] = 1;
	table1[2][2] = 1;
	table1[2][3] = 1;
}


void Tetris_table::L_shape2()
{
	table1[0][3] = 1;
	table1[1][3] = 1;
	table1[2][3] = 1;
	table1[0][2] = 1;
}


void Tetris_table::line()
{
	table1[0][4] = 1;
	table1[1][4] = 1;
	table1[2][4] = 1;
	table1[3][4] = 1;
}


