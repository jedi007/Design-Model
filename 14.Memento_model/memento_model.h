#ifndef MEMENTO_MODEL_H
#define MEMENTO_MODEL_H

#include <QString>
#include <QDebug>

class Memento
{
public:
    explicit Memento(QString s1, QString s2)
        :state1(s1),state2(s2)
    {}
    QString state1;
    QString state2;
};

class Originator
{
public:
    QString state1;
    QString state2;

    Memento* CreateMemento()
    {
        return new Memento(state1,state2);
    }

    void SetMemento(Memento * m)
    {
        state1 = m->state1;
        state2 = m->state2;
    }

    void display(){
        qDebug()<<QString("current state1:%1  ,  state2:%2").arg(state1).arg(state2)<<endl;
    }
};

//备忘录管理者
class Caretaker
{
public:
    Caretaker(){ memento=NULL; }
    Memento * getMemento(){ return memento; }
    void SetMement( Memento *m )
    {
        if(memento)
        {
            delete memento;
            memento = NULL;
        }
        memento = m;
    }

private:
    Memento *memento;
};

#endif // MEMENTO_MODEL_H
