#include "tablepermutation.h"

#include <QDebug>

tablePermutation::tablePermutation()
{

}

tablePermutation::~tablePermutation()
{
    for (int i = 0; i < rows_matrix; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void tablePermutation::makeMatrix(QString code, QString str, bool shif_or_rasshif)
{
    if(shif_or_rasshif)
        rows_matrix=getMatrixRowsCount(code,str,true);
    else
        rows_matrix=getMatrixRowsCount(code,str,false);
    cols_matrix=code.size();
    matrix=new QString*[rows_matrix];
    for (int i = 0; i < rows_matrix;i++ ) {
        matrix[i]=new QString[cols_matrix];
    }
    if(shif_or_rasshif)
        fillMatrixShifr(code,str);
    else
        fillMatrixRasShifr(code,str);

}
int tablePermutation::getMatrixRowsCount(QString code, QString str, bool shif_or_rasshif)
{
    if(shif_or_rasshif)
    {
        int countOfStrWithProbels=0, probelcount=0, symbolscount=0;
        for (int i = 0; i < code.size(); ++i) {
            symbolscount+=getNumforProbel(code,i);
            if(symbolscount<str.size())
                probelcount++;
            else
                break;
        }
        countOfStrWithProbels=(probelcount+str.size())/code.size();
        if(str.size()+probelcount==countOfStrWithProbels*code.size())
            return countOfStrWithProbels;
        else
            return ++countOfStrWithProbels;
    }
    else
    {
       int rows=str.size()/code.size();
       if(str.size()>rows*code.size())
           return ++rows;
       else
           return rows;
    }
}


void tablePermutation::fillMatrixShifr(QString code, QString str)
{
    int k=0,indexCodeForProb=0, indexWayProbel=0;
    int numForProbel=getNumforProbel(code,indexCodeForProb);
    for(int i=0;i<rows_matrix;i++){
        for(int j=0;j<code.size();j++){
            if(k<str.size() && indexWayProbel!=numForProbel)
            {
                matrix[i][j]=str[k];
                indexWayProbel++;
                k++;
            }
            else if(k<str.size())
            {
                matrix[i][j]=" ";
                indexWayProbel=0;
                indexCodeForProb++;
                numForProbel=getNumforProbel(code,indexCodeForProb);
            }
                }
    }
}

void tablePermutation::fillMatrixRasShifr(QString code, QString str)
{
    bool needToFillSomeEmpty=false;
    int stroki=str.size()/code.size();
    if(stroki*code.size()<str.size())
        needToFillSomeEmpty=true;
    int kollOfDefaultPos=code.size()*(stroki+1)-str.size();

    int index_str=0;
    QString remakeCodeSTR=getStringRemake(code);
    for (int i = 0; i < remakeCodeSTR.size(); ++i) {
        for (int j = 0; j < code.size(); ++j) {
            if(remakeCodeSTR[i]==code[j])
            {
                if(remakeCodeSTR[i]==remakeCodeSTR[i+1])
                    i++;
                for (int k = 0; k < rows_matrix; ++k) {
                    if(needToFillSomeEmpty && k==stroki && j>=code.size()-kollOfDefaultPos)
                        matrix[k][j]="0";
                    else
                    {
                        matrix[k][j]=str[index_str];
                        index_str++;
                    }
                }
            }
        }
    }
}

int tablePermutation::getNumforProbel(QString code,int num)
{
    bool povtor=false;
    for (int i = 0; i < code.size(); ++i) {
        if(code[i]==code[num] && i!=num && num>i)
            povtor=true;
    }
    int k=1;
    for (int i = 0; i < code.size(); ++i) {
        if(code[num]>code[i])
            k++;
    }
    if(povtor)
        return k+1;
    else
        return k;
}

QString tablePermutation::getStringRemake(QString code)
{
    QString tmpStr;
    for(int i=0; i<code.size()-1;i++)
    {
        for(int j=0;j<code.size()-1-i;j++)
        {
            if(code[j]>code[j+1])
            {
                tmpStr=code[j];
                code[j]=code[j+1];
                code[j+1]=tmpStr[0];
            }
        }

    }
    return code;
}

QString tablePermutation::makeShifr(QString str, QString code)
{
    makeMatrix(code,str,true);
    QString shifrStr;
    QString _newCodeStr= getStringRemake(code);
    for(int i=0;i<_newCodeStr.size();i++){
        for (int j = 0; j < code.size(); ++j) {
            if(_newCodeStr[i]==code[j])
            {
                if(_newCodeStr[i]==_newCodeStr[i+1])
                    i++;//увеличиваем индекс на поиск такой же буквы как в предыдущем цикле i
                for (int k = 0; k < rows_matrix; ++k) {
                    shifrStr+=matrix[k][j];
                }
            }
        }
    }
    return shifrStr;
}

QString tablePermutation::makeRasShifr(QString str, QString code)
{
    QString rasShifrStr;
    makeMatrix(code,str,false);
    for (int i = 0; i < rows_matrix; ++i) {
        for (int j = 0; j < code.size(); ++j) {
            rasShifrStr+=matrix[i][j];
        }
    }
    return rasShifrStr;
}
