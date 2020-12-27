#include "FenCodeGenere.h"

FenCodeGenere::FenCodeGenere(QString *t ,QDialog *parent) : QDialog (parent), m_leText(*t)
{
    QVBoxLayout *o = new QVBoxLayout(this);
    m_text = new QTextEdit;
    m_bout = new QPushButton("fermer");

    o->addWidget(m_text);
    o->addWidget(m_bout);
    this->setLayout(o);

    m_text->setText(m_leText);

    //***SLOT close de la fenetre***
    connect(m_bout,SIGNAL(clicked()),this,SLOT(close()));
}
