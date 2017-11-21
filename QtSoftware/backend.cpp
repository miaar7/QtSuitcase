#include "backend.h"
#include "BOX.h"

BOX box;

Backend::Backend()
    {



    }




void Backend::setSetpoint(double d)
{
    qDebug() << "SetSetPoint " << d;
}

void Backend::setFan(float n)
{
    qDebug() << "SetFan " << n;
}

void Backend::setLamp1(bool b)
{
    qDebug() << "SetLamp1 " << b;
}

void Backend::setLamp2(bool b)
{
    qDebug() << "SetLamp2 " << b;
}

void Backend::setLamp3(bool b)
{
    qDebug() << "SetLamp3 " << b;
}

void Backend::setMode(bool b)
{
    emit currentTemperature(40);
    qDebug() << "SetMode " << b;
}




