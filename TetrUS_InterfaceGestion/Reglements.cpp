#include "Reglements.h"
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QPixmap>

Reglements::Reglements(QWidget *parent) :QDialog(parent)
{
	init();
}

Reglements::~Reglements()
{

}

void Reglements::init()
{
	QFont fontTitle("Courier", 16, QFont::Bold, true);
	QFont fontSub("Courier", 12, QFont::Bold, true);

	setStyleSheet("background-color: white");

	setWindowTitle("Regles du jeu");
	btnOk_ = new QPushButton("Ok");
	btnOk_->setMaximumWidth(100);
	lblTitre_ = new QLabel("Comment jouer");
	lblTitre_->setAlignment(Qt::AlignCenter);
	lblTitre_->setFont(fontTitle);
	clavier_ = new QLabel("Utilisation du clavier pour jouer: ");
	clavier_->setFont(fontSub);
	lblPhotoClavier_ = new QLabel();
	QPixmap mypix("./photos/clavier.png");
	lblPhotoClavier_->setPixmap(mypix);
	lblPhotoClavier_->setAlignment(Qt::AlignCenter);
	phonemes_ = new QLabel("Utilisation des phonemes: ");
	phonemes_->setFont(fontSub);
	lblPhotoPhoneme_ = new QLabel();
	QPixmap pixPhoneme("./photos/phonemes.png");
	lblPhotoPhoneme_->setPixmap(pixPhoneme);
	lblPhotoPhoneme_->setAlignment(Qt::AlignCenter);

	connect(btnOk_, SIGNAL(clicked()), this, SLOT(btnOk_Clicked()));

	QVBoxLayout *ReglementsLayout_ = new QVBoxLayout();
	ReglementsLayout_->addWidget(lblTitre_);
	ReglementsLayout_->addWidget(clavier_);
	ReglementsLayout_->addWidget(lblPhotoClavier_);
	ReglementsLayout_->addWidget(phonemes_);
	ReglementsLayout_->addWidget(lblPhotoPhoneme_);
	ReglementsLayout_->addWidget(btnOk_);

	ReglementsLayout_->setSpacing(30);
	setLayout(ReglementsLayout_);
}

void Reglements::btnOk_Clicked()
{
	close();
}
