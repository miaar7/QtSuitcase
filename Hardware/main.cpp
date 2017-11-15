#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "GPIO.h"
#include "PWM.h"
#include "BOX.h"

using namespace std;

int main(void)
{
  BOX box;
  box.initialize_tmp100();
  box.set_lamp1();
  cout << " lamp 1 is on \n" << flush;
  sleep(10);
//  box.reset_lamp1();
//  cout << " off \n" << flush;
//  sleep(3);
  cout << "lamp 2 is on \n" << flush;
  box.set_lamp2();
  sleep(10);
  cout << "lamp3 is on \n" << flush;
  box.set_lamp3();
  sleep(1);
//  sleep(3);
//  box.reset_lamp2();
//  cout << " off \n" << flush;
//  sleep(3);
//  box.set_fan();
//  sleep(3);
while(1)
  {
    cout <<"temperature is" << box.get_temp() << " celcius degrees" << endl;
    sleep(1);

  };

  return 0;
}













