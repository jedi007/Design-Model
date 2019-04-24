#ifndef COMPOSITE_MODEL_H
#define COMPOSITE_MODEL_H

#include <QString>
#include <QDebug>

class Compoent
{
public:
    Compoent(QString tname):name(tname)
    {}

    virtual void Add(Compoent *c)=0;
    virtual void Remove(Compoent *c)=0;
    virtual void Display(QString basem="")=0;

protected:
    QString name;
};

class Leaf:public Compoent
{
public:
    Leaf(QString tname):Compoent(tname)
    {}

    virtual void Add(Compoent *c)
    {
        qDebug()<<"Can not add to a leaf"<<endl;
    }

    virtual void Remove(Compoent *c)
    {
        qDebug()<<"Can not remove from a leaf"<<endl;
    }

    virtual void Display(QString basem="")
    {
        basem = QString("%1%2").arg(basem).arg(name);
        qDebug()<<basem<<flush;
    }
};

class Composite: public Compoent
{
public:
    Composite(QString tname):Compoent(tname)
    {}

    virtual void Add(Compoent *c)
    {
        children.append(c);
    }

    virtual void Remove(Compoent *c)
    {
        children.removeOne(c);
    }

    virtual void Display(QString basem="")
    {
        basem = QString("%1%2 -> ").arg(basem).arg(name);
        qDebug()<<basem<<flush;
        foreach (Compoent *c, children) {
            c->Display(basem);
        }
    }

private:
    QList<Compoent *> children;
};

#endif // COMPOSITE_MODEL_H
