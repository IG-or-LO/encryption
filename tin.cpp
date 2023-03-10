#include "tin.h"
#include<QDebug>
#include<QDateTime>
#include<QThread>

TIN::TIN()
{

}

void TIN::setSizeOfNumbers(int size)
{
    sizeOfNumbers=size;
}

void TIN::makeNumbersFromStr( QString &numbersStr)
{
    numbers=new int[sizeOfNumbers];
    for(int i=0;i<sizeOfNumbers;i++)
    {
        numbers[i]=QString( numbersStr[i] ).toInt();
    }
}

void TIN::StrFromNumbers(QString &numbersStr)
{
    for(int i=0;i<sizeOfNumbers;i++)
    {
        numbersStr+=QString::number(numbers[i]);
    }
}


void TIN::makeDigit()
{
    if(sizeOfNumbers==9)
    {
        int n10=((2*numbers[0] + 4*numbers[1]+ 10*numbers[2] + 3*numbers[3] + 5*numbers[4]
                + 9*numbers[5] + 4*numbers[6] + 6*numbers[7] + 8*numbers[8]) % 11) % 10;
        digitStr=QString::number(n10);
    }
    else if(sizeOfNumbers==10)
    {
        int n11 = ((7*numbers[0] + 2*numbers[1] + 4*numbers[2] + 10*numbers[3] + 3*numbers[4] + 5*numbers[5]
                + 9*numbers[6] + 4*numbers[7] + 6*numbers[8] + 8*numbers[9]) % 11) % 10;
        int n12 = ((3*numbers[0] + 7*numbers[1] + 2*numbers[2] + 4*numbers[3] + 10*numbers[4] + 3*numbers[5]
                + 5*numbers[6] + 9*numbers[7] + 4*numbers[8] + 6*numbers[9] + 8*n11) % 11) % 10;
        digitStr=QString::number(n11)+QString::number(n12);
    }
}

int TIN::getRandom(int low, int high, int seed)
{
    qsrand(seed); // Setting a base number for counting a random in qrand
    return (qrand() % ((high + 1) - low) + low);
}


void TIN::makeNumbersRandom()
{
    numbers=new int[sizeOfNumbers];
    for(int i=0;i<sizeOfNumbers;i++)
    {
        numbers[i]=getRandom(0, 9,QDateTime::currentMSecsSinceEpoch()); //QDateTime::currentSecsSinceEpoch());
        QThread::msleep(23);
    }
}


QString TIN::getFullTin(QString numbersStr,bool individualOrEntity)
{
    if(numbersStr=="")
    {
        individualOrEntity?setSizeOfNumbers(10):setSizeOfNumbers(9);
        makeNumbersRandom();
        StrFromNumbers(numbersStr);
        makeDigit();
    }
    else
    {
        setSizeOfNumbers(numbersStr.size());
        makeNumbersFromStr(numbersStr);
        makeDigit();

    }
    return numbersStr+digitStr;
}
