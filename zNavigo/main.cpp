#include <QtWebEngine>
#include <QApplication>
#include <QtWidgets>
#include "FenPrincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QtWebEngine::initialize();
    FenPrincipale fenetre;
    fenetre.show();

    return app.exec();
}
