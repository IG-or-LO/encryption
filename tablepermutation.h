#ifndef TABLEPERMUTATION_H
#define TABLEPERMUTATION_H


#include<QString>

class tablePermutation
{
private:
    int rows_matrix;
    int cols_matrix;
    QString **matrix;
    void makeMatrix(QString code,QString str, bool shif_or_rasshif);
    void fillMatrixShifr(QString code,QString str);
    void fillMatrixRasShifr(QString code,QString str);
    QString getStringRemake(QString code);
    int getNumforProbel(QString code, int num);
    int getMatrixRowsCount(QString code,QString str, bool shif_or_rasshif);

public:
    tablePermutation();
    ~tablePermutation();
    QString makeShifr(QString str, QString code);
    QString makeRasShifr(QString str, QString code);

};

#endif // TABLEPERMUTATION_H

