//#include <QCoreApplication>

#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class User
{
public:
    User(string tname):name(tname){}

    string getname(){return name;}

private:
    string name;
};

class WebSite
{
public:
    virtual void Use(User *user)=0;
};

class ConcreteWebSite: public WebSite
{
public:
    ConcreteWebSite(string tname):name(tname){}

    virtual void Use(User *user)
    {
        cout<<"WebSite style: "<<name<<"  User:"+user->getname()<<endl;
    }

private:
    string name;
};

class WebSiteFactory
{
public:
    WebSite* GetWebSiteCategory(string key)
    {
        if( !flyweights.count(key) )
        {
            cout<<"test insert"<<endl;
            //flyweights.insert( pair<string,WebSite*>(key, new ConcreteWebSite(key)) );
            flyweights[key] = new ConcreteWebSite(key);
        }

        return flyweights[key];
    }

    int GetWebSiteCount(){
        return flyweights.size();
    }

private:
    map<string,WebSite*>  flyweights;
};

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    cout<<"test"<<endl;
    //return a.exec();

    WebSiteFactory *factory = new WebSiteFactory();

    WebSite* fx = factory->GetWebSiteCategory("Product display");
    fx->Use(new User("Mr.Small"));

    WebSite* fy = factory->GetWebSiteCategory("Product display");
    fy->Use(new User("Mr.Big"));

    WebSite* fz = factory->GetWebSiteCategory("Product display");
    fz->Use(new User("Mr.DD"));

    WebSite* fa = factory->GetWebSiteCategory("Blog");
    fa->Use(new User("aaa"));

    WebSite* fb = factory->GetWebSiteCategory("Blog");
    fb->Use(new User("bbb"));

    WebSite* fc = factory->GetWebSiteCategory("Blog");
    fc->Use(new User("ccc"));

    cout<<"WebSite styles count: "<<factory->GetWebSiteCount()<<endl;
}
