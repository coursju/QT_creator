#ifndef FENCALCULATRICE_H
#define FENCALCULATRICE_H

#include <QWidget>
#include<QtScript/QScriptValue>
#include<QtScript/QScriptEngine>
#include<QDebug>

namespace Ui {
class FenCalculatrice;
}

class FenCalculatrice : public QWidget
{
    Q_OBJECT

public:
    explicit FenCalculatrice(QWidget *parent = nullptr);
    ~FenCalculatrice();

public slots:
    void calculerOperation();

private:
    Ui::FenCalculatrice *ui;
   QScriptEngine myEngine;
   QScriptValue x2 ;



};

#endif // FENCALCULATRICE_H
