#ifndef TMP100_H
#define TMP100_H

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <iostream>
using namespace std;

class TMP100
{
 public:
  TMP100();
  void initialize(void);
  float read_temp(void);



 private:
  char* bus;
  int file;
  float ctemp;
};


#endif //TMP100_H
