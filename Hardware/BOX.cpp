#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "GPIO.h"
#include "PWM.h"
#include "BOX.h"
#include "TMP100.h"

using namespace std;

 BOX::BOX() {
  lamp_1 = new GPIO("7");
  lamp_2 = new GPIO("14");
  lamp_3 = new GPIO("15");
  fan = new PWM();
  sensor = new TMP100();
  
  //Initialize the box
  lamp_1->reset();
  lamp_2->reset();
  lamp_3->reset();
  fan->stop();
//  rasp->reset();
}
void BOX::set_lamp1(void) {
 this->lamp_1->set();
}
void BOX::set_lamp2(void) {
  this->lamp_2->set();
}
void BOX::set_lamp3(void) {
  this->lamp_3->set();
}
void BOX::reset_lamp1(void) {
  this->lamp_1->reset();
}
void BOX::reset_lamp2(void) {
  this->lamp_2->reset();
}
void BOX::reset_lamp3(void) {
  this->lamp_3->reset();
}
void BOX::set_fan_speed(string speed)
{
  this->fan->set_speed(speed);
}

void BOX::stop_fan(void)
{
  this->fan->stop();
}

float BOX::get_temp(void)
{
  this->sensor->read_temp();
}

void BOX::initialize_tmp100(void)
{
  this->sensor->initialize();
}
