#ifndef CONTROLTHREAD_H
#define CONTROLTHREAD_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QThread>
#include <unistd.h>

#include <BOX.h>



typedef enum
{
    HOT, AT_SP, COLD, COLDER, COLDEST
} State;


typedef struct
{
    float SP;
    float ONE_LAMP;
    float TWO_LAMP;
    float THREE_LAMP;
    float MAX;

} Setpoint ;

class ControlThread : public QObject
{
    Q_OBJECT
public:
    ControlThread(BOX*);
    ~ControlThread();
    void setMode(bool);
    void currentTemp(float temp);
    void setPoint(float temp);

public slots :
    void process();

signals:
    void finished();
    void error(QString err);

private:
    float temp;
    Setpoint setpoint;
    BOX* box;
    bool mode = 0;

};


#endif // CONTROLTHREAD_H
