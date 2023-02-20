#include "stringhelper.h"
#include <QRegExp>

stringHelper::stringHelper()
{

}

QString stringHelper::removeCharFromAllStr(QString str,QChar ch)
{
    str.remove(QRegExp(ch));
    return str;
}

QString stringHelper::changeChar(QString ch, QString rech, QString str)
{
    str.replace(ch,rech);
    return str;
}

