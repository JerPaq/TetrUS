#pragma once

#include <QWidget>
#include <qpushbutton>
#include <qmenu>
#include <qmenubar>

class CentralWidget : public QWidget
{
	Q_OBJECT

public:
	CentralWidget(QWidget *parent = 0);
	~CentralWidget();

private slots:
	void btnBouton1_Clicked();
	void btnBouton2_Clicked();
//signals:
//	void btn1clicked();
private:
	void init();
	QPushButton *btnBouton1_;
	QPushButton *btnBouton2_;
	QMenuBar *menuBar_;
	QMenu *menu_;

};