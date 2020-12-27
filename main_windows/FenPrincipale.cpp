#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    QMdiArea *zoneCentrale = new QMdiArea;

       QTextEdit *zoneTexte1 = new QTextEdit;
       QTextEdit *zoneTexte2 = new QTextEdit;

       QMdiSubWindow *sousFenetre1 = zoneCentrale->addSubWindow(zoneTexte1);
       QMdiSubWindow *sousFenetre2 = zoneCentrale->addSubWindow(zoneTexte2);

       QMenu *menuFichier = menuBar()->addMenu("&Fichier");

       QAction *actionQuitter = new QAction("&Quitter", this);
           menuFichier->addAction(actionQuitter);

           QMenu *fichiersRecents = menuFichier->addMenu("Fichiers &récents");
           fichiersRecents->addAction("Fichier bidon 1.txt");
           fichiersRecents->addAction("Fichier bidon 2.txt");
           fichiersRecents->addAction("Fichier bidon 3.txt");

       QMenu *menuEdition = menuBar()->addMenu("&Edition");

       QAction *actionGras = new QAction("&Gras", this);
           menuEdition->addAction(actionGras);

       QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

       setCentralWidget(zoneCentrale);

       connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
       actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
       actionQuitter->setIcon(QIcon("/home/coursju/Documents/Qt creator/main_windows/quitter.png"));

       actionGras->setShortcut(QKeySequence("Ctrl+G"));
       actionGras->setCheckable(true);

       QToolBar *toolBarFichier = addToolBar("Fichier");
            toolBarFichier->addAction(actionQuitter);

            QFontComboBox *choixPolice = new QFontComboBox;
            toolBarFichier->addWidget(choixPolice);
            toolBarFichier->addSeparator();


}
