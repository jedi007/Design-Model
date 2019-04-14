#ifndef OBSERVER_MODEL_H
#define OBSERVER_MODEL_H

#include <QList>
#include <QDebug>

class Observer
{
public:
    virtual void Update() = 0;
};

class Subject
{
public:
    //添加观察者
    void Attach(Observer *o)
    {
        Observers.append(o);
    }
    //移除观察者
    void Detach(Observer *o)
    {
        Observers.removeOne(o);
    }
    //通知观察者
    void Notify()
    {
        foreach (Observer * o, Observers) {
            o->Update();
        }
    }

private:
    QList<Observer *> Observers;
};

class ConcreteSubject : public Subject
{
public:
    QString getState(){ return subjectState; }
    void setState(QString s){ subjectState = s; }
private:
    QString subjectState;
};

class ConcreteObserver: public Observer
{
public:
    ConcreteObserver(ConcreteSubject * s, QString tname){
        subject = s;
        name = tname;
    }

    void Update(){
        observerState = subject->getState();
        qDebug()<<QString("观察者%1的新状态是%2").arg(name).arg(observerState)<<endl;
    }

private:
    QString name;
    QString observerState;
    ConcreteSubject * subject;
};


#endif // OBSERVER_MODEL_H
