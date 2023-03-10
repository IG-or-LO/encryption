#ifndef TIN_H
#define TIN_H
#include <QString>

class TIN
{

private:
    int *numbers;
    int sizeOfNumbers;
    QString digitStr;
    void makeNumbersFromStr( QString &numbersStr);
    void StrFromNumbers(QString &numbersStr);
    void makeNumbersRandom();
    void makeDigit();
    int getRandom(int low, int high, int seed);
    void setSizeOfNumbers(int size);

public:
    TIN();
    QString getFullTin(QString numbersStr="",bool individualOrEntity=true);
};

#endif // TIN_H
