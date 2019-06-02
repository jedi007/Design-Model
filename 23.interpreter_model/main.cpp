//#include <QCoreApplication>

#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

class Context
{
public:
    Context() {}

    void set_input(string tin){input = tin;}
    string get_input(){ return input;}

    void set_output(string tout){output = tout;}
    string get_output(){ return output; }

private:
    string input;
    string output;
};

class AbstractExpression
{
public:
    virtual void Interpret(Context*)=0;
};

class TerminalExpression: public AbstractExpression
{
public:
    virtual void Interpret(Context*)
    {
        cout<<"Terminal Interpret"<<endl;
    }
};

class NonterminalExpression: public AbstractExpression
{
public:
    virtual void Interpret(Context*)
    {
        cout<<"Nonterminal Interpret"<<endl;
    }
};


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    Context * context = new Context();

    list<AbstractExpression*> alist;
    alist.push_back(new NonterminalExpression());
    alist.push_back(new NonterminalExpression());
    alist.push_back(new TerminalExpression());
    alist.push_back(new NonterminalExpression());
    alist.push_back(new TerminalExpression());

    list<AbstractExpression*>::iterator it;
    for (it = alist.begin(); it != alist.end(); ++it)
    {
        (*it)->Interpret(context);
    }

}
