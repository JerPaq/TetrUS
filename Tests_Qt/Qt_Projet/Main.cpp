



#include <QApplication>
#include <qpushbutton.h>
#include "MonInterface.h"

int main( int argc, char ** argv )
{
	QApplication app(argc, argv);
 
	MonInterface gui("Test Interface");
	QPushButton button("hey");
	gui.addAction(button);
	gui.show();

	return app.exec();
}
