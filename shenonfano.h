#ifndef SHENONFANO_H
#define SHENONFANO_H
#include <QString>

class ShenonFano
{
public:
    ShenonFano();
    ~ShenonFano();
    QString getStrOfUniqueChars(QString str);
    double *getProbabilityOfChars(QString str,QString uniqStr);
 private:
    double *prob;
    int *collOfChars;
    QString sortUniqueStr(QString str, QString uniqStr);
    int * getcollOfChars(QString str,QString uniqStr);
};

#endif // SHENONFANO_H
