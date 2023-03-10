#include "shenonfano.h"

ShenonFano::ShenonFano()
{

}

ShenonFano::~ShenonFano()
{
    delete prob;
    delete collOfChars;
}

QString ShenonFano::getStrOfUniqueChars(QString str)
{
    QString _uniqeStr="";
    for(int i=0;i<str.size();++i)
    {
     if(!_uniqeStr.contains(str[i]))
        _uniqeStr+=str[i];
    }
    return sortUniqueStr(str,_uniqeStr);
}

double *ShenonFano::getProbabilityOfChars(QString str, QString uniqStr)
{
    prob=new double[uniqStr.size()];
    for(int i=0;i<uniqStr.size();i++){
        prob[i]=(double)collOfChars[i] /str.size();
    }
    return prob;
}

QString ShenonFano::sortUniqueStr(QString str, QString uniqStr)
{
    getcollOfChars(str,uniqStr);
    /* Отсортируем массив по убыванию */
        for(int i = 1; i < uniqStr.size(); ++i)
        {
            for(int r = 0; r < uniqStr.size()-i; r++)
            {
                if(collOfChars[r] < collOfChars[r+1])
                {
                    // Обмен местами
                    QChar temp = uniqStr[r];
                    uniqStr[r] = uniqStr[r+1];
                    uniqStr[r+1] = temp;
                    qSwap(collOfChars[r],collOfChars[r+1]);
                }
            }
        }
    return uniqStr;
}

int *ShenonFano::getcollOfChars(QString str, QString uniqStr)
{
    collOfChars=new int[uniqStr.size()];
    int k;
    for(int i=0;i<uniqStr.size();i++)
    {
        k=0;
           for(int j=0;j<str.size();j++)
           {
               if(uniqStr[i]==str[j])
                    k++;
           }
           collOfChars[i]=k;
    }
    return collOfChars;
}
