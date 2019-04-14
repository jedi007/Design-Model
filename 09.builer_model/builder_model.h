#ifndef BUILDER_MODEL_H
#define BUILDER_MODEL_H

#include <QString>
#include <QList>
#include <QDebug>

class Product
{
public:
    void Addpart(QString part)
    {
        parts.append(part);
    }

    void Show()
    {
        foreach (QString part, parts) {
            qDebug()<<QString("产品创建------- %1").arg(part)<<endl;
        }
    }

private:
    QList<QString> parts;
};

class Builder
{
public:
    Builder()
    {
        product = new Product;
    }
    virtual void BuilderA()=0;
    virtual void BuilderB()=0;
    Product * GetResult()
    {
        return product;
    }

protected:
    Product * product;
};

class ConcreteBuilder1 : public Builder
{
public:
    virtual void BuilderA()
    {
        product->Addpart("1->部件A");
    }

    virtual void BuilderB()
    {
        product->Addpart("1->部件B");
    }
};

class ConcreteBuilder2 : public Builder
{
public:
    virtual void BuilderA()
    {
        product->Addpart("2->部件X");
    }

    virtual void BuilderB()
    {
        product->Addpart("2->部件Y");
    }
};

class Director
{
public:
    void Construct(Builder *builder)
    {
        builder->BuilderA();
        builder->BuilderB();
    }
};

#endif // BUILDER_MODEL_H
