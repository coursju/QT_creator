#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QDialog>
#include<QTextEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QGroupBox>


class FenCodeGenere : public QDialog
{
    Q_OBJECT
public:
    FenCodeGenere(QString *t = nullptr ,QDialog *parent = nullptr);

private:
    QTextEdit *m_text;
    QPushButton *m_bout;
    QString m_leText;

};

#endif // FENCODEGENERE_H
