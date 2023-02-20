#include "shifrvigenera.h"

#include <QDebug>

shifrVigenera::shifrVigenera()
{
    lanquage_size=RU;
}

shifrVigenera::~shifrVigenera()
{
    for (int i = 0; i < lanquage_size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void shifrVigenera::setlanquage(int lanq)
{
    if(lanq==0)
        lanquage_size=RU;
    else if(lanq==1)
        lanquage_size=EN;
 }

QString shifrVigenera::getChar(int value)
{
    switch (lanquage_size) {
    case RU: return symbolsRu[value];
        break;
    case EN: return symbolsEn[value];
    }
}

QString shifrVigenera::makeShifr(QString str, QString code)
{
  //  delMatrix();
    makeMatrix();
    QString _newstr, _temp_code, _temp_str;
    int _temp_num_col, _temp_num_width, k_code=0, k_str=0;
    do{//цикл do до окончания кодируемой строки
        _temp_str=str[k_str];
        _temp_code=code[k_code];

        if(_temp_str!=" "){
            for (int i = 0; i < lanquage_size; ++i) {//опеределние строки в матрице- начинается с буквы кодового слова
                if(matrix[i]==_temp_code)
                {
                    _temp_num_col=i;
                    break;
                }
            }
            for (int i = 0; i < lanquage_size; ++i) {//определение номера столбца матрицы с буквой кодируемого слова
                if(matrix[0][i]==_temp_str){
                    _temp_num_width=i;
                    break;
                }
            }
            _newstr+=matrix[_temp_num_col][_temp_num_width]; //присвоение кодируемого символа новой строке

            //инкремент индексов кодируемой строки и кодового слова
            k_str++;
            if(k_code<code.size()-1)
                k_code++;
            else
                k_code=0;
        }
        else{//присвоение пробела
            _newstr+=_temp_str;
            k_str++;
        }
    }while(k_str<str.size());

    return _newstr;

}

QString shifrVigenera::makeRasShifr(QString str, QString code)
{
  //  delMatrix();
    makeMatrix();
    QString _newstr, _temp_code, _temp_str;
    int _temp_num_col, _temp_num_width, k_code=0, k_str=0;
    do{//цикл do до окончания кодируемой строки
        _temp_code=code[k_code];
        _temp_str=str[k_str];

        if(_temp_str!=" "){  
            for (int i = 0; i < lanquage_size; ++i) {//опеределние строки в матрице- начинается с буквы кодового слова
                if(matrix[i]==_temp_code)
                {
                    _temp_num_col=i;
                    break;
                }
            }
            for (int i = 0; i < lanquage_size; ++i) {//определение номера столбца матрицы с буквой закодированого слова
                if(matrix[_temp_num_col][i]==_temp_str){
                    _temp_num_width=i;
                    break;
                }
            }
            _newstr+=matrix[0][_temp_num_width];//присвоение кодируемого символа новой строке

            //инкремент индексов кодируемой строки и кодового слова
            k_str++;
            if(k_code<code.size()-1)
                k_code++;
            else
                k_code=0;
        }
        else{//присвоение пробела
            _newstr+=_temp_str;
            k_str++;
        }
    }while(k_str<str.size());

    return _newstr;

}



void shifrVigenera::makeMatrix()
{
    matrix=new QString*[lanquage_size];
    for (int i = 0; i < lanquage_size;i++ ) {
        matrix[i]=new QString[lanquage_size];
    }
    int k=0;
    for(int i=0;i<lanquage_size;i++){
        for(int j=0;j<lanquage_size;j++){
            if(k+j<lanquage_size){
                matrix[i][j]=getChar(k+j);
            }
            else
                matrix[i][j]=getChar(k+j-lanquage_size);
                }
        k++;
    }
}

