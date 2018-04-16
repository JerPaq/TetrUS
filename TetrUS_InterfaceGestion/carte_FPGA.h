#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
//#include <cmath>
using namespace std;

#include "CommunicationFPGA.h"


const string  CANB2USBCONSOLE_VERS = "V01.00a";


//string ladate()
//{
//	string s;
//	time_t t;             // strutures requises a la lecture
//						  // de la date et de l'heure systeme
//	time(&t);
//#ifdef WIN32
//	char str[0x100];
//	if (!ctime_s(str, 0x100, &t))
//		s.assign(str);
//	else
//		s.assign("erreur ctime_s");
//#endif
//#ifdef UNIX
//	s = ctime(&t);
//#endif
//	return s;
//}

class Carte_FPGA
{
public:
	Carte_FPGA();
	~Carte_FPGA();

	char lireCarte();

private:
	BOOL statutport = false;            // statut du port de communication qui sera cree


	int compteur_temps = 0;
	int swt = 0;                         // donnee recue du FPGA
	int aff7sg_octet0 = 0;               // octet 0 (droite) pour afficheur 7 segments
	int aff7sg_octet1 = 0;               // octet 0 (droite) pour afficheur 7 segments
	int stat_btn = 0;               // donnee recue du FPGA: statut et BTN
	int echconv[4];                      // donnee converties recues du FPGA
	int canal_a_afficher = 0;     // donnee recue du FPGA
	int indice_canal_a_afficher = 0;

	const int nitermax = 10000;         // Nbre d'itération max de la boucle de lecture d'acquisition (limite pour tests)
										// changer la condition de boucle sans cette limite selon le besoin de l'application
	const int delai_boucle = 10;         // delai d'attente ajouté dans la boucle de lecture en ms

										 // numeros de registres correspondants pour les echanges FPGA <-> PC  ...
	unsigned const int nreg_lect_stat_btn = 0;  // fpga -> PC  Statut et BTN lus FPGA -> PC
	unsigned const int nreg_lect_swt = 1;       // fpga -> PC  SWT lus FPGA -> PC
	unsigned const int nreg_lect_cmpt_t = 2;    // fpga -> PC  compteur temps FPGA -> PC 
	unsigned const int nreg_lect_can0 = 3;      // fpga -> PC  canal 0 lus FPGA -> PC
	unsigned const int nreg_lect_can1 = 4;      // fpga -> PC  canal 1 lus FPGA -> PC
	unsigned const int nreg_lect_can2 = 5;      // fpga -> PC  canal 2 lus FPGA -> PC
	unsigned const int nreg_lect_can3 = 6;      // fpga -> PC  canal 3 lus FPGA -> PC
	unsigned const int nreg_ecri_aff7sg0 = 7;   // PC -> fpga (octet 0  aff.7 seg.)
	unsigned const int nreg_ecri_aff7sg1 = 8;   // PC -> fpga (octet 1  aff.7 seg.)
	unsigned const int nreg_ecri_aff7dot = 9;   // PC -> fpga (donnees dot-points)
	unsigned const int nreg_ecri_led = 10;      // PC -> fpga (donnees leds)


	CommunicationFPGA port;   // Instance du port de communication

							  /*if (!port.estOk())
							  {
							  cout << port.messageErreur() << endl;
							  return 1;
							  }
							  else
							  cout << "Statut initial du port de communication = " << port.estOk() << endl << endl;*/

	int statut_circuit = 0;

};