#include "shifrtrithemius.h"

#include <QDebug>

shifrTrithemius::shifrTrithemius()
{
    lanquage_size=RU;
}

void shifrTrithemius::setlanquage(int lanq)
{
    if(lanq==0)
        lanquage_size=RU;
    else if(lanq==1)
        lanquage_size=EN;

}

int shifrTrithemius::getCharkey(QChar ch)
{
    switch (lanquage_size) {
    case RU: return mapRu.value(ch);
        break;
    case EN: return mapEn.value(ch);
        break;
    }
}

QString shifrTrithemius::getChar(int value)
{
    switch (lanquage_size) {
    case RU: return mapRu.key(value);
        break;
    case EN: return mapEn.key(value);
        break;
    }

}

QString shifrTrithemius::makeShifrString(QString str, QString code)//l=m+k(mod lanquage_size)
{
     qDebug()<<"строка в методе шифрования-"<<str;
    QString _newStr;
    int key_str, key_code, key_new, index_strCode=0;
    for(int i=0; i<str.size();i++){
        if(str[i]!=' ' && str[i]!='!' && str[i]!='.' && str[i]!=',')
        {
            key_str=getCharkey(str[i]);//код буквы слова
            if(code.size()>index_strCode)//код буквы кода
            {
                key_code=getCharkey(code[index_strCode]);
                index_strCode++;
            }
            else
            {
                index_strCode=0;
                key_code=getCharkey(code[index_strCode]);
                index_strCode++;
            }
            if(key_str+key_code<lanquage_size)//< 33||26
                key_new=key_str+key_code;
            else
                key_new=key_str+key_code-lanquage_size;
            _newStr+=getChar(key_new);

        }
        else
            _newStr+=str[i];
    }

    return _newStr;
}

QString shifrTrithemius::makeRasShifrString(QString str, QString code)//m=l-k(mod 31)
{
    QString _newStr;
    int key_str, key_code, key_new, index_strCode=0;
    for(int i=0; i<str.size();i++){
        if(str[i]!=' ' && str[i]!='!' && str[i]!='.' && str[i]!=',')
        {
            key_str=getCharkey(str[i]);//код буквы слова
            if(code.size()>index_strCode)//код буквы кода
            {
                key_code=getCharkey(code[index_strCode]);
                index_strCode++;
            }
            else
            {
                index_strCode=0;
                key_code=getCharkey(code[index_strCode]);
                index_strCode++;
            }

            if(key_str-key_code>=0)
                key_new=key_str-key_code;
            else
                key_new=key_str-key_code+lanquage_size;
            _newStr+=getChar(key_new);

        }
        else
            _newStr+=str[i];
    }

    return _newStr;
}
