#ifndef TEMPTHREAD_H
#define TEMPTHREAD_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QThread>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

class TempThread : public QObject
{
    Q_OBJECT
public:
    TempThread();
    ~TempThread();

public slots :
    void process();

signals:
    void tempChange(float value);
    void finished();
    void error(QString err);
};

#endif // TEMPTHREAD_H
