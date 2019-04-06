#ifndef PROXY_MODEL_H
#define PROXY_MODEL_H

#include <QString>
#include <QDebug>

class IGiveGift
{
public:
    IGiveGift(){}

    virtual void GiveDolls()=0;
    virtual void GiveFlowers()=0;
    virtual void GiveChocolate()=0;
};

//被追求者类
class SchoolGirl
{
public:
    SchoolGirl(){}

    QString getName(){ return name; }
    void setName(QString tname){ name = tname; }

private:
    QString name;
};

//追求者类
class Pursuit:public IGiveGift
{
public:
    Pursuit(SchoolGirl *tmm):mm(tmm) {}
    virtual ~Pursuit(){}

    void GiveDolls()
    {
        qDebug()<<QString("%1  送你洋娃娃").arg(mm->getName())<<endl;
    }

    void GiveFlowers()
    {
        qDebug()<<QString("%1  送你鲜花").arg(mm->getName())<<endl;
    }

    void GiveChocolate()
    {
        qDebug()<<QString("%1  送你巧克力").arg(mm->getName())<<endl;
    }

private:
    SchoolGirl *mm;
};

class Proxy:public IGiveGift
{
public:
    Proxy(SchoolGirl *tmm)
    {
        gg = new Pursuit(tmm);
    }
    virtual ~Proxy()
    {
        delete gg;
        gg = NULL;
    }

    void GiveDolls()
    {
        gg->GiveDolls();
    }

    void GiveFlowers()
    {
        gg->GiveFlowers();
    }

    void GiveChocolate()
    {
        gg->GiveChocolate();
    }

private:
    Pursuit* gg;
};

//案例二-智能指针
template<class T>
class auto_ptr {
public:
    explicit auto_ptr(T *p = 0): pointee(p) {}
    auto_ptr(auto_ptr<T>& rhs): pointee(rhs.release()) {}
    ~auto_ptr() { delete pointee; }
    auto_ptr<T>& operator=(auto_ptr<T>& rhs)
    {
        if (this != &rhs) reset(rhs.release());
        return *this;
    }
    T& operator*() const { return *pointee; }
    T* operator->() const { return pointee; }
    T* get() const { return pointee; }
    T* release()
    {
        T *oldPointee = pointee;
        pointee = 0;
        return oldPointee;
    }
    void reset(T *p = 0)
    {
        if (pointee != p) {
               delete pointee;
               pointee = p;
            }
        }
private:
    T *pointee;
};


#endif // PROXY_MODEL_H
