#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include<QBoxLayout>
#include<QDirModel>
#include<QTreeView>
#include<QListView>
#include<QTableView>
#include<QStringListModel>
#include<QStandardItemModel>
#include<QPushButton>
#include<QMessageBox>

class FenPrincipale : public QWidget
{
    Q_OBJECT

    public:
        FenPrincipale();

    private:
        QListView *vue;
        QStringListModel *modele;
        QPushButton *bouton;

    private slots:
        void clicSelection();
};

#endif // FENPRINCIPALE_H
