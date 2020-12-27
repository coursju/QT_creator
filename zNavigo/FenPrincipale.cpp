#include "FenPrincipale.h"
#include<QObject>
//#include<QDebug>


FenPrincipale::FenPrincipale()
{
        onglets = new QTabWidget(this);
        charge = new QProgressBar(onglets);
        //QMdiArea *zoneCentrale = new QMdiArea(onglets);
        //view = new QWebEngineView(onglets);
        //view2 = new QWebEngineView(onglets);
        //plus = new QPushButton(onglets);


    menuFichier = menuBar()->addMenu(tr("&Fichier"));
         actionQuitter = new QAction(tr("&Quitter"), this);
         actionnvlOnglet = new QAction(tr("&New page"), this);

              menuFichier->addAction(actionQuitter);

    menuEdition = menuBar()->addMenu(tr("&Edition"));
           QToolBar *toolBarFichier = addToolBar(tr("Fichier"));
           zoneText = new QLineEdit;
           toolBarFichier->addWidget(zoneText);
           toolBarFichier->addAction(actionQuitter);
           toolBarFichier->addAction(actionnvlOnglet);
           toolBarFichier->addWidget(charge);

    //onglets->addTab(view,"test");
    //onglets->addTab(view2,"test2");
    //onglets->addTab(plus,"+");

    //QMdiSubWindow *sousFenetre1 = onglets->addSubWindow(zoneCentrale);
   // view->load(QUrl(url));
    //view->show();
    //->load(QUrl("http://www.groov.fr"));
    //view2->show();

    setCentralWidget(onglets);

   connect(zoneText,SIGNAL(returnPressed()),this,SLOT(stringTransfert()));
          connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
          connect(actionnvlOnglet, SIGNAL(triggered()), this, SLOT(nvlOnglet()));
   nvlOnglet();
}

void FenPrincipale::stringTransfert()
{
url = zoneText->text();
qDebug()<<url;//visualisation dans la console de l url envoyée

//envoi de la nouvelle url (apres casting)
dynamic_cast<QWebEngineView*>(onglets->currentWidget())->load(QUrl(url));
dynamic_cast<QWebEngineView*>(onglets->currentWidget())->show();



}

void FenPrincipale::nvlOnglet()
{
    k++;
    qDebug()<<k;
    onglets->addTab(new QWebEngineView(onglets)  ,tr("nouvelle page")+QString::number(k));
    dynamic_cast<QWebEngineView*>(onglets->currentWidget())->load(QUrl(url));

    dynamic_cast<QWebEngineView*>(onglets->currentWidget())->show();

}

void FenPrincipale::setUrl(const QString &value)
{
    url = value;
}

void FenPrincipale::nvlPage()
{
    onglets->addTab(new QWebEngineView(onglets),tr("nouvelle page"));
    dynamic_cast<QWebEngineView*>(onglets->currentWidget())->load(QUrl(url));
    dynamic_cast<QWebEngineView*>(onglets->currentWidget())->show();

}
