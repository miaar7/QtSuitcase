#include "tempthread.h"

TempThread::TempThread(){}

TempThread::~TempThread(){}

void TempThread::process(){
    // Create I2C bus
    int file;
    int status;
    char *bus = "/dev/i2c-2";
    if ((file = open(bus, O_RDWR)) < 0)
    {
        qDebug() << "Failed to open the bus." ;
    }

    // Get I2C device, TMP100 I2C address is 0x4F(79)
    status = ioctl(file, I2C_SLAVE, 0x48);
    if(status < 0){
        qDebug() << "Error ioctl";

    }
    while(1){

        // Select configuration register(0x01)
        // Continuous conversion, comparator mode, 12-bit resolution(0x60)
        char config[2] = {0};
        config[0] = 0x01;
        config[1] = 0x60;
        status = write(file, config, 2);

        if(status < 0){
            qDebug() << "Error writing i2c config";
        }
        sleep(1);

        // Read 2 bytes of data from register(0x00)
        char reg[1] = {0x00};
        status =  write(file, reg, 1);
        if(status < 0){
            qDebug() << "Error writing i2c register";

        }
        char data[2] = {0};

        status = read(file, data, 2);
        if(status != 2)
        {
            qDebug() << "Input/Output error " << status;
        }
        else
        {
            // Convert the data to 12-bits
            int temp = (data[0] * 256 + (data[1] & 0xF0)) / 16;
            if(temp > 2047)
            {
                temp -= 4096;
            }
            float cTemp = temp * 0.0625; // Celsius
            float fTemp = cTemp * 1.8 + 32; // Fahrenheit

            emit tempChange(cTemp);
        }
    }

}
