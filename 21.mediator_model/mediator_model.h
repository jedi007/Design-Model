#ifndef MEDIATOR_MODEL_H
#define MEDIATOR_MODEL_H

#include <QString>
#include <QDebug>

class Mediator;
class Colleague
{
public:
     Colleague(Mediator* m):mediator(m){}

protected:
     Mediator* mediator;
};

class Mediator
{
public:
    virtual void Send(QString message,Colleague* colleague)=0;
};

class ConcreteColleague1: public Colleague
{
public:
      ConcreteColleague1(Mediator *mediator):Colleague(mediator){}

      void Send(QString message)
      {
          mediator->Send(message,this);
      }

      void Nodify(QString message)
      {
          qDebug()<<"同事1得到消息："<<message<<endl;
      }
};

class ConcreteColleague2: public Colleague
{
public:
      ConcreteColleague2(Mediator *mediator):Colleague(mediator){}

      void Send(QString message)
      {
          mediator->Send(message,this);
      }

      void Nodify(QString message)
      {
          qDebug()<<"同事2得到消息："<<message<<endl;
      }
};

class ConcreteMediator: public Mediator
{
public:
    ConcreteColleague1* colleague1;
    ConcreteColleague2* colleague2;

    virtual void Send(QString message, Colleague* colleague)
    {
        if(colleague == colleague1)
        {
            colleague2->Nodify(message);
        }
        else
        {
            colleague1->Nodify(message);
        }
    }
};

#endif // MEDIATOR_MODEL_H
