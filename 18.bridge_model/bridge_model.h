#ifndef BRIDGE_MODEL_H
#define BRIDGE_MODEL_H

#include <QString>
#include <QDebug>

class base
{
public:
    QString name;
};

class Implementor1
{
public:
    virtual void Operation1()=0;
};

class Implementor2
{
public:
    virtual void Operation2()=0;
};

class ConcreteImplementorA: public base,public Implementor1,public Implementor2  //多继承，父类为虚基类。与OC和swift中面向协议编程的思想很像
{
public:
    ConcreteImplementorA(){ name="ConcreteImplementorA"; }
    virtual void Operation1()
    {
        qDebug()<<QString("具体实现 %1 的 Operation1() 方法").arg(name)<<endl;
    }

    virtual void Operation2()
    {
        qDebug()<<QString("具体实现 %1 的 Operation2() 方法").arg(name)<<endl;
    }
};

class ConcreteImplementorB: public base,public Implementor1,public Implementor2  //多继承，父类为虚基类。与OC和swift中面向协议编程的思想很像
{
public:
    ConcreteImplementorB(){ name="ConcreteImplementorB"; }
    virtual void Operation1()
    {
        qDebug()<<QString("具体实现 %1 的 Operation1() 方法").arg(name)<<endl;
    }

    virtual void Operation2()
    {
        qDebug()<<QString("具体实现 %1 的 Operation2() 方法").arg(name)<<endl;
    }
};

class Abstraction
{
public:
    Abstraction(){ im1=NULL; }
    void SetImplementor(Implementor1 *tim1){
        im1 = tim1;
    }
    virtual void operation()=0;
protected:
    Implementor1 *im1;
};

class RefineAction:public Abstraction
{
public:
    virtual void operation()
    {
        if(im1)
            im1->Operation1();
    }
};

#endif // BRIDGE_MODEL_H
