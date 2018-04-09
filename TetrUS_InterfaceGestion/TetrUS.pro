TEMPLATE     = vcapp
TARGET       = TetrUS
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += MainWindow.h CentralWidget.h NouveauJoueur.h SelectJoueur.h ModifierJoueur.h joueur.h vecteur.h gestionjoueur.h
SOURCES     += MainWindow.cpp main.cpp CentralWidget.cpp NouveauJoueur.cpp SelectJoueur.cpp ModifierJoueur.cpp joueur.cpp gestionjoueur.cpp
INCLUDEPATH += .\nlohmann
LIBS	      += 
QT += widgets
