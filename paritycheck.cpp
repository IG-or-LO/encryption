#include "paritycheck.h"

#include<QDebug>

ParityCheck::ParityCheck()
{

}

QString ParityCheck::getBinaryCode(QString str)
{
    QString rez;
    for(QChar ch:qAsConst(str))
    {
        rez+=doParityCheck(QString("%1").arg(*reinterpret_cast<uint16_t*>(&ch),16, 2,QChar{'0'}), true);
    }
    return rez;
}

QString ParityCheck::doParityCheck(QString str,bool addOrCheck)
{
    bool parity=true;
    for (int i = 0,k=1; i < str.size(); ++i,++k)
    {
        if(str[i]=="1")
            parity=!parity;
        if(k%8==0)//если бит четности
        {
            if(addOrCheck)//если вставка бита четности
            {
                str.insert(i+1,QString::number(parity));
                parity=true;
                i++;
            }
            else//если проверка бита четности
            {
                if(str[i+1]==QString::number(parity))//проверка успешна
                {
                    parity=true;
                    i++;
                    k=0;
                }
                else//бит не правильный
                {
                    return "Ошибка бита четности!";
                }
            }
        }
    }
    return addOrCheck?str:"Биты четности верные";
}

QString ParityCheck::getStrFromBinaryCode(QString str)
{
    return doParityCheck(str,false);
}
