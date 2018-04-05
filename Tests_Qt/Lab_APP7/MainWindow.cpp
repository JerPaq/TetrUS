#include "mainwindow.h"
#include "CentralWidget.h"
#include <QWidget>
#include <QPushButton>
#include <QCoreApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)    
{
	init();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::init()
{
	//setGeometry(10, 10, 500, 500);
	widgetCentral_ = new CentralWidget(this);
	setCentralWidget(widgetCentral_);
	this->setGeometry(200, 200, 200, 200);
}
