#include<QApplication>
#include<QWidget>
#include"dialog.h"
#include<QDialog>
#include<FenCalculatrice.h>


int main(int argc, char *argv[]){
    QApplication app (argc,argv);

    FenCalculatrice test;
    test.show();

    return app.exec();


}
