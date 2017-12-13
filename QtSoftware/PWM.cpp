#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "PWM.h"

using namespace std;

PWM::PWM()
{
	_speed = "0";
    _pin_number = "2";

    SLOT_WRITE.open("/sys/devices/bone_capemgr.8/slots/");
    SLOT_WRITE << "am33xx_pwm" << flush;
	usleep(100);
    SLOT_WRITE << "bone_pwm_P8_19" << flush;
    SLOT_WRITE.close();

    polarity.open("/sys/devices/ocp.2/pwm_test_P8_19.14/polarity");
    polarity << 0 << flush;
	polarity.close();
    period.open("/sys/devices/ocp.2/pwm_test_P8_19.14/period");
    period << 20000000 << flush;
	period.close();
    duty.open("/sys/devices/ocp.2/pwm_test_P8_19.14/duty");
    duty << 0 << flush;
	duty.close();
    run.open("/sys/devices/ocp.2/pwm_test_P8_19.14/run");
    run << 1 << flush;
	run.close();
}

void PWM::set_speed(string speed)
{
    // this->_speed = speed;
    this->duty.open("/sys/devices/ocp.2/pwm_test_P8_19.14/duty");
	this->duty << speed.c_str() << flush;
	this->duty.close();
}

void PWM::stop(void) 
{
	this->_speed = "0";
	this->duty.open((PWM_PATH + "/duty").c_str());
	this->duty << "0" << flush;
	this->duty.close();
}

//string get_speed(void) 
//{
//	return this->_speed;
//}
