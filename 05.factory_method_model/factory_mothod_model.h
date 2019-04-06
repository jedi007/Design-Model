#ifndef FACTORY_MOTHOD_MODEL_H
#define FACTORY_MOTHOD_MODEL_H

#include <QString>
#include <QDebug>

class LeiFeng
{
public:
    LeiFeng(){}

    virtual void Sweep()
    {
        qDebug()<<"扫地"<<endl;
    }

    virtual void Wash()
    {
        qDebug()<<"洗衣"<<endl;
    }

    virtual void BuyRice()
    {
        qDebug()<<"买米"<<endl;
    }
};

//学雷锋的大学生
class Undergraduate: public LeiFeng
{
public:
    Undergraduate(){}
};

//社区志愿者
class Volunteer: public LeiFeng
{
public:
    Volunteer(){}
};

//雷锋工厂
class IFactory
{
public:
    IFactory(){}
    virtual LeiFeng * CreateLeiFeng()=0;
};

//学雷锋大学生工厂
class UndergraduateFactory: public IFactory
{
public:
    UndergraduateFactory(){}
    virtual LeiFeng* CreateLeiFeng()
    {
        return new Undergraduate();
    }
};

//学雷锋志愿者工厂
class VolunteerFactory: public IFactory
{
public:
    VolunteerFactory(){}
    virtual LeiFeng* CreateLeiFeng()
    {
        return new Volunteer();
    }
};

#endif // FACTORY_MOTHOD_MODEL_H
