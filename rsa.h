#ifndef RSA_H
#define RSA_H
#include<QString>
#include <QMap>

#define RU 34
#define EN 27
#define RUEN 60
class Rsa
{
private:
    int lanquage_size;
    int *arrayKeys;
    //int primesArr[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};//,73,79,83,89,97};

     QMap<QString,int> mapRu{
         {"а",0},{"б",1},{"в",2},{"г",3},{"д",4},
         {"е",5},{"ё",6},{"ж",7},{"з",8},{"и",9},
         {"й",10},{"к",11},{"л",12},{"м",13},{"н",14},
         {"о",15},{"п",16},{"р",17},{"с",18},{"т",19},
         {"у",20},{"ф",21},{"х",22},{"ц",23},{"ч",24},
         {"ш",25},{"щ",26},{"ъ",27},{"ы",28},{"ь",29},
         {"э",30},{"ю",31},{"я",32},{" ",33}
     };
     QMap<QString,int> mapEn{
         {"a",0},{"b",1},{"c",2},{"d",3},{"e",4},{"f",5},
         {"g",6},{"h",7},{"i",8},{"j",9},{"k",10},{"l",11},
         {"m",12},{"n",13},{"o",14},{"p",15},{"q",16},{"r",17},
         {"s",18},{"t",19},{"u",20},{"v",21},{"w",22},{"x",23},{"y",24},{"z",25},{" ",26}
     };
     QMap<QString,int> mapRuEn{
         {"а",0},{"б",1},{"в",2},{"г",3},{"д",4},
         {"е",5},{"ё",6},{"ж",7},{"з",8},{"и",9},
         {"й",10},{"к",11},{"л",12},{"м",13},{"н",14},
         {"о",15},{"п",16},{"р",17},{"с",18},{"т",19},
         {"у",20},{"ф",21},{"х",22},{"ц",23},{"ч",24},
         {"ш",25},{"щ",26},{"ъ",27},{"ы",28},{"ь",29},
         {"э",30},{"ю",31},{"я",32},{" ",33},
         {"a",34},{"b",35},{"c",36},{"d",37},{"e",38},{"f",39},
         {"g",40},{"h",41},{"i",42},{"j",43},{"k",44},{"l",45},
         {"m",46},{"n",47},{"o",48},{"p",49},{"q",50},{"r",51},
         {"s",52},{"t",53},{"u",54},{"v",55},{"w",56},{"x",57},{"y",58},{"z",59},
         {".",60},{",",61},{"!",62},{"?",63},{"(",64},{")",65}
     };

    int getPrime();
    int getRandom(int low,int high,int seed);
    int getProizvedenie(int primeF,int primeS);
    int getEllerFunction(int primeF, int primeS);
    int getFirstCloseKey(int firstOpenKey, int ellerFunction);
    int getCharkey(QChar ch);
    QString getChar(int value);
    long long int getShifrInt(long long int numToShifr,long long int  firstKey,long long int  secondKey);
    unsigned int gcd(unsigned int m, unsigned int n);
    bool isCoprime(unsigned int m, unsigned int n);

public:
    Rsa();
    void setlanquage(int lanq);
    int* genKey();
    QString makeShifr(QString str, int firstKey,int secondKey);
    QString makeRasShifr(QString str, int firstKey,int secondKey);
};

#endif // RSA_H
