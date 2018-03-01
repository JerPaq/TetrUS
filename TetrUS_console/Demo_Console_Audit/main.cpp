//Main.cpp
//Test de tableau 


#include <iostream>
#include "tableau.h"

int main()
{
	int x = 0; 
	cout << "Hello!" << endl; 
	Tetris_table tetris1; 
	tetris1.initialise_table();
	tetris1.afficher_tableau();
	
	for (int i = 0; i < 12; i++)
	{
		system("cls");
		if (i == 1)
			tetris1.square();
		if (i == 5)
			tetris1.L_shape();
		if (i == 8)
			tetris1.line();
		if (i == 12)
			tetris1.L_shape2();

		tetris1.afficher_tableau();

		if (tetris1.full_line() == 1)
		{
			tetris1.delete_line();
		}

		tetris1.iteration();
		Sleep(1000);
	}

	cin >> x;
	return 0;
}

