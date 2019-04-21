#ifndef STATE_MODEL_H
#define STATE_MODEL_H

#include <QString>
#include <QDebug>

class Work;
class ForenoonState;
class State
{
public:
    virtual void WriteProgram(Work * w)=0;
    virtual ~State(){}
};

//工作
class Work
{
public:
    Work();//{ currentState = new ForenoonState();Hour = 8;WorkFinish=false; }
    double Hour;
    bool WorkFinish;

    void SetState(State *s){ delete currentState; currentState = s; }

    void WriteProgram(){
        currentState->WriteProgram(this);
    }

private:
    State *currentState;

};

//休息状态
class RestState:public State
{
public:
    virtual ~RestState(){}
    virtual void WriteProgram(Work* w)
    {
        qDebug()<<QString("当前时间: %1点 下班回家").arg(w->Hour)<<endl;
    }
};

//睡眠状态
class SleepingState:public State
{
public:
    virtual ~SleepingState(){}
    virtual void WriteProgram(Work *w)
    {
        qDebug()<<QString("当前时间: %1点 效率太低，快睡着了").arg(w->Hour)<<endl;
    }
};

//晚间工作状态
class EveningState:public State
{
public:
    virtual ~EveningState(){}
    virtual void WriteProgram(Work * w)
    {
        if(w->WorkFinish)
        {
            w->SetState(new RestState());
            w->WriteProgram();
        }
        else
        {
            if(w->Hour < 21)
            {
                qDebug()<<QString("当前时间: %1点 加班咯，效率下降").arg(w->Hour)<<endl;
            }
            else
            {
                w->SetState(new SleepingState());
                w->WriteProgram();
            }
        }

    }
};

//下午和傍晚工作状态
class AfternoonState:public State
{
public:
    virtual ~AfternoonState(){}
    virtual void WriteProgram(Work * w)
    {
        if(w->Hour < 17)
        {
            qDebug()<<QString("当前时间: %1点 下午状态还不错，继续努力").arg(w->Hour)<<endl;
        }
        else
        {
            w->SetState(new EveningState());
            w->WriteProgram();
        }
    }
};

//中午工作状态
class NoonState:public State
{
public:
    virtual ~NoonState(){}
    virtual void WriteProgram(Work * w)
    {
        if(w->Hour < 13)
        {
            qDebug()<<QString("当前时间: %1点 午饭、晕饭、午休").arg(w->Hour)<<endl;
        }
        else
        {
            w->SetState(new AfternoonState());
            w->WriteProgram();
        }
    }
};

//上午工作状态
class ForenoonState:public State
{
public:
    virtual ~ForenoonState(){}
    virtual void WriteProgram(Work * w)
    {
        if(w->Hour < 12)
        {
            qDebug()<<QString("当前时间: %1点 上午工作，精神百倍").arg(w->Hour)<<endl;
        }
        else
        {
            w->SetState(new NoonState());
            w->WriteProgram();
        }
    }
};





























#endif // STATE_MODEL_H
