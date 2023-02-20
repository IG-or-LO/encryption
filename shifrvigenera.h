#ifndef SHIFRVIGENERA_H
#define SHIFRVIGENERA_H

#include<QString>

#define RU 33
#define EN 26
class shifrVigenera
{
private:
    int lanquage_size;
    QString **matrix;

    QString symbolsRu[33]{
        "а","б","в","г","д","е","ё","ж","з","и","й","к","л","м","н","о","п","р","с","т","у","ф","х","ц","ч","ш","щ","ъ","ы","ь","э","ю","я"
    };
    QString symbolsEn[26]{
        "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
    };

    int getCharkey(QChar ch);
    QString getChar(int value);
    void makeMatrix();
public:
    shifrVigenera();
    ~shifrVigenera();
    void setlanquage(int lanq);
    QString makeShifr(QString str, QString code);
    QString makeRasShifr(QString str, QString code);


};

#endif // SHIFRVIGENERA_H
