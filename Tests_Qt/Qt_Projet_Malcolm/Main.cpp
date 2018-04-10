


#include <QProgressBar>
#include <QSlider>
#include <QApplication>
#include <qgraphicsscene.h>
#include <qpushbutton.h>
#include "MonInterface.h"



int main( int argc, char ** argv )
{
	QApplication ui(argc, argv);
	

	QGraphicsScene* scene = new QGraphicsScene;
	ui->view->setScene(scene);

	// Add the vertical lines first, paint them red
	for (int x = 0; x <= 500; x += 50)
		scene->addLine(x, 0, x, 500, QPen(Qt::red));

	// Now add the horizontal lines, paint them green
	for (int y = 0; y <= 500; y += 50)
		scene->addLine(0, y, 500, y, QPen(Qt::green));

	// Fit the view in the scene's bounding rect
	ui->view->fitInView(scene->itemsVBoundingRect());

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
