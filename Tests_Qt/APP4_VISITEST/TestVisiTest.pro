TEMPLATE     = vcapp
TARGET       = TestVisiTest
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += leds.h centralwidget.h switches.h VisiTest.h
SOURCES     += 
INCLUDEPATH += ../VisiTest
LIBS	      += ../VisiTest/VisiTest.lib
QT += widgets
