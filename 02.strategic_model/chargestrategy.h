#ifndef CHARGESTRATEGY_H
#define CHARGESTRATEGY_H

#include <QString>

class ChargeStrategy
{
public:
    ChargeStrategy();

    virtual double acceptCash(double money)=0;
};

class CrashNormal:public ChargeStrategy
{
public:
    virtual double acceptCash(double money)
    {
        return money;
    }
};

//打折收费
class CrashRebate:public ChargeStrategy
{
public:
    CrashRebate(QString rebate){
        moneyRebate = rebate.toDouble();
    }
    virtual double acceptCash(double money)
    {
        return money*moneyRebate;
    }

private:
    double moneyRebate;
};

//返现收费
class CrashReturn:public ChargeStrategy
{
public:
    CrashReturn(QString mCondition, QString mReturn){
        moneyCondition = mCondition.toDouble();
        moneyReturn    = mReturn.toDouble();
    }
    virtual double acceptCash(double money)
    {
        double cReturn = int(money/moneyCondition)*moneyReturn;
        return money-cReturn;
    }

private:
    double moneyCondition;
    double moneyReturn;
};

class ChargeStrategyController
{
public:
    ChargeStrategyController(QString type){
        if(type == "正常收费")
            cs = new CrashNormal();
        else if(type == "满300反100")
            cs = new CrashReturn("300","100");
        else if(type == "打8折")
            cs = new CrashRebate("0.8");
    }

    double GetResult(double money){
        return cs->acceptCash(money);
    }

private:
    ChargeStrategy *cs;
};

#endif // CHARGESTRATEGY_H
