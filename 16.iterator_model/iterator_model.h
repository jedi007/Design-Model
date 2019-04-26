#ifndef ITERATOR_MODEL_H
#define ITERATOR_MODEL_H

#include <QList>
#include <QDebug>
#include <QString>

/*
 使用 QList<obj*> objs 模拟的数据，现实中实际数据结构会复杂得多

 */

class obj
{
public:
    QString name;
};

//集合的对象
class Aggregate
{
public:
    Aggregate(){
        obj *o1 = new obj;
        o1->name = "name-o1";
        objs.append(o1);

        obj *o2 = new obj;
        o2->name = "name-o2";
        objs.append(o2);

        obj *o3 = new obj;
        o3->name = "name-o3";
        objs.append(o3);
    }

    obj* operator [](int index){
        if(index>=0 && index < objs.count())
            return objs[index];
        else return NULL;
    }

    int getcount(){
        return objs.count();
    }

private:
    QList<obj*> objs;
};

//具体迭代器功能
class Iterator
{
public:
    Iterator(Aggregate *a):aggregate(a){current_index=0;}

    int current_index;
    virtual obj* First(){return (*aggregate)[0];}
    virtual obj* Next(){
        obj* oj = NULL;
        if( current_index < aggregate->getcount()-1)
        {
            ++current_index;
            oj = (*aggregate)[current_index];
        }
         return oj;
    }
    virtual bool isDone(){ return true; }
    virtual obj* CurrentItem(){ return (*aggregate)[current_index];}

private:
    Aggregate *aggregate;
};


#endif // ITERATOR_MODEL_H
