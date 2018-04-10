#include "CentralWidget.h"
#include "gestionjoueur.h"
#include <QMenu>
#include <QMenuBar>

CentralWidget::CentralWidget(GestionJoueur *pGestion, QWidget *parent) : QWidget(parent)
{
	gestion_ = pGestion;
	init();
}

CentralWidget::~CentralWidget()
{

}

void CentralWidget::init()
{
	btnStart_ = new QPushButton("Commencer partie");
	btnPause_ = new QPushButton("Pause");
	btnStop_ = new QPushButton("Terminer partie");

	btnStart_->setMinimumHeight(40);
	btnPause_->setMinimumHeight(40);
	btnStop_->setMinimumHeight(40);

	connect(btnStart_, SIGNAL(clicked()), this, SLOT(btnStart_Clicked()));
	connect(btnPause_, SIGNAL(clicked()), this, SLOT(btnPause_Clicked()));
	connect(btnStop_, SIGNAL(clicked()), this, SLOT(btnStop_Clicked()));

	tetrusLabel_ = new QLabel("TetrUS");

	tetrusLabel_->setStyleSheet("font: 24pt;");

	widgetJeu_ = new QWidget(this);
	widgetNextBloc_ = new QWidget(this);
	widgetHighscore_ = new QWidget(this);
	widgetStats_ = new QWidget(this);

	widgetJeu_->setObjectName("container");
	widgetNextBloc_->setObjectName("container");
	widgetHighscore_->setObjectName("container");
	widgetStats_->setObjectName("container");

	widgetJeu_->setStyleSheet("#container { border: 1px solid black }");
	widgetNextBloc_->setStyleSheet("#container { border: 1px solid black }");
	widgetHighscore_->setStyleSheet("#container { border: 1px solid black }");
	widgetStats_->setStyleSheet("#container { border: 1px solid black }");

	widgetNextBloc_->setLayout(initNextBloc());
	widgetHighscore_->setLayout(initHighscore());
	widgetStats_->setLayout(initStats());
	widgetJeu_->setLayout(initJeu());

	QGridLayout *centralGridLayout = new QGridLayout();
	centralGridLayout->addWidget(widgetNextBloc_, 0, 0, 1, 1);
	centralGridLayout->addWidget(widgetHighscore_, 1, 0, 1, 1);
	centralGridLayout->addWidget(widgetStats_, 2, 0, 1, 1);
	centralGridLayout->addWidget(widgetJeu_, 0, 1, 3, 3);

	centralGridLayout->addWidget(tetrusLabel_, 4, 0, 1, 1);

	centralGridLayout->addWidget(btnStart_, 4, 1, 1, 1);
	centralGridLayout->addWidget(btnPause_, 4, 2, 1, 1);
	centralGridLayout->addWidget(btnStop_, 4, 3, 1, 1);
	setLayout(centralGridLayout);
}

QGridLayout* CentralWidget::initJeu()
{
	QGridLayout *Layout = new QGridLayout();


	QTableWidget* Jeuwidget = new QTableWidget(this);
	Jeuwidget->setRowCount(20);
	Jeuwidget->setColumnCount(10);
	Layout->addWidget(Jeuwidget);

	return Layout;
}

QGridLayout* CentralWidget::initNextBloc()
{
	QGridLayout *Layout = new QGridLayout();
	QLabel *lblTitreNextBloc = new QLabel("Prochain Bloc");
	lblTitreNextBloc->setStyleSheet("font: 14pt;");

	Layout->addWidget(lblTitreNextBloc, 0, 0, 1, 1);

	return Layout;
}

QGridLayout* CentralWidget::initHighscore()
{
	QGridLayout *Layout = new QGridLayout();
	QLabel *lblTitreHighScore = new QLabel("Score");
	lblTitreHighScore->setStyleSheet("font: 14pt;");
	QLabel *lblScore = new QLabel("Score : ");
	lblScore_ = new QLabel("0");
	QLabel *lblHighscore = new QLabel("Highscore : ");
	lblHighscore_ = new QLabel("0");
	lblHighscore_->setText(QString::fromStdString(std::to_string(gestion_->getHighscore())));

	Layout->addWidget(lblTitreHighScore, 0, 0, 1, 2);
	Layout->addWidget(lblScore, 1, 0, 1, 1);
	Layout->addWidget(lblScore_, 1, 1, 1, 1);
	Layout->addWidget(lblHighscore, 2, 0, 1, 1);
	Layout->addWidget(lblHighscore_, 2, 1, 1, 1);

	return Layout;
}

QGridLayout* CentralWidget::initStats()
{
	QGridLayout *Layout = new QGridLayout();
	QLabel *lblTitreStat = new QLabel("Statistiques");
	lblTitreStat->setStyleSheet("font: 14pt;");
	QLabel *lblNom = new QLabel("Nom du joueur : ");
	QLabel *lblNbPartie = new QLabel("Nombre de parties : ");
	QLabel *lblNbVictoire = new QLabel("Nom de victoires : ");
	QLabel *lblPourcentage = new QLabel("Pourcentage de victoire : ");
	QLabel *lblHighscore = new QLabel("Highscore du joueur : ");

	lblNom_ = new QLabel("Aucun");
	lblNbPartie_ = new QLabel("0");
	lblNbVictoire_ = new QLabel("0");
	lblPourcentage_ = new QLabel("0");
	lblHighscoreJoueur_ = new QLabel("0");

	Layout->addWidget(lblTitreStat, 0, 0, 1, 2);
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

	return Layout;
}

void CentralWidget::btnStart_Clicked()
{
	msgBox_ = new QMessageBox();
	msgBox_->setText("Fonction 'Start' n'est pas encore implementee");
	msgBox_->setStandardButtons(QMessageBox::Save);
	msgBox_->setButtonText(QMessageBox::Save, "Ok");
	msgBox_->setDefaultButton(QMessageBox::Save);
	int ret = msgBox_->exec();
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
		lblPourcentage_->setText("0");
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
		lblPourcentage_->setText(QString::fromStdString(std::to_string(pourcentage)));
		int highscoreJoueur = temp["Highscore"];
		lblHighscoreJoueur_->setText(QString::fromStdString(std::to_string(highscoreJoueur)));
	}
	lblHighscore_->setText(QString::fromStdString(to_string(gestion_->getHighscore())));
	
}