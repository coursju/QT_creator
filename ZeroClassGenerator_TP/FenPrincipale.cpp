#include "FenPrincipale.h"

FenPrincipale::FenPrincipale(QWidget *parent) : QWidget(parent)
{
 vbox = new QVBoxLayout(this);


 groupBox1 = new QGroupBox(tr("Definition de la class"));
 groupBox2 = new QGroupBox(tr("Options"));
 groupBox3 = new QGroupBox(tr("Ajouter des commentaires"));
  groupBox3->setCheckable(true);
  groupBox3->setChecked(false);

  groupBox4 = new QGroupBox;
  ok = new QHBoxLayout(groupBox4);


a =new QFormLayout(groupBox1);
b =new QFormLayout(groupBox2);
c =new QFormLayout(groupBox3);


nom = new QLineEdit;
classe = new QLineEdit;

radio1 = new QCheckBox(tr("Proteger le header contre les inclusions multiples"));
radio2 = new QCheckBox(tr("Generer un constructeur par defaut"));
radio3 = new QCheckBox(tr("Generer un destructeur"));

auteur = new QLineEdit(groupBox4);
date = new QDateEdit(groupBox4);
text = new QTextEdit(groupBox4);



a->addRow("nom: ",nom);
a->addRow("Classe mere: ",classe);
groupBox1->setLayout(a);

b->addRow(radio1);
b->addRow(radio2);
b->addRow(radio3);
groupBox2->setLayout(b);

c->addRow("auteur: ",auteur);
c->addRow("date de creation: ",date);
c->addRow("role de la classe: ",text);
groupBox3->setLayout(c);


generer = new QPushButton("generer!",groupBox4);
quitter = new QPushButton("quitter",groupBox4);
ok->addWidget(quitter);
ok->addWidget(generer);

groupBox4->setLayout(ok);

 vbox->addWidget(groupBox1);
 vbox->addWidget(groupBox2);
 vbox->addWidget(groupBox3);
 vbox->addWidget(groupBox4);


this->setLayout(vbox);


connect(quitter,SIGNAL(clicked()),qApp,SLOT(quit()));
connect(generer,SIGNAL(clicked()),this,SLOT(genererCode()));




}
//***concatenation du texte
void FenPrincipale::constructionText()
{//proprietes:
    QString comment="", clas="", heritage="", construct="", destruct="";

    //si commentaires est coché
    if(groupBox3->isChecked()){
        comment= "/*\nAuteur:  "+auteur->text()+"\nDate de creation:  "+date->text()+"\n\nRole:  "+text->toPlainText()+"\n\n*/";
        m_leCode += comment;
    }
    //si destructeur est coché
    if(radio3->isChecked()){
        destruct=" \t~"+nom->text()+"();\n";
    }
    //si constructeur est coché
    if(radio2->isChecked()){
        construct=" \t"+nom->text()+"();\n";
    }
    //si heritage est coché
    if(classe->text()!=""){
        heritage="  :  public "+classe->text();
    }
    //ajout du code central
    clas= "class "+nom->text()+heritage+"\n{\n\tpublic:\n"+construct+destruct+"\n\tprotected:\n\n\tprivate:\n\n};";

    //si protection du header est coché
    if(radio1->isChecked()){
        clas= "\n#ifndef HEADER_"+nom->text()+"\n#define HEADER_"+nom->text()+"\n\n"+clas+"\n\n#endif";
    }
    //concatenation du text final
    m_leCode += clas;

}
//***appelle de la fenetre QDialog
void FenPrincipale::genererCode()
{
    m_leCode="";//efface la chaine
    //test si nom est vide
    if(nom->text()!=""){
    constructionText();
    m_FenCodeGenere = new FenCodeGenere(&m_leCode);
    m_FenCodeGenere->exec();
    }else{
        QMessageBox::critical(this,"erreur","il faut au minimum que le nom de la class soit renseigné");
        return;
    }
}
