#ifndef INVOKE_CLASS_H
#define INVOKE_CLASS_H

#include <QObject>
#include <QString>
#include <QDebug>

class invoke_class : public QObject
{
    Q_OBJECT
public:
    explicit invoke_class(QObject *parent = nullptr);

    Q_INVOKABLE QString testButtonClick(int i);

signals:
    void setTextField(QVariant text);

public slots:

};

#endif // INVOKE_CLASS_H
