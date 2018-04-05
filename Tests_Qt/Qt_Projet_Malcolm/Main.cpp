


#include <QProgressBar>
#include <QSlider>
#include <QApplication>
#include <qpushbutton.h>
#include "MonInterface.h"



int main( int argc, char ** argv )
{
	QApplication app(argc, argv);
	
	QPushButton button1("test");
	QPushButton button2("other", &button1);

	button1.show();

	/*
	QWidget window;
	window.setFixedSize(200, 80);

	QProgressBar *progressBar = new QProgressBar(&window);
	progressBar->setRange(0, 100);
	progressBar->setValue(0);
	progressBar->setGeometry(10, 10, 180, 30);

	QSlider *slider = new QSlider(&window);
	slider->setOrientation(Qt::Horizontal);
	slider->setRange(0, 100);
	slider->setValue(0);
	slider->setGeometry(10, 40, 180, 30);


	window.show();

	QObject::connect(slider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
	*/

	return app.exec();
}
