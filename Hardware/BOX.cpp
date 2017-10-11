# include <iostream>
# include <fstream>
# include <unistd.h>
# include <string>
# include "GPIO.h"
# include "BOX.h"
using namespace std;

 BOX::BOX() {
  lamp_1 = new GPIO("7");
  lamp_2 = new GPIO("14");
  lamp_3 = new GPIO("15");
  fan = new GPIO("2");
//  rasp = new GPIO("4");
  //Initialize the box
  lamp_1->reset();
  lamp_2->reset();
  lamp_3->reset();
  fan->reset();
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
void BOX::set_fan(void) {
  this->fan->set();
}
//void BOX::set_rasp(void) {
//  this->rasp->set();
//}
void BOX::reset_lamp1(void) {
  this->lamp_1->reset();
}
void BOX::reset_lamp2(void) {
  this->lamp_2->reset();
}
void BOX::reset_lamp3(void) {
  this->lamp_3->reset();
}
void BOX::reset_fan(void) {
  this->fan->reset();
}
//void BOX::reset_rasp(void) {
//  this->rasp->reset();
//}
