#ifndef ABSTRACT_FACRORY_MODEL_H
#define ABSTRACT_FACRORY_MODEL_H

#include <QString>
#include <QDebug>

class User
{
public:
    QString name;
    int age;
    int id;
};

class IUser
{
public:
    virtual void insert(User *user)=0;
    virtual User* GetUser(int id)=0;
};

class SqlserverUser : public IUser
{
public:
    virtual void insert(User *user)
    {
        qDebug()<<"在SQL Server 中给 User 表增加一条记录"<<endl;
    }
    virtual User* GetUser(int id)
    {
        qDebug()<<"在SQL Server 中根据ID 得到 User 表一条记录"<<endl;
        return NULL;
    }
};

class AccessUser : public IUser
{
public:
    virtual void insert(User *department)
    {
        qDebug()<<"在Access 中给 User 表增加一条记录"<<endl;
    }
    virtual User* GetUser(int id)
    {
        qDebug()<<"在Access 中根据ID 得到 User 表一条记录"<<endl;
        return NULL;
    }
};

class Department
{
public:
    int id;
    QString dept_name;
};

class IDepartment
{
public:
    virtual void insert(Department *department)=0;
    virtual Department* GetDepartment(int id)=0;
};

class SqlserverDepartment : public IDepartment
{
public:
    SqlserverDepartment(){}
    virtual void insert(Department *department)
    {
        qDebug()<<"在SQL Server 中给 Department 表增加一条记录"<<endl;
    }
    virtual Department* GetDepartment(int id)
    {
        qDebug()<<"在SQL Server 中根据ID 得到 Department 表一条记录"<<endl;
        return NULL;
    }
};

class AccessDepartment : public IDepartment
{
public:
    virtual void insert(Department *department)
    {
        qDebug()<<"在Access 中给 Department 表增加一条记录"<<endl;
    }
    virtual Department* GetDepartment(int id)
    {
        qDebug()<<"在Access 中根据ID 得到 Department 表一条记录"<<endl;
        return NULL;
    }
};

class IFactory
{
public:
    virtual IUser* CreateUser()=0;
    virtual IDepartment* CreateDepartment()=0;
};

class SqlserverFactory: public IFactory
{
public:
    virtual IUser* CreateUser()
    {
        return new SqlserverUser();
    }

    virtual IDepartment* CreateDepartment()
    {
        return new SqlserverDepartment();
    }
};

class AccessFactory: public IFactory
{
public:
    virtual IUser* CreateUser()
    {
        return new AccessUser();
    }

    virtual IDepartment* CreateDepartment()
    {
        return new AccessDepartment();
    }
};

























#endif // ABSTRACT_FACRORY_MODEL_H
