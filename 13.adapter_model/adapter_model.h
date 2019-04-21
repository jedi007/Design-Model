#ifndef ADAPTER_MODEL_H
#define ADAPTER_MODEL_H

#include <QString>
#include <QDebug>

class Target
{
public:
    virtual void Request()
    {
        qDebug()<<"普通请求"<<endl;
    }
};

//需要适配器的类
class Adaptee
{
public:
    void SpecificRequest()
    {
        qDebug()<<"特殊请求"<<endl;
    }
};

class Adapter: public Target
{
public:
    virtual void Request()
    {
        adptee.SpecificRequest();
    }

private:
    Adaptee adptee;
};

#endif // ADAPTER_MODEL_H
