#ifndef SHIFRTRITHEMIUS_H
#define SHIFRTRITHEMIUS_H
#include <QMap>

#define RU 33
#define RU2 32
#define EN 26
class shifrTrithemius
{
private:
    int lanquage_size;
    QMap<QString,int> mapRu{
        {"а",0},{"б",1},{"в",2},{"г",3},{"д",4},
        {"е",5},{"ё",6},{"ж",7},{"з",8},{"и",9},
        {"й",10},{"к",11},{"л",12},{"м",13},{"н",14},
        {"о",15},{"п",16},{"р",17},{"с",18},{"т",19},
        {"у",20},{"ф",21},{"х",22},{"ц",23},{"ч",24},
        {"ш",25},{"щ",26},{"ъ",27},{"ы",28},{"ь",29},
        {"э",30},{"ю",31},{"я",32}
    };
    QMap<QString,int> mapEn{
        {"a",0},{"b",1},{"c",2},{"d",3},{"e",4},{"f",5},
        {"g",6},{"h",7},{"i",8},{"j",9},{"k",10},{"l",11},
        {"m",12},{"n",13},{"o",14},{"p",15},{"q",16},{"r",17},
        {"s",18},{"t",19},{"u",20},{"v",21},{"w",22},{"x",23},{"y",24},{"z",25}
    };

    int getCharkey(QChar ch);
    QString getChar(int value);
public:
    shifrTrithemius();
    void setlanquage(int lanq);
    QString makeShifrString(QString str,QString code);
    QString makeRasShifrString(QString str, QString code);
};

#endif // SHIFRTRITHEMIUS_H
