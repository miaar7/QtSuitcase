#ifndef BOX_H
#define BOX_H

#include<iostream>
#include<fstream>
#include<unistd.h>
#include<string>

#include <QString>
#include <QDebug>
#include "GPIO.h"
#include "PWM.h"
#include "tempthread.h"

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>


using namespace std;

 class BOX :public QObject
 {
    Q_OBJECT
 public:
      BOX();
      void set_lamp1(void);
      void set_lamp2(void);
      void set_lamp3(void);
      void reset_lamp1(void);
      void reset_lamp2(void);
      void reset_lamp3(void);
      void set_fan_speed(void);
      void stop_fan(void);
      QString get_gpioState();
      float temp(void);

 public slots:

      void slotTempChange(float temp);

 private:
      GPIO* lamp_1;
      GPIO* lamp_2;
      GPIO* lamp_3;
      GPIO* fan;
      // PWM* fan;
      QThread* thread;
      TempThread* tempThread;

signals:
      void sigTempChange(float);

  // TMP100* tmp;
//  GPIO* rasp; // For home testing on RPi
};
#endif //BOX_H
