#ifndef FACADE_MODEL_H
#define FACADE_MODEL_H

#include <QDebug>

class SubSystem1
{
public:
    void Method()
    {
        qDebug()<<"SubSystem1 method"<<endl;
    }
};

class SubSystem2
{
public:
    void Method()
    {
        qDebug()<<"SubSystem2 method"<<endl;
    }
};

class SubSystem3
{
public:
    void Method()
    {
        qDebug()<<"SubSystem3 method"<<endl;
    }
};

class SubSystem4
{
public:
    void Method()
    {
        qDebug()<<"SubSystem4 method"<<endl;
    }
};

class Facade
{
public:
    void MethodA()
    {
        s1.Method();
        s2.Method();
        s4.Method();
    }

    void MethodB()
    {
        s2.Method();
        s3.Method();
        s4.Method();
    }

private:
    SubSystem1 s1;
    SubSystem2 s2;
    SubSystem3 s3;
    SubSystem4 s4;
};

#endif // FACADE_MODEL_H
