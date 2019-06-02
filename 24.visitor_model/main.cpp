//#include <QCoreApplication>

#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
    Visitor() {}
    virtual void VisitorConcreteElementA(ConcreteElementA *A)=0;
    virtual void VisitorConcreteElementB(ConcreteElementB *B)=0;
};

class ConcreteVisitor1: public Visitor
{
public:
    virtual void VisitorConcreteElementA(ConcreteElementA *A)
    {
        cout<<"ConcreteVisitor1 visit ConcreteElementA"<<endl;
    }
    virtual void VisitorConcreteElementB(ConcreteElementB *B)
    {
        cout<<"ConcreteVisitor1 visit ConcreteElementB"<<endl;
    }
};

class ConcreteVisitor2: public Visitor
{
public:
    virtual void VisitorConcreteElementA(ConcreteElementA *A)
    {
        cout<<"ConcreteVisitor2 visit ConcreteElementA"<<endl;
    }
    virtual void VisitorConcreteElementB(ConcreteElementB *B)
    {
        cout<<"ConcreteVisitor2 visit ConcreteElementB"<<endl;
    }
};

class Element
{
public:
    virtual void accept(Visitor *v)=0;
};

class ConcreteElementA: public Element
{
public:
    virtual void accept(Visitor *v)
    {
        v->VisitorConcreteElementA(this);
    }

    void OperatorOther(){}
};

class ConcreteElementB: public Element
{
public:
    virtual void accept(Visitor *v)
    {
        v->VisitorConcreteElementB(this);
    }

    void OperatorOther(){}
};

class ObjectStructure
{
public:
    void Attach(Element *e)
    {
        elements.push_back(e);
    }

    void Detach(Element *e)
    {
        elements.remove(e);
    }

    void Accept(Visitor *v)
    {
        list<Element *>::iterator it;
        for (it = elements.begin(); it != elements.end(); ++it)
        {
            (*it)->accept(v);
        }
    }

private:
    list<Element *> elements;
};


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    ObjectStructure ObjStructure;
    ObjStructure.Attach(new ConcreteElementA());
    ObjStructure.Attach(new ConcreteElementB());

    ConcreteVisitor1 *v1 = new ConcreteVisitor1();
    ConcreteVisitor2 *v2 = new ConcreteVisitor2();

    ObjStructure.Accept(v1);
    cout<<"==========================="<<endl;
    ObjStructure.Accept(v2);
}
