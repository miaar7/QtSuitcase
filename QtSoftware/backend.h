#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QTimer>
#include <QString>
#include <QDebug>
#include "BOX.h"

/*
extern "C" {

#include "TMP100.h"
}
*/



class Backend : public QObject
{
     Q_OBJECT
public:


    explicit Backend();
    Q_INVOKABLE void setSetpoint(double);
    Q_INVOKABLE void setFan(float);
    Q_INVOKABLE void setLamp1(bool);
    Q_INVOKABLE void setLamp2(bool);
    Q_INVOKABLE void setLamp3(bool);
    Q_INVOKABLE void setMode(bool);

signals:
    void currentTemperature(QVariant value);

public slots:
    void Tmp100Slot(float);

private:
    QTimer *timer;
    BOX *box;

};

#endif // BACKEND_H




//


