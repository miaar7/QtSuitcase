#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "GPIO.h"
#include "BOX.h"

using namespace std;

int main(void)
{
  BOX box;
  box.set_lamp1();
  cout << " on \n" << flush;
 // sleep(3);
//  box.reset_lamp1();
//  cout << " off \n" << flush;
//  sleep(3);
  cout << " on \n" << flush;
  box.set_lamp2();
  box.set_lamp3();
//  sleep(3);
//  box.reset_lamp2();
//  cout << " off \n" << flush;
//  sleep(3);
//  box.set_fan();
//  sleep(3);
while(1){};

  return 0;
}













