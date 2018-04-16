TEMPLATE     = vcapp
TARGET       = TetrUS
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += MainWindow.h CentralWidget.h NouveauJoueur.h SelectJoueur.h ModifierJoueur.h joueur.h vecteur.h gestionjoueur.h Reglements.h Carre.h Forme.h L.h LGauche.h Ligne.h Pyramide.h S.h Z.h CommunicationFPGA.h carte_FPGA.h
SOURCES     += MainWindow.cpp main.cpp CentralWidget.cpp NouveauJoueur.cpp SelectJoueur.cpp ModifierJoueur.cpp joueur.cpp gestionjoueur.cpp Reglements.cpp Carre.cpp Forme.cpp L.cpp LGauche.cpp Ligne.cpp Pyramide.cpp S.cpp Z.cpp carte_FPGA.cpp
INCLUDEPATH += .\nlohmann
LIBS	      += CommunicationFPGA.lib
QT += widgets
