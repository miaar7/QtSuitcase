#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QDebug>


class Backend : public QObject
{
        Q_OBJECT
public:



    explicit Backend();
    Q_INVOKABLE void setSetpoint(double);
    Q_INVOKABLE void setFan(int);
    Q_INVOKABLE void setLamp1(char);
    Q_INVOKABLE void setLamp2(char);
    Q_INVOKABLE void setLamp3(char);
    Q_INVOKABLE void setMode(char);

signals:
        void currentTemperature(QVariant);


// public slots:
};

#endif // BACKEND_H




//


