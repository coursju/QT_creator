#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QRadioButton>
#include<QCheckBox>
#include<QDateEdit>
#include<QTextEdit>
#include<QPushButton>
#include<QApplication>
#include<QLineEdit>
#include<QFormLayout>
#include<FenCodeGenere.h>
#include<QMessageBox>

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
    explicit FenPrincipale(QWidget *parent = nullptr);
    void constructionText();

signals:

public slots:
    void genererCode();

private:
    FenCodeGenere *m_FenCodeGenere;
    QString m_leCode;
    QVBoxLayout *vbox;
    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QGroupBox *groupBox3;
    QGroupBox *groupBox4;
    QHBoxLayout *ok;
    QFormLayout *a;
    QFormLayout *b;
    QFormLayout *c;
    QLineEdit *nom ;
    QLineEdit *classe ;

    QCheckBox *radio1 ;
    QCheckBox *radio2 ;
    QCheckBox *radio3 ;

    QLineEdit *auteur ;
    QDateEdit *date ;
    QTextEdit *text ;
    QPushButton *generer ;
    QPushButton *quitter ;

};

#endif // FENPRINCIPALE_H
