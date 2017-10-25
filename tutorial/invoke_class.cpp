#include "invoke_class.h"


invoke_class::invoke_class(QObject *parent) : QObject(parent)
{

}

QString invoke_class::testButtonClick(int i)
{
    qDebug() << "button clicked";

    emit setTextField("signal emitted test");

    if(i==1)
        return "test 1";

    return "test else";
}

