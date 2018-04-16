#include "CentralWidget.h"
#include "gestionjoueur.h"
#include <QMenu>
#include <QMenuBar>
#include <QFont>
#include <QHeaderView>
//Lecture du clavier
#include <conio.h>
//Timer
#include <Windows.h>

CentralWidget::CentralWidget(GestionJoueur *pGestion, QWidget *parent) : QWidget(parent)
{
	gestion_ = pGestion;
	init();
	
	largeur = largeur_tableau;
	hauteur = hauteur_tableau;
	formeActuelle = &buffer;
	prochaineForme = new Carre();
	srand(time(NULL));
	randomProchaineForme = rand() % 7;
}

CentralWidget::~CentralWidget()
{
	/*int grandeur = formeActuelle->getLength();
	if (formeActuelle != NULL)
	{		
		for (int i = 0; i < grandeur; i++)
		{
			delete formeActuelle->at(i);
		}
		delete[] formeActuelle;
	}

	if (prochaineForme != NULL)
		delete prochaineForme;*/
}

void CentralWidget::init()
{
	
	QFont newFont("Courier", 8, QFont::Decorative, true);

	//btnStart_ = new QPushButton("Commencer partie");
	//btnPause_ = new QPushButton("Pause");
	//btnStop_ = new QPushButton("Terminer partie");
	btnStart_ = new QPushButton();
	btnPause_ = new QPushButton();
	btnStop_ = new QPushButton();
	QPixmap pixStart("./photos/start.png");
	btnStart_->setStyleSheet("background-color:white");
	btnStart_->setIcon(pixStart);
	btnStart_->setIconSize(pixStart.rect().size());
	QPixmap pixPause("./photos/pause.png");
	btnPause_->setStyleSheet("background-color:white");
	btnPause_->setIcon(pixPause);
	btnPause_->setIconSize(pixPause.rect().size());
	QPixmap pixStop("./photos/stop.png");
	btnStop_->setStyleSheet("background-color:white");
	btnStop_->setIcon(pixStop);
	btnStop_->setIconSize(pixStop.rect().size());

	btnStart_->setMinimumHeight(40);
	btnPause_->setMinimumHeight(40);
	btnStop_->setMinimumHeight(40);

	connect(btnStart_, SIGNAL(clicked()), this, SLOT(btnStart_Clicked()));
	connect(btnPause_, SIGNAL(clicked()), this, SLOT(btnPause_Clicked()));
	connect(btnStop_, SIGNAL(clicked()), this, SLOT(btnStop_Clicked()));


	tetrusLabel_ = new QLabel("TetrUS");
	QPixmap mypix ("./photos/tetrus_logo.png");
	tetrusLabel_->setPixmap(mypix);
	tetrusLabel_->setAlignment(Qt::AlignCenter);

	widgetJeu_ = new QWidget(this);
	widgetNextBloc_ = new QWidget(this);
	widgetHighscore_ = new QWidget(this);
	widgetStats_ = new QWidget(this);

	widgetJeu_->setMaximumWidth(322);
	widgetJeu_->setMinimumWidth(322);
	widgetJeu_->setMaximumHeight(620);
	widgetJeu_->setMinimumHeight(620);

	widgetJeu_->setObjectName("container");
	widgetNextBloc_->setObjectName("container");
	widgetHighscore_->setObjectName("container");
	widgetStats_->setObjectName("container");

	widgetJeu_->setStyleSheet("#container { border: 1px solid black }");
	widgetNextBloc_->setStyleSheet("#container { border: 1px solid black }");
	widgetHighscore_->setStyleSheet("#container { border: 1px solid black }");
	widgetStats_->setStyleSheet("#container { border: 1px solid black }");

	QVBoxLayout *widgetBoites = new QVBoxLayout();
	widgetBoites->addLayout(initNextBloc());
	widgetBoites->addLayout(initHighscore());
	widgetBoites->addLayout(initStats());
	QHBoxLayout *widgetBoutons = new QHBoxLayout();
	widgetBoutons->addWidget(btnStart_);
	widgetBoutons->addWidget(btnPause_);
	widgetBoutons->addWidget(btnStop_);

	widgetJeu_->setLayout(initJeu());

	QGridLayout *centralGridLayout = new QGridLayout();
	centralGridLayout->addLayout(widgetBoites, 0, 0, 1, 1);
	centralGridLayout->addWidget(widgetJeu_, 0, 1, 1, 1);
	centralGridLayout->addWidget(tetrusLabel_, 1, 0, 1, 1);
	centralGridLayout->addLayout(widgetBoutons, 1, 1, 1, 1);

	setLayout(centralGridLayout);

	timerJeu_ = new QTimer;
	timerPhoneme_ = new QTimer;

}

QGridLayout* CentralWidget::initJeu()
{
	QGridLayout *Layout = new QGridLayout();

	Tetris_ = new QTableWidget(this);
	Tetris_->setRowCount(20);
	Tetris_->setColumnCount(10);
	Tetris_->setMaximumWidth(302);
	Tetris_->setMinimumWidth(302);
	Tetris_->setMaximumHeight(602);
	Tetris_->setMinimumHeight(602);
	Tetris_->setEditTriggers(QAbstractItemView::NoEditTriggers);
	Tetris_->setSelectionMode(QAbstractItemView::NoSelection);
	Tetris_->horizontalHeader()->hide();
	Tetris_->verticalHeader()->hide();

	Tetris_->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	Tetris_->verticalHeader()->setDefaultSectionSize(30);
	Tetris_->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	Tetris_->horizontalHeader()->setDefaultSectionSize(30);

	Tetris_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	Tetris_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//Test pour afficher un cube//
	//QTableWidgetItem *cubesHeaderItem = new QTableWidgetItem();
	//cubesHeaderItem->setBackgroundColor(QColor(255, 0, 0));
	//cubesHeaderItem->setIcon(QIcon(QPixmap("smily.png")));
	//Tetris_->setItem(0, 2, cubesHeaderItem);

	Layout->addWidget(Tetris_);

	return Layout;
}

QVBoxLayout* CentralWidget::initNextBloc()
{
	widgetNextBloc_->setMaximumWidth(225);

	QVBoxLayout *VLayoutNextBloc = new QVBoxLayout();

	QLabel *lblNextBloc = new QLabel();
	QPixmap NextBlocpix("./photos/carre.png");
	lblNextBloc->setPixmap(NextBlocpix);
	lblNextBloc->setAlignment(Qt::AlignCenter);
	QHBoxLayout *Layout = new QHBoxLayout();
	Layout->addWidget(lblNextBloc);
	widgetNextBloc_->setLayout(Layout);
	

	/*VLayoutNextBloc->addWidget(widgetNextBloc_);*/
	QLabel *lblTitreNextBloc = new QLabel("Prochain Bloc");
	QPixmap mypix("./photos/prochainbloc.png");
	lblTitreNextBloc->setPixmap(mypix);
	lblTitreNextBloc->setAlignment(Qt::AlignCenter);
	VLayoutNextBloc->setContentsMargins(0, 0, 0, 5);
	VLayoutNextBloc->setSpacing(0);

	VLayoutNextBloc->addWidget(lblTitreNextBloc);
	VLayoutNextBloc->addWidget(widgetNextBloc_);

	VLayoutNextBloc->addStretch(0);
	return VLayoutNextBloc;
}

QVBoxLayout* CentralWidget::initHighscore()
{
	widgetHighscore_->setMaximumWidth(225);

	QVBoxLayout *VLayoutHighscore = new QVBoxLayout();
	QGridLayout *Layout = new QGridLayout();
	QLabel *lblTitreHighScore = new QLabel("Score");
	QPixmap mypix("./photos/score.png");
	lblTitreHighScore->setPixmap(mypix);
	lblTitreHighScore->setAlignment(Qt::AlignCenter);
	QLabel *lblScore = new QLabel("Score : ");
	lblScore_ = new QLabel("0");
	QLabel *lblHighscore = new QLabel("Highscore : ");
	lblHighscore_ = new QLabel("0");
	lblHighscore_->setText(QString::fromStdString(std::to_string(gestion_->getHighscore())));

	Layout->addWidget(lblScore, 1, 0, 1, 1);
	Layout->addWidget(lblScore_, 1, 1, 1, 1);
	Layout->addWidget(lblHighscore, 2, 0, 1, 1);
	Layout->addWidget(lblHighscore_, 2, 1, 1, 1);
	widgetHighscore_->setLayout(Layout);
	VLayoutHighscore->setContentsMargins(0, 0, 0, 5);
	VLayoutHighscore->setSpacing(0);

	VLayoutHighscore->addWidget(lblTitreHighScore);
	VLayoutHighscore->addWidget(widgetHighscore_);

	VLayoutHighscore->addStretch(0);
	return VLayoutHighscore;
}

QVBoxLayout* CentralWidget::initStats()
{
	widgetStats_->setMaximumWidth(225);

	QVBoxLayout *VLayoutStats = new QVBoxLayout();
	QGridLayout *Layout = new QGridLayout();
	QLabel *lblTitreStat = new QLabel("Statistiques");
	QPixmap mypix("./photos/statistiques.png");
	lblTitreStat->setPixmap(mypix);
	lblTitreStat->setAlignment(Qt::AlignCenter);
	QLabel *lblNom = new QLabel("Nom du joueur : ");
	QLabel *lblNbPartie = new QLabel("Nombre de parties : ");
	QLabel *lblNbVictoire = new QLabel("Nombre de victoires : ");
	QLabel *lblPourcentage = new QLabel("Pourcentage de victoire : ");
	QLabel *lblHighscore = new QLabel("Highscore du joueur : ");

	lblNom_ = new QLabel("Aucun");
	lblNbPartie_ = new QLabel("0");
	lblNbVictoire_ = new QLabel("0");
	lblPourcentage_ = new QLabel("0%");
	lblHighscoreJoueur_ = new QLabel("0");

	Layout->addWidget(lblNom, 1, 0, 1, 1);
	Layout->addWidget(lblNom_, 1, 1, 1, 1);
	Layout->addWidget(lblNbPartie, 2, 0, 1, 1);
	Layout->addWidget(lblNbPartie_, 2, 1, 1, 1);
	Layout->addWidget(lblNbVictoire, 3, 0, 1, 1);
	Layout->addWidget(lblNbVictoire_, 3, 1, 1, 1);
	Layout->addWidget(lblPourcentage, 4, 0, 1, 1);
	Layout->addWidget(lblPourcentage_, 4, 1, 1, 1);
	Layout->addWidget(lblHighscore, 5, 0, 1, 1);
	Layout->addWidget(lblHighscoreJoueur_, 5, 1, 1, 1);

	widgetStats_->setLayout(Layout);
	VLayoutStats->setContentsMargins(0, 0, 0, 0);
	VLayoutStats->setSpacing(0);

	VLayoutStats->addWidget(lblTitreStat);
	VLayoutStats->addWidget(widgetStats_);

	VLayoutStats->addStretch(0);

	return VLayoutStats;
}

void CentralWidget::btnStart_Clicked()
{
	//msgBox_ = new QMessageBox();
	//msgBox_->setText("Fonction 'Start' n'est pas encore implementee");
	//msgBox_->setStandardButtons(QMessageBox::Save);
	//msgBox_->setButtonText(QMessageBox::Save, "Ok");
	//msgBox_->setDefaultButton(QMessageBox::Save);
	//int ret = msgBox_->exec();
	
	if (!activeGame)
	{
		initialise_table();
		refreshGame();
		run_game();
	}
}

void CentralWidget::btnPause_Clicked()
{
	msgBox_ = new QMessageBox();
	msgBox_->setText("Fonction 'Pause' n'est pas encore implementee");
	msgBox_->setStandardButtons(QMessageBox::Save);
	msgBox_->setButtonText(QMessageBox::Save, "Ok");
	msgBox_->setDefaultButton(QMessageBox::Save);
	int ret = msgBox_->exec();
}

void CentralWidget::btnStop_Clicked()
{
	msgBox_ = new QMessageBox();
	msgBox_->setText("Terminer la partie");
	msgBox_->setInformativeText("Voulez-vous vraiment quitter le jeu TetrUS? ");
	msgBox_->setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
	msgBox_->setButtonText(QMessageBox::Cancel, "Non");
	msgBox_->setButtonText(QMessageBox::Save, "Ok");
	msgBox_->setDefaultButton(QMessageBox::Save);
	int ret = msgBox_->exec();

	switch (ret) {
	case QMessageBox::Save:
		this->setAttribute(Qt::WA_DeleteOnClose);
		connect(this, SIGNAL(destroyed()), this->parent(), SLOT(menuQuitter_Clicked()));
		close();
		break;
	case QMessageBox::Cancel:
		break;
	default:
		break;
	}
}

void CentralWidget::refreshUI()
{
	if (gestion_->joueurSelect() == nullptr)
	{
		lblNom_->setText("Aucun");
		lblNbPartie_->setText("0");
		lblNbVictoire_->setText("0");
		lblPourcentage_->setText("0%");
		lblHighscoreJoueur_->setText("0");
	}
	else
	{
		json temp = gestion_->joueurSelect()->getAttributs();

		lblNom_->setText(QString::fromStdString(temp["Name"]));
		int nbPartie = temp["NbPartie"];
		lblNbPartie_->setText(QString::fromStdString(std::to_string(nbPartie)));
		int nbVictoire = temp["NbVictoire"];
		lblNbVictoire_->setText(QString::fromStdString(std::to_string(nbVictoire)));
		int pourcentage = temp["Pourcentage"];
		lblPourcentage_->setText((QString::fromStdString(std::to_string(pourcentage))) + "%");
		int highscoreJoueur = temp["Highscore"];
		lblHighscoreJoueur_->setText(QString::fromStdString(std::to_string(highscoreJoueur)));
	}
	lblHighscore_->setText(QString::fromStdString(to_string(gestion_->getHighscore())));
	
}


void CentralWidget::refreshGame()
{
	for (int i = 0; i < hauteur_tableau; i++)
	{
		for (int j = 0; j < largeur_tableau; j++)
		{
			if (table1[i][j] != 0)
			{
				QTableWidgetItem *cubesHeaderItem = new QTableWidgetItem();
				switch (table1[i][j])
				{
				case PYRAMIDE:
					cubesHeaderItem->setBackgroundColor(QColor(141, 0, 255));
					break;
				case CARRE:
					cubesHeaderItem->setBackgroundColor(QColor(255, 255, 0));
					break;
				case L_VALUE:
					cubesHeaderItem->setBackgroundColor(QColor(255, 126, 0));
					break;
				case LGAUCHE:
					cubesHeaderItem->setBackgroundColor(QColor(0, 11, 232));
					break;
				case S_VALUE:
					cubesHeaderItem->setBackgroundColor(QColor(24, 255, 0));
					break;
				case Z_VALUE:
					cubesHeaderItem->setBackgroundColor(QColor(255, 0, 0));
					break;
				default:
					cubesHeaderItem->setBackgroundColor(QColor(0, 232, 226));
					break;
				}
				Tetris_->setItem(i, j, cubesHeaderItem);
			}
			else
			{
				QTableWidgetItem *cubesHeaderItem = new QTableWidgetItem();
				cubesHeaderItem->setBackgroundColor(QColor(255, 255, 255));
				Tetris_->setItem(i, j, cubesHeaderItem);
			}
		}
	}
	Tetris_->repaint();
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////         SECTION JEU               /////////////////////////////  
/////////////////////////////////////////////////////////////////////////////////////////////

bool CentralWidget::iteration()
{

	int grandeur = formeActuelle->getLength();
	int j;

	for (j = 0; j < grandeur; j++)
	{
		int index = findLastDown(formeActuelle, 0, j, false);

		if (index == -1)
			continue;
		else
		{
			if (!isFree('D', index, j))
				return false;
		}
	}
	return true;
}

int CentralWidget::findLastDown(Forme* pForme, int i, int j, bool pNonVide)
{
	if ((pForme->getLength() == i + 1) && (pForme->getElement(i, j) == 0))
	{
		return -1;
	}
	else if ((pForme->getLength() == i + 1) && (pForme->getElement(i, j) != 0))
	{
		return i;
	}
	else if ((pForme->getElement(i, j) == 0) && !pNonVide)
	{
		return findLastDown(pForme, i + 1, j, false);
	}
	else if ((pForme->getElement(i, j) == 0) && pNonVide)
	{
		return i - 1;
	}
	else if ((pForme->getElement(i, j) != 0) && !pNonVide)
	{
		return findLastDown(pForme, i + 1, j, true);
	}
	else if ((pForme->getElement(i, j) != 0) && pNonVide)
	{
		return findLastDown(pForme, i + 1, j, true);
	}
}

bool CentralWidget::translation(char direction)
{
	int grandeur = formeActuelle->getLength();
	int i;
	int j;

	if (direction == 'L')
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
	else if (direction == 'R')
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

void CentralWidget::move(char direc)
{
	int grandeur = formeActuelle->getLength();
	int i;
	int j;
	int lastOfLine;
	int firstOfLine = 0;
	if (direc == 'L')
	{
		for (i = 0; i < grandeur; i++)
		{
			for (j = 0; j < grandeur; j++)
			{
				if (formeActuelle->getElement(i, j) != 0)
				{
					table1[positionHauteur + i][positionLargeur + j - 1] = formeActuelle->getElement(i, j);
					lastOfLine = j;
				}
			}
			table1[positionHauteur + i][positionLargeur + lastOfLine] = 0;
		}
		positionLargeur--;
	}

	else if (direc == 'R')
	{
		for (i = 0; i < grandeur; i++)
		{
			for (j = (grandeur - 1); j >= 0; j--)
			{
				if (formeActuelle->getElement(i, j) != 0)
				{
					table1[positionHauteur + i][positionLargeur + j + 1] = formeActuelle->getElement(i, j);
					firstOfLine = j;
				}
			}
			table1[positionHauteur + i][positionLargeur + firstOfLine] = 0;
		}
		positionLargeur++;
	}

	else if (direc == 'D')
	{
		for (i = grandeur - 1; i >= 0; i--)
		{
			for (j = 0; j < grandeur; j++)
			{
				if (formeActuelle->getElement(i, j) != 0)
				{
					table1[positionHauteur + i + 1][positionLargeur + j] = formeActuelle->getElement(i, j);
					firstOfLine = i;
					table1[positionHauteur + i][positionLargeur + j] = 0;
				}				
			}			
		}
		positionHauteur++;
	}

	refreshGame();
}

bool CentralWidget::isFree(char direction, int vertical, int horizontal)
{
	if (direction == 'L')
	{
		if ((table1[positionHauteur + vertical][positionLargeur + horizontal - 1] != 0) || (positionLargeur + horizontal - 1 < 0))
		{
			return false;
		}
	}
	else if (direction == 'R')
	{
		if ((table1[positionHauteur + vertical][positionLargeur + horizontal + 1] != 0) || (positionLargeur + horizontal + 1 > largeur_tableau - 1))
		{
			return false;
		}
	}

	if (direction == 'D')
	{
		if ((table1[positionHauteur + vertical + 1][positionLargeur + horizontal] != 0) || (positionHauteur + vertical + 1 > hauteur_tableau + 1))
		{
			return false;
		}
	}

	return true;
}

void CentralWidget::run_game()
{
	current_score = 0;
	prochaineForme = choixForme(rand() % 7);
	activeGame = true;
	alive = true;
	nouvelleFormeApparait();
	refreshGame();

	for (int j = 0; j < 22; j++)
	{
		Sleep(500);
		iteration();
	}

	int i = 0;
	while (activeGame && alive)
	{
		Sleep(500);
		if (iteration())
		{
			move('D');
		}
		else
		{
			nouvelleFormeApparait();
			refreshGame();
		}
	}
}

//Elements fonctionnnels
bool CentralWidget::ajouterForme(Forme forme)
{
	int grandeurForme = forme.getLength(); //Obtenir la taille de la forme
	positionLargeur = (largeur_tableau / 2) - 1;
	positionHauteur = 0;

	for (int i = 0; i < grandeurForme; i++)
	{
		for (int j = 0; j < grandeurForme; j++)
		{
			//if (table1[i + positionHauteur][j + positionLargeur] == 0) 
			//{
			table1[i + positionHauteur][j + positionLargeur] = forme.getElement(i, j);
			//}
		}
	}
	return true;
}

void CentralWidget::nouvelleFormeApparait()
{
	buffer = *prochaineForme;
	delete[] prochaineForme;
	ajouterForme(buffer);

	prochaineForme = choixForme(randomProchaineForme);
	randomProchaineForme = rand() % 8;

	switch (randomProchaineForme)
	{
		case PYRAMIDE:
			QPixmap NextBlocpix("./photos/Pyramide.png");
			break; 
		case CARRE:
			break;
		case L_VALUE:
			break;
		case LGAUCHE:
			break;
		case S_VALUE:
			break;
		case Z_VALUE:
			break; 
		default:
			break;
	}
}

Forme* CentralWidget::choixForme(int chiffreRandom)
{
	switch (chiffreRandom)
	{
	case PYRAMIDE:
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

Forme* CentralWidget::getFormeActuelle()
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

Forme* CentralWidget::getProchaineForme()
{
	if (prochaineForme == NULL)
	{
		std::cout << "NULL" << endl;
		return NULL;
	}
	return prochaineForme;
}

void CentralWidget::delete_line(int deleted_line)
{
	for (int i = deleted_line; i >= 0; i--)
	{
		for (int j = 0; j < largeur_tableau; j++)
		{
			table1[i][j] = table1[i - 1][j];
		}
	}

	for (int j = 0; j < largeur_tableau; j++)
		table1[0][j] = 0;

	current_score++;
}

bool CentralWidget::full_line(int line_check)
{
	for (int j = 0; j < largeur_tableau; j++)
	{
		if (table1[line_check - 1][j] == 0)
			return false;
	}

	return true;
}

void CentralWidget::check_lines()
{
	for (int i = 0; i < hauteur_tableau; i++)
	{
		if (full_line(i))
		{
			delete_line(i);
		}
	}
}

bool CentralWidget::initialise_table()
{
	for (int i = 0; i < hauteur_tableau; i++)
	{
		for (int j = 0; j < largeur_tableau; j++)
		{
			table1[i][j] = 0;
		}
	}
	return true;
} 

void CentralWidget::processusJeu()
{

}

