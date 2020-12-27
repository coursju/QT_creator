#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtWidgets>
 #include <QWebEngineView>
#include<QPushButton>
#include<QProgressBar>

class FenPrincipale : public QMainWindow
{
    Q_OBJECT
public:
    FenPrincipale();

    void setUrl(const QString &value);
    void nvlPage();

public slots:
    void stringTransfert();
    void nvlOnglet();


private:
    QString url = "http://www.qt.io/";
    QLineEdit *zoneText;
     QTabWidget *onglets ;
     QWebEngineView *view ;
     QWebEngineView *view2;
    QPushButton *plus;
    QMenu *menuFichier;
    QAction *actionQuitter;
    QMenu *menuEdition;
    int k=0;
    QAction *actionnvlOnglet;
    QProgressBar *charge;
};

#endif // FENPRINCIPALE_H
