#ifndef COMMAND_MODEL_H
#define COMMAND_MODEL_H

#include <QDebug>

class Receiver
{
public:
    void Action()
    {
        qDebug()<<"执行请求"<<endl;
    }
};

class Command
{
public:
    Command(Receiver *r):receiver(r){}

    virtual void Execute()=0;
protected:
    Receiver *receiver;
};

class ConcreteCommand:public Command
{
public:
    ConcreteCommand(Receiver *r):Command(r){}

    virtual void Execute()
    {
        if(receiver)
            receiver->Action();
    }
};

class Invoker
{
public:
    void SetCommand(Command * c)
    {
        command = c;
    }

    void ExcuteCommand()
    {
        if(command)
            command->Execute();
    }
private:
    Command * command;
};

#endif // COMMAND_MODEL_H
