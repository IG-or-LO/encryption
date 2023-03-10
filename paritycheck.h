#ifndef PARITYCHECK_H
#define PARITYCHECK_H

#include <QString>

class ParityCheck
{
private:
       QString doParityCheck(QString str,bool addOrCheck);
public:
    ParityCheck();
    QString getBinaryCode(QString str);
    QString getStrFromBinaryCode(QString str);
};

#endif // PARITYCHECK_H
