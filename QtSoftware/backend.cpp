#include "backend.h"

Backend::Backend()
    {
        //timer = new QTimer(this);
        box = new BOX();
        connect(box, SIGNAL(sigTempChange(float)),this, SLOT(Tmp100Slot(float)));
        //timer -> start(1000);
    }

void Backend::setSetpoint(double d)
{
    qDebug() << "SetSetPoint " << d;
}

void Backend::setFan(float n)
{

    // string speed = to_string(n);
    // box->set_fan_speed("20000000");
   box->set_fan_speed("1500000");
    qDebug() << "SetFan " << n;

}

void Backend::setLamp1(bool b)
{
    if(b) box->set_lamp1(); else box->reset_lamp1();
    qDebug() << "SetLamp1 " << b;

}

void Backend::setLamp2(bool b)
{
    if(b) box->set_lamp2(); else box->reset_lamp2();
    qDebug() << "SetLamp2 " << b;
}

void Backend::setLamp3(bool b)
{
    if(b) box->set_lamp3(); else box->reset_lamp3();
    qDebug() << "SetLamp3 " << b;

}

void Backend::setMode(bool b)
{
    emit currentTemperature(40);
    qDebug() << "SetMode " << b;
}


void Backend::Tmp100Slot(float temp)
{
    qDebug() << "Temp from backend" << temp;
    emit currentTemperature(temp);
}




