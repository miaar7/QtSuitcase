#ifndef TMPTIMER_H
#define TMPTIMER_H

#include <QtCore>

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>

class Tmp100Timer : public QObject
{
    Q_OBJECT
public:
    Tmp100Timer();
    QTimer *timer;


private:
    ofstream write;
    ifstream read;

public slots:
    void Tmp100Slot();

};

#endif // TMPTIMER_H
