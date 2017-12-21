#include "backend.h"

Backend::Backend()
    {

        box = new BOX();
        connect(box, SIGNAL(sigTempChange(float)),this, SLOT(Tmp100Slot(float)));

        thread  = new QThread();
        controlThread = new ControlThread(box);
        controlThread->moveToThread(thread);

        connect(thread,SIGNAL(started()),controlThread,SLOT(process()));
        connect(controlThread,SIGNAL(finished()),thread,SLOT(quit()));
        connect(controlThread,SIGNAL(finished()),controlThread,SLOT(deleteLater()));
        connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));

        thread->start();

    }

void Backend::setSetpoint(double d)
{
    controlThread->setPoint((float) d);
   // qDebug() << "SetSetPoint " << d;
}

void Backend::setFan(float n)
{

    if(n > 0.5)
    {
        box->set_fan_speed();
    }
    else
    {
       box->stop_fan();
    }

   // qDebug() << "SetFan " << n;

}

void Backend::setLamp1(bool b)
{
    if(b) box->set_lamp1(); else box->reset_lamp1();
    //qDebug() << "SetLamp1 " << b;

}

void Backend::setLamp2(bool b)
{
    if(b) box->set_lamp2(); else box->reset_lamp2();
    //qDebug() << "SetLamp2 " << b;
}

void Backend::setLamp3(bool b)
{
    if(b) box->set_lamp3(); else box->reset_lamp3();
    //qDebug() << "SetLamp3 " << b;

}

void Backend::setMode(bool b)
{

    controlThread->setMode(b);
    QString state = box->get_gpioState();
    emit gpioState(state);
    //qDebug() << "SetMode " << b;
}


void Backend::Tmp100Slot(float temp)
{
    // qDebug() << "Temp from backend" << temp;
    emit currentTemperature(temp);
    controlThread->currentTemp(temp);

    //Update GPIO state to the GUI
    QString state = box->get_gpioState();
    emit gpioState(state);
}




