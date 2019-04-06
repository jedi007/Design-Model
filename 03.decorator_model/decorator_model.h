#ifndef DECORATOR_MODEL_H
#define DECORATOR_MODEL_H

#include <QString>
#include <QDebug>

class base_component
{
public:
    base_component(){}
    virtual void show()=0;
};

class Person:public base_component
{
public:
    Person(QString tname):name(tname){}

    virtual void show(){
        qDebug()<<QString("装扮 ==== %1").arg(name)<<endl;
    }

private:
    QString name;
};

class Finery:public base_component
{
public:
    Finery(){ person = NULL; }
    void decorate(base_component *tperson){ person = tperson; }

    virtual void show(){
        if( person )
        {
            person->show();
        }
    }

protected:
    base_component *person;
};

class TShirts:public Finery
{
public:
    TShirts(){}

    virtual void show()
    {
        qDebug()<<"大T恤"<<flush;
        Finery::show();
    }
};

class BigUnderpants:public Finery
{
public:
    BigUnderpants(){}

    virtual void show()
    {
        qDebug()<<"大裤衩"<<flush;
        Finery::show();
    }
};

class LeatherShoes:public Finery
{
public:
    LeatherShoes(){}

    virtual void show()
    {
        qDebug()<<"皮鞋"<<flush;
        Finery::show();
    }
};

class Tie:public Finery
{
public:
    Tie(){}

    virtual void show()
    {
        qDebug()<<"领带"<<flush;
        Finery::show();
    }
};

class BusinessSuit:public Finery
{
public:
    BusinessSuit(){}

    virtual void show()
    {
        qDebug()<<"西装"<<flush;
        Finery::show();
    }
};

class decorator_model
{
public:
    decorator_model();
};

#endif // DECORATOR_MODEL_H
