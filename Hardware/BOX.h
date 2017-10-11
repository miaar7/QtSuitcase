#ifndef BOX_H 
#define BOX_H
# include <iostream>
# include <fstream>
# include <unistd.h>
# include <string>
# include "GPIO.h"

using namespace std;

 class BOX {
 public:
  BOX();
  void set_lamp1(void);
  void set_lamp2(void);
  void set_lamp3(void);
  void set_fan(void);
  void set_rasp(void);
  void reset_lamp1(void);
  void reset_lamp2(void);
  void reset_lamp3(void);
  void reset_fan(void);
  void reset_rasp(void);
  
 private:
  GPIO* lamp_1;
  GPIO* lamp_2;
  GPIO* lamp_3;
  GPIO* fan;
//  GPIO* rasp; // For home testing on RPi
};
#endif //BOX_H
