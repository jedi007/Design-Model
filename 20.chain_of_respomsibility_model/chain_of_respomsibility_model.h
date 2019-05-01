#ifndef CHAIN_OF_RESPOMSIBILITY_MODEL_H
#define CHAIN_OF_RESPOMSIBILITY_MODEL_H

#include <QDebug>
#include <QString>

class Handler
{
public:
    Handler(){ successor = NULL; }

    void SetSuccessor(Handler* s)
    {
        successor = s;
    }

    virtual void HandlerRequest(int request)=0;

protected:
    Handler* successor;
};

class ConcreteHandler1:public Handler
{
public:
    virtual void HandlerRequest(int request)
    {
        if(0 <= request && request < 10 )
            qDebug()<<"ConcreteHandler1 handle the request "<<QString::number(request)<<endl;
        else if(successor)
            successor->HandlerRequest(request);
    }
};

class ConcreteHandler2:public Handler
{
public:
    virtual void HandlerRequest(int request)
    {
        if(10 <= request && request < 20 )
            qDebug()<<"ConcreteHandler2 handle the request "<<QString::number(request)<<endl;
        else if(successor)
            successor->HandlerRequest(request);
    }
};

class ConcreteHandler3:public Handler
{
public:
    virtual void HandlerRequest(int request)
    {
        if(20 <= request && request < 30 )
            qDebug()<<"ConcreteHandler3 handle the request "<<QString::number(request)<<endl;
        else if(successor)
            successor->HandlerRequest(request);
    }
};

#endif // CHAIN_OF_RESPOMSIBILITY_MODEL_H
