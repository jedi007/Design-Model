#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <QDebug>

class TemplateClass
{
public:
    TemplateClass(){}

    virtual void PrimitveOperation1()=0;
    virtual void PrimitveOperation2()=0;

    void TemplateMethod()
    {
        PrimitveOperation1();
        PrimitveOperation2();
    }

};

class ClassA:public TemplateClass
{
public:
    ClassA(){}
    virtual void PrimitveOperation1()
    {
        qDebug()<<"类A的方法1"<<endl;
    }

    virtual void PrimitveOperation2()
    {
        qDebug()<<"类A的方法2"<<endl;
    }
};

class ClassB:public TemplateClass
{
public:
    ClassB(){}
    virtual void PrimitveOperation1()
    {
        qDebug()<<"类B的方法1"<<endl;
    }

    virtual void PrimitveOperation2()
    {
        qDebug()<<"类B的方法2"<<endl;
    }
};

#endif // TEMPLATECLASS_H
