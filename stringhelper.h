#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include <QString>
class stringHelper
{
public:
    stringHelper();
    QString removeCharFromAllStr(QString str, QChar ch);
    QString changeChar(QString ch,QString rech, QString str);

};

#endif // STRINGHELPER_H
