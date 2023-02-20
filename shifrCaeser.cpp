#include "shifrCaeser.h"
#include <QDebug>

ShifrCaeser::ShifrCaeser()
{
    lanquage=RU;
}

void ShifrCaeser::setlanquage(int lanq)
{
    if(lanq==0)
        lanquage=RU;
    else if(lanq==1)
        lanquage=EN;
}

int ShifrCaeser::getCharkey(QChar ch)
{
    switch (lanquage) {
    case RU: return mapRu.value(ch);
        break;
    case EN: return mapEn.value(ch);
    }

}

QString ShifrCaeser::getChar(int value)
{
    switch (lanquage) {
    case RU: return mapRu.key(value);
        break;
    case EN: return mapEn.key(value);
    }
}

QString ShifrCaeser::makeShifrString(QString str, int smeshenie)
{
    QString _newStr;
    int sm;
    for(int i=0; i<str.size();i++){
        if(str[i]!=' ' && str[i]!='!' && str[i]!='.' && str[i]!=',')
        {
            sm=getCharkey(str[i]);
            if(sm+smeshenie<lanquage)
                _newStr+= getChar(sm+smeshenie);
            else
                _newStr+= getChar(sm+smeshenie-lanquage);
        }
        else
            _newStr+=str[i];
    }

    return _newStr;
}

QString ShifrCaeser::makeRasShifrString(QString str, int smeshenie)
{
    QString _newStr;
    int sm;
    for(int i=0; i<str.size();i++){
        if(str[i]!=' ' && str[i]!='!' && str[i]!='.' && str[i]!=',')
        {
            sm=getCharkey(str[i]);
            if(sm-smeshenie>=0)
                _newStr+= getChar(sm-smeshenie);
            else
                _newStr+= getChar(sm-smeshenie+lanquage);
        }
        else
            _newStr+=str[i];
    }

    return _newStr;
}
