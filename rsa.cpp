#include "rsa.h"

#include<QtMath>
#include<QDateTime>
#include<QThread>

#include <QDebug>

Rsa::Rsa()
{
    lanquage_size=RU;
}

void Rsa::setlanquage(int lanq)
{
    if(lanq==0)
        lanquage_size=RU;
    else if(lanq==1)
        lanquage_size=EN;
    else if(lanq==2)
        lanquage_size=RUEN;
}

int Rsa::getPrime()
{
    int _rand1=getRandom(0,39,/*QDateTime::currentMSecsSinceEpoch()*/ QDateTime::currentSecsSinceEpoch());
   // int prime=primesArr[_rand1];//test for myPrimes array
    int prime=qPow(_rand1,2)+_rand1+41; //Leonhard Euler formula of quadratic polynomial(41, 43, 47, 53, 61, 71, ..., 1601)

    return prime;
}

int Rsa::getRandom(int low, int high, int seed)
{
    qsrand(seed); // Setting a base number for counting a random in qrand
    return (qrand() % ((high + 1) - low) + low);
}

int Rsa::getProizvedenie(int primeF, int primeS)
{
    return primeF*primeS;
}

int Rsa::getEllerFunction(int primeF, int primeS)
{
    return (primeF-1)*(primeS-1);
}

int Rsa::getFirstCloseKey(int firstOpenKey, int ellerFunction)
{
    int firstCloseKey=0;
    for (int i=2;i <ellerFunction; ++i) {
      if(  (firstOpenKey*i)%ellerFunction==1)
      {
          firstCloseKey=i;
          break;
      }
    }
    return firstCloseKey;
}

int Rsa::getCharkey(QChar ch)
{
    switch (lanquage_size) {
    case RU: return mapRu.value(ch);
        break;
    case EN: return mapEn.value(ch);
        break;
    case RUEN: return mapRuEn.value(ch);
        break;
    }
}

QString Rsa::getChar(int value)
{
    switch (lanquage_size) {
    case RU: return mapRu.key(value);
        break;
    case EN: return mapEn.key(value);
        break;
    case RUEN: return mapRuEn.key(value);
        break;
    }
}

long long int Rsa::getShifrInt(long long int numToShifr,long long int  firstKey, long long int secondKey)
{
    if(firstKey==0) return 1;
    long long int tmp=getShifrInt(numToShifr,firstKey/2, secondKey);
    if(firstKey%2==0)//если ключ не четный, то должны 1 раз умножить на основание перед тем как разделить степень на два
        return (tmp*tmp)%secondKey;
    else
        return (numToShifr*tmp*tmp)%secondKey;
}

unsigned int Rsa::gcd(unsigned int m, unsigned int n)
{
    return n?gcd(n,m%n):m;  // рекурсивный алгоритм Евклида. Если n>0, вычисляем gcd(n,m%n), иначе возвращаем m
}

bool Rsa::isCoprime(unsigned int m, unsigned int n)
{
    return (gcd(m,n) == 1); // Если НОД(m,n) == 1, то возвращаем true, иначе — false
}

int* Rsa::genKey()
{
    arrayKeys=new int[4];
    //простое число 1
    int primeF=getPrime();
    qDebug()<<"fIRST PRIME:"<<primeF;
    int primeS;
    //простое число 2( не должно ==1 простое)
    do{
    QThread::sleep(1);
    primeS=getPrime();
    qDebug()<<"Second PRIME:"<<primeS;
    }while(primeF==primeS);

    //произведение простых чисел
    int proizvedenie=getProizvedenie(primeF,primeS);
    qDebug()<<"Proizvedenie:"<<proizvedenie;

    //функция элера(второй ключ)
    int ellerFunction=getEllerFunction(primeF,primeS);
    qDebug()<<"ellerfunction:"<<ellerFunction;

    // первый открытый ключ(не должен быть больше числа еллера и взаимно-простой с ним)
    int primeOpenF;
    for (int i=50;i<ellerFunction ;i++) {
        primeOpenF=i;
    if(isCoprime(primeOpenF,ellerFunction))
        break;
    }

    int firstCLoseKey=getFirstCloseKey(primeOpenF,ellerFunction);
    qDebug()<<"PrimeOpenF:"<<primeOpenF;
    arrayKeys[0]=primeOpenF; arrayKeys[1] =proizvedenie;
    arrayKeys[2]=firstCLoseKey; arrayKeys[3]=proizvedenie;


    return arrayKeys;

}

QString Rsa::makeShifr(QString str, int firstKey, int secondKey)
{   QString resStr="";
    for (int i = 0; i < str.size(); ++i) {
     resStr+=QString::number( getShifrInt(getCharkey(str[i]),firstKey,secondKey) ) +" ";
    }
    qDebug()<<"Зашифрованная строка: "<<resStr;
    return resStr;
}

QString Rsa::makeRasShifr(QString str, int firstKey, int secondKey)
{
    str+=" ";//добавляем пробел для последней операции в цикле
    QString resStr="";
    QString tmpStr;
   // int numToRasShifr;
    for (int i = 0; i < str.size(); ++i) {
        if(str[i]!=" "){
            tmpStr+=str[i];
        }
        else
        {
            resStr+=getChar( getShifrInt(tmpStr.toInt(),firstKey,secondKey));
            tmpStr="";
        }
    }
    return resStr;
}
