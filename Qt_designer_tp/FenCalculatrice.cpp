#include "FenCalculatrice.h"
#include "ui_FenCalculatrice.h"


FenCalculatrice::FenCalculatrice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenCalculatrice)
{
    ui->setupUi(this);

        connect(ui->boutonEgal, SIGNAL(clicked()), this, SLOT(calculerOperation()));
}

FenCalculatrice::~FenCalculatrice()
{
    delete ui;
}

void FenCalculatrice::calculerOperation(){


    QString x= ui->nombre1->text()+ ui->operation->itemText(ui->operation->currentIndex())+ui->nombre2->text();
    x2 = myEngine.evaluate(x);
    qDebug() << x2.toNumber(); //sortie console
    QString res = x2.toString(); // sortie label"resultat"

    ui->resultat->setText(res);


}
