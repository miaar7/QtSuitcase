#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "GPIO.h"

using namespace std;

GPIO::GPIO() 
{
	_direction = "out";
	_pin_number = "7";
	exxport.open("/sys/class/gpio/export");
	exxport << this->_pin_number << flush;
	string direction_folder = "/sys/class/gpio/gpio" + this->_pin_number + "/direction";
	direction.open(direction_folder.c_str());
	direction << "out" << flush;
	direction.close();
}

GPIO::GPIO(string pin_num) 
{
	_direction = "out";
	_pin_number = pin_num;
	exxport.open("/sys/class/gpio/export");
	exxport << this->_pin_number << flush;
	string direction_folder = "/sys/class/gpio/gpio" + this->_pin_number + "/direction";
	direction.open(direction_folder.c_str());
	direction << "out" << flush;
	direction.close();
}

GPIO::GPIO(string pin_num, string dir)
{
	_direction = dir;
	_pin_number = pin_num;
	exxport.open("/sys/class/gpio/export");
        exxport << this->_pin_number << flush;
	string direction_folder = "/sys/class/gpio/gpio" + this->_pin_number + "/direction";
	direction.open(direction_folder.c_str());
	direction << "out" << flush;
	direction.close();
}

void GPIO::set(void)
{
	string out_folder = "/sys/class/gpio/gpio" + this->_pin_number + "/value";
	out_value.open(out_folder.c_str());
    out_value << '1' << flush;
	out_value.close();
}

int GPIO::get(void) 
{
	char c;
	string in_folder = "/sys/class/gpio/gpio" + this ->_pin_number + "/value";
	in_value.open(in_folder.c_str());
	in_value >> c;
	in_value.close();
	if (c == '1') return 1; else return 0;
}

void GPIO::reset(void) 
{
	string out_folder = "/sys/class/gpio/gpio" + this->_pin_number + "/value";
	out_value.open(out_folder.c_str());
	out_value << '0' << flush;
	out_value.close();
}

GPIO::~GPIO()
{
  string unexport_folder = "/sys/class/gpio/unexport";
  unexxport.open(unexport_folder.c_str());
  unexxport << this->_pin_number;
  unexxport.close();
}

