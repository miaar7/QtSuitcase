#include "controlthread.h"


ControlThread::ControlThread(BOX* box):box(box)
{



}

ControlThread::~ControlThread(){

}

void ControlThread::process(){


    State state = AT_SP;

    while(1)
    {

        if(mode)
        {

            switch(state)
            {

                case HOT:
                    box->set_fan_speed();
                    box -> reset_lamp1();
                    box -> reset_lamp2();
                    box -> reset_lamp3();

                    //qDebug() << "HOT";

                    if(temp < setpoint.MAX)
                        state = AT_SP;

                break;

            case AT_SP:
                    box->stop_fan();
                    box -> reset_lamp1();
                    box -> reset_lamp2();
                    box -> reset_lamp3();

                    //qDebug() << "AT SP";

                    if(temp > setpoint.MAX)
                        state = HOT;
                    if(temp < setpoint.ONE_LAMP)
                        state = COLD;
                    break;

            case COLD:
                    box -> stop_fan();
                    box -> set_lamp1();
                    box -> reset_lamp2();
                    box -> reset_lamp3();

                    //qDebug() << "COLD";

                    if(temp > setpoint.ONE_LAMP)
                        state = AT_SP;
                    if(temp < setpoint.TWO_LAMP)
                        state = COLDER;
                break;

            case COLDER:
                    box -> stop_fan();
                    box -> set_lamp1();
                    box -> set_lamp2();
                    box -> reset_lamp3();

                    //qDebug() << "COLDER";

                    if(temp > setpoint.TWO_LAMP)
                        state = COLD;
                    if(temp < setpoint.THREE_LAMP)
                        state = COLDEST;
                break;

            case COLDEST:
                    box -> stop_fan();
                    box -> set_lamp1();
                    box -> set_lamp2();
                    box -> set_lamp3();

                    //qDebug() << "COLDEST";

                    if(temp > setpoint.THREE_LAMP)
                        state = COLDER;
                break;
            }

            // qDebug() << "automatic" << temp << " sp - " << AT_SP;




        }
        else
        {
           //qDebug() << "manual";
        }




    sleep(1);
    }

}


void ControlThread::setPoint(float temp)
{
    setpoint.SP  = temp;

    setpoint.ONE_LAMP = setpoint.SP -0.1;
    setpoint.TWO_LAMP = setpoint.ONE_LAMP - 0.2;
    setpoint.THREE_LAMP = setpoint.TWO_LAMP - 0.5;

    setpoint.MAX = setpoint.SP +0.1;
}

void ControlThread::currentTemp(float temp)
{
    this->temp=temp;
}

void ControlThread::setMode(bool mode)
{
    this->mode=mode;
}
