#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    QVBoxLayout *layout = new QVBoxLayout;

    QStringList listePays;
    listePays << "France" << "Espagne" << "Italie" << "Portugal" << "Suisse";

    //QDirModel *modele = new QDirModel;
    modele = new QStringListModel(listePays);
    //QStandardItemModel *modele = new QStandardItemModel(5, 3);



    //modele->setItem(3, 1, new QStandardItem("Zéro !"));
    //QStandardItem *item = new QStandardItem("John Deuf");
       //modele->appendRow(item);
      // item->appendRow(new QStandardItem("17 ans"));

    bouton = new QPushButton("Afficher la sélection");

    //QTreeView *vue = new QTreeView;
    vue = new QListView;
    //QTableView *vue = new QTableView;

    //vue->setRootIndex(modele->index("./"));
    vue->setSelectionMode(QAbstractItemView::ExtendedSelection);

    vue->setModel(modele);
    layout->addWidget(vue);
    layout->addWidget(bouton);

    setLayout(layout);
        connect(bouton, SIGNAL(clicked()), this, SLOT(clicSelection()));
}

/*void FenPrincipale::clicSelection() //selection pour un
{
    QItemSelectionModel *selection = vue->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = modele->data(indexElementSelectionne, Qt::DisplayRole);
    QMessageBox::information(this, "Elément sélectionné", elementSelectionne.toString());
}*/
void FenPrincipale::clicSelection() //selection pour plusieurs
{
    QItemSelectionModel *selection = vue->selectionModel();
    QModelIndexList listeSelections = selection->selectedIndexes();
    QString elementsSelectionnes;

    for (int i = 0 ; i < listeSelections.size() ; i++)
    {
        QVariant elementSelectionne = modele->data(listeSelections[i], Qt::DisplayRole);
        elementsSelectionnes += elementSelectionne.toString() + "<br />";
    }

    QMessageBox::information(this, "Eléments sélectionnés", elementsSelectionnes);
}
