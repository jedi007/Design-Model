#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include <QString>
#include <QMap>

class Operation
{
public:
    explicit Operation(double A, double B):numberA(A),numberB(B)
    {}

    double getNumberA(){ return numberA; }
    void setNumberA(double A){ numberA = A; }

    double getNumberB(){ return numberB; }
    void setNumberB(double B){ numberB = B; }

    virtual double GetResult()=0;

private:
    double numberA;
    double numberB;
};

class OperationAdd:public Operation
{
public:
    explicit OperationAdd(double A=0, double B=0):Operation(A,B){}
    virtual double GetResult(){
        return getNumberA() + getNumberB();
    }
};

class OperationSub:public Operation
{
public:
    explicit OperationSub(double A=0, double B=0):Operation(A,B){}
    virtual double GetResult(){
        return getNumberA() - getNumberB();
    }
};

class OperationMul:public Operation
{
public:
    explicit OperationMul(double A=0, double B=0):Operation(A,B){}
    virtual double GetResult(){
        return getNumberA() * getNumberB();
    }
};

class OperationDiv:public Operation
{
public:
    explicit OperationDiv(double A=0, double B=0):Operation(A,B){}
    virtual double GetResult(){
        if (getNumberB() == 0)
            return 9999999999999;
        else
            return getNumberA() / getNumberB();
    }
};

class OperationFactory
{
public:
    OperationFactory()
    {
        operator_map.clear();
        operator_map.insert("+",0);
        operator_map.insert("-",1);
        operator_map.insert("*",2);
        operator_map.insert("/",3);
    }

    QMap<QString,int> operator_map;

    Operation* createOperate(QString stroperator)
    {
        Operation* oper = NULL;

        if( !operator_map.contains(stroperator) )
            return oper;
        int oper_SN = operator_map[stroperator];

        switch (oper_SN) {
        case 0:
            oper = new OperationAdd();
            break;
        case 1:
            oper = new OperationSub();
            break;
        case 2:
            oper = new OperationMul();
            break;
        case 3:
            oper = new OperationDiv();
            break;
        default:
            break;
        }
        return oper;
    }
};

#endif // OPERATIONFACTORY_H
