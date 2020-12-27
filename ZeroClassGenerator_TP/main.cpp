#include<QApplication>
#include<QWidget>
#include<FenPrincipale.h>
#include<QTranslator>
#include<QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);

        QTranslator translator;
  //  translator.load(QString("zeroclassgenerator_") + locale);

    /*if(QFile::exists("/home/coursju/Documents/Qt creator/zeroclassgenerator_en"))
        qWarning("failed-no file");
        */
     if( translator.load(QString("zeroclassgenerator_") + locale)){  // translator.load("/home/coursju/Documents/Qt creator/zeroclassgenerator_en")
        app.installTranslator(&translator);

}else {
qWarning("fichier non chargé");
QMessageBox::critical(nullptr,"error","fichier non trouvé");
}

      FenPrincipale fenetre;
      fenetre.show();


    return app.exec();

}
