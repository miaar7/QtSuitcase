#ifndef BOX_H 
#define BOX_H

#include<iostream>
#include<fstream>
#include<unistd.h>
#include<string>
#include "GPIO.h"
#include "PWM.h"
#include "TMP100.h"
using namespace std;

 class BOX {
 public:
  BOX();
  void set_lamp1(void);
  void set_lamp2(void);
  void set_lamp3(void);
  void reset_lamp1(void);
  void reset_lamp2(void);
  void reset_lamp3(void);
  void set_fan_speed(string speed);
  void stop_fan(void);
  void initialize_tmp100(void);
  float get_temp(void);
  
 private:
  GPIO* lamp_1;
  GPIO* lamp_2;
  GPIO* lamp_3;
  PWM* fan;
  TMP100* sensor;
};
#endif //BOX_H
