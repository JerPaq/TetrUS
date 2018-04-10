#include "CentralWidget.h"
#include "gestionjoueur.h"
#include <QMenu>
#include <QMenuBar>
#include <QFont>
#include <QHeaderView>

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

	QFont newFont("Courier", 8, QFont::Decorative, true);

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
	QPixmap mypix ("tetrus_logo.png");
	tetrusLabel_->setPixmap(mypix);
	tetrusLabel_->setAlignment(Qt::AlignCenter);

	widgetJeu_ = new QWidget(this);
	widgetNextBloc_ = new QWidget(this);
	widgetHighscore_ = new QWidget(this);
	widgetStats_ = new QWidget(this);

	widgetJeu_->setMaximumWidth(271);
	widgetJeu_->setMinimumWidth(271);
	widgetJeu_->setMaximumHeight(521);
	widgetJeu_->setMinimumHeight(521);

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
}
QGridLayout* CentralWidget::initJeu()
{
	QGridLayout *Layout = new QGridLayout();

	Tetris_ = new QTableWidget(this);
	Tetris_->setRowCount(20);
	Tetris_->setColumnCount(10);
	Tetris_->setMaximumWidth(251);
	Tetris_->setMinimumWidth(251);
	Tetris_->setMaximumHeight(501);
	Tetris_->setMinimumHeight(501);
	Tetris_->setEditTriggers(QAbstractItemView::NoEditTriggers);
	Tetris_->setSelectionMode(QAbstractItemView::NoSelection);
	Tetris_->horizontalHeader()->hide();
	Tetris_->verticalHeader()->hide();

	Tetris_->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	Tetris_->verticalHeader()->setDefaultSectionSize(25);
	Tetris_->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	Tetris_->horizontalHeader()->setDefaultSectionSize(25);

	Tetris_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	Tetris_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	QTableWidgetItem *cubesHeaderItem = new QTableWidgetItem();
	cubesHeaderItem->setIcon(QIcon(QPixmap("smily.png")));
	Tetris_->setItem(0, 2, cubesHeaderItem);

	Layout->addWidget(Tetris_);

	return Layout;
}
QVBoxLayout* CentralWidget::initNextBloc()
{
	QFont newFont("Courier", 8, QFont::Decorative, true);

	widgetNextBloc_->setMaximumWidth(225);

	QVBoxLayout *VLayoutNextBloc = new QVBoxLayout();
	VLayoutNextBloc->addWidget(widgetNextBloc_);
	QLabel *lblTitreNextBloc = new QLabel("Prochain Bloc");
	lblTitreNextBloc->setFont(newFont);
	lblTitreNextBloc->setAlignment(Qt::AlignCenter);
	lblTitreNextBloc->setMaximumWidth(225);
	VLayoutNextBloc->addWidget(lblTitreNextBloc);
	VLayoutNextBloc->setContentsMargins(0, 0, 0, 5);
	VLayoutNextBloc->setSpacing(0);

	VLayoutNextBloc->addStretch(0);
	return VLayoutNextBloc;
}
QVBoxLayout* CentralWidget::initHighscore()
{
	QFont newFont("Courier", 8, QFont::Decorative, true);

	widgetHighscore_->setMaximumWidth(225);

	QVBoxLayout *VLayoutHighscore = new QVBoxLayout();
	QGridLayout *Layout = new QGridLayout();
	QLabel *lblTitreHighScore = new QLabel("Score");
	lblTitreHighScore->setFont(newFont);
	lblTitreHighScore->setAlignment(Qt::AlignCenter);
	lblTitreHighScore->setMaximumWidth(225);
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
	VLayoutHighscore->addWidget(widgetHighscore_);
	VLayoutHighscore->addWidget(lblTitreHighScore);
	VLayoutHighscore->setContentsMargins(0, 0, 0, 5);
	VLayoutHighscore->setSpacing(0);

	VLayoutHighscore->addStretch(0);
	return VLayoutHighscore;
}
QVBoxLayout* CentralWidget::initStats()
{
	QFont newFont("Courier", 8, QFont::Decorative, true);

	widgetStats_->setMaximumWidth(225);

	QVBoxLayout *VLayoutStats = new QVBoxLayout();
	QGridLayout *Layout = new QGridLayout();
	QLabel *lblTitreStat = new QLabel("Statistiques");
	lblTitreStat->setFont(newFont);
	lblTitreStat->setAlignment(Qt::AlignCenter);
	lblTitreStat->setMaximumWidth(225);
	QLabel *lblNom = new QLabel("Nom du joueur : ");
	QLabel *lblNbPartie = new QLabel("Nombre de parties : ");
	QLabel *lblNbVictoire = new QLabel("Nom de victoires : ");
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
	VLayoutStats->addWidget(widgetStats_);
	VLayoutStats->addWidget(lblTitreStat);
	VLayoutStats->setContentsMargins(0, 0, 0, 0);
	VLayoutStats->setSpacing(0);
	VLayoutStats->addStretch(0);

	return VLayoutStats;
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

}