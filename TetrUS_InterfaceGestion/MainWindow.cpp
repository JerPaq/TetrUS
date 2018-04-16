#include "mainwindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)    
{
	//setGeometry(30, 30, 600, 700);
	gestion_ = new GestionJoueur();
	if (!gestion_->charger());
	init();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::init()
{
	widgetCentral_ = new CentralWidget(gestion_, this);
	setCentralWidget(widgetCentral_);

	menuFichier_ = new QMenu();
	menuJoueur_ = new QMenu();

	QPalette palette;
	palette.setColor(QPalette::Background, Qt::white);
	widgetCentral_->setAutoFillBackground(true);
	widgetCentral_->setPalette(palette);

	menuFichier_ = menuBar()->addMenu(tr("&Fichier"));
	menuJoueur_ = menuBar()->addMenu(tr("&Joueur"));

	actQuitter_ = new QAction(tr("&Quitter"), this);
	actReglement_ = new QAction(tr("&Regles du jeu"), this);
	actNouveauJoueur_ = new QAction(tr("&Nouveau Joueur"), this);
	actGestionJoueur_ = new QAction(tr("&Gestion Joueur"), this);

	menuFichier_->addAction(actReglement_);
	menuFichier_->addAction(actQuitter_);
	menuJoueur_->addAction(actNouveauJoueur_);
	menuJoueur_->addAction(actGestionJoueur_);

	connect(actQuitter_, SIGNAL(triggered()), this, SLOT(menuQuitter_Clicked()));
	connect(actReglement_, SIGNAL(triggered()), this, SLOT(menuReglements_Clicked()));
	connect(actNouveauJoueur_, SIGNAL(triggered()), this, SLOT(menuNouveauJoueur_Clicked()));
	connect(actGestionJoueur_, SIGNAL(triggered()), this, SLOT(menuGestionJoueur_Clicked()));
}

void MainWindow::menuQuitter_Clicked()
{
	close();
}
void MainWindow::menuNouveauJoueur_Clicked()
{
	dlgNouveauJoueur_ = new NouveauJoueur(gestion_, this);
	dlgNouveauJoueur_->exec();
	if (dlgNouveauJoueur_->isOk())
	{
		widgetCentral_->refreshUI();
	}
}
void MainWindow::menuGestionJoueur_Clicked()
{
	dlgSelectJoueur_ = new SelectJoueur(gestion_, this);
	dlgSelectJoueur_->exec();
	if (dlgSelectJoueur_->isOk())
	{
		widgetCentral_->refreshUI();
	}
}
void MainWindow::menuReglements_Clicked()
{
	dlgReglements_ = new Reglements(this);
	dlgReglements_->exec();
}