
#include "carte_FPGA.h"


Carte_FPGA::Carte_FPGA()
{
	statutport = port.lireRegistre(nreg_lect_stat_btn, statut_circuit);
}

Carte_FPGA::~Carte_FPGA()
{
}

char Carte_FPGA::lireCarte()
{
	//if (statutport) statutport = port.lireRegistre(nreg_lect_stat_btn, stat_btn);        // lecture BTN
	char compteur[4];

	for (int i = 0; i < 4; i++)
	{
		port.lireRegistre(nreg_lect_can0, echconv[0]);       // lecture canal 0
		port.lireRegistre(nreg_lect_can1, echconv[1]);       // lecture canal 1
		port.lireRegistre(nreg_lect_can2, echconv[2]);       // lecture canal 2
		port.lireRegistre(nreg_lect_can3, echconv[3]);       // lecture canal 3
		//// detection A
		if ((echconv[0] >= 0x60) && (echconv[1] >= 0x60) && (echconv[2] >= 0x25) && (echconv[3] >= 0x15))
		{
			compteur[i] = 'A';
		}//// detection E
		else if ((echconv[0] <= 0x60) && (echconv[1] >= 0x70) && (echconv[2] >= 0x45))
		{
			compteur[i] = 'E';
		}
		//// detection O
		//else if ((echconv[0] > 0x5) &&  (echconv[2] > 0x5) && (echconv[3] > 0x5) && (echconv[0] <= 0x50) && (echconv[2] <= 0x50) && (echconv[3] <= 0x50))
		//{
		//	compteur[i] = 'O';
		//	return 'O';

		//}
		// detection U
		else if ((echconv[0] <= 0x20) && (echconv[1] <= 0x70) && (echconv[2] >= 0x90) && (echconv[3] <= 0x75))
		{
			compteur[i] = 'U';
		}
		Sleep(5);
	}

	bool capter = false;
	for (int i = 0; i < 3; i++)
	{
		if (compteur[i] != compteur[i + 1])
		{
			return 'R';
		}
	}

	return compteur[0];
	
}

		
	


