#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "TMP100.h"
#include <iostream>

using namespace std;

TMP100::TMP100()
{
  //char buffer[] = ; 
  //  this->bus = &buffer[0];
     this->ctemp = 0.0;
}

void TMP100::initialize(void)
{
  if ((this->file = open("/dev/i2c-1", O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
        }

}

float TMP100::read_temp(void)
{
  ioctl(this->file, I2C_SLAVE, 0x48);

  char config[2] = {0};
  config[0] = 0x01;
  config[1] = 0x60;
  write(this->file, config, 2);
  sleep(1);

  // Read 2 bytes of data from register(0x00)
  // temp msb, temp lsb
  char reg[1] = {0x00};
  write(this->file, reg, 1);
  char data[2] = {0};
  if(read(this->file, data, 2) != 2)
        {
		printf("Error : Input/Output error \n");
	}
	else
	{
		// Convert the data to 12-bits
		int temp = (data[0] * 256 + (data[1] & 0xF0)) / 16;
		if(temp > 2047)
		{
			temp -= 4096;
		}
		this->ctemp = temp * 0.0625;
         }
  return this->ctemp;

}  
