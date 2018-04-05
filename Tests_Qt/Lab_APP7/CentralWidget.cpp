#include "CentralWidget.h"
#include <QHBoxLayout>

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
	init();
}

CentralWidget::~CentralWidget()
{

}

void CentralWidget::init()
{
	menuBar_ = new QMenuBar();
	menu_ = new QMenu();
	btnBouton1_ = new QPushButton("My Button");
	btnBouton2_ = new QPushButton("My Button2");

	connect(btnBouton1_, SIGNAL(clicked()), this, SLOT(btnBouton1_Clicked()));
	connect(btnBouton2_, SIGNAL(clicked()), this, SLOT(btnBouton2_Clicked()));

	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(btnBouton1_);
	layout->addWidget(btnBouton2_);
	setLayout(layout);
	//principal->setLayout(layout);
}

void CentralWidget::btnBouton1_Clicked()
{
	// change the text
	btnBouton1_->setText("criss de push button");
}

void CentralWidget::btnBouton2_Clicked()
{
	// change the text
	btnBouton2_->setText("criss de push button 2");
}
