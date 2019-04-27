#ifndef SINGLETON_MODEL_H
#define SINGLETON_MODEL_H

#include <QDebug>

//懒汉模式的单例模式，第一次调用时实例化
class Singleton
{
public:
    static Singleton * getSingleton(){
        if(!p)
            p = new Singleton();
        return p;
    }

    int testi;

private:
    Singleton(){ //单例模式实现的关键，私有构造函数
        testi=0;
    }
    static Singleton * p;
};
//Singleton* Singleton::p = NULL;在cpp中

//饿汉版单例模式
class singleton
{
protected:
    singleton()
    {
        testi = 0;
    }
private:
    static singleton* p;
public:
    int testi;
    static singleton* initance();
};

#include <QMutex>
//线程安全的懒汉实现
class safe_singleton
{
protected:
    safe_singleton(){ testi=0; }
private:
    static safe_singleton* p;
    static QMutex mutex;
public:
    int testi;
    static safe_singleton* initance();
};


/*
 * 内部静态变量的懒汉实现

class singleton
{
protected:
    singleton()
    {
        pthread_mutex_init(&mutex);
    }
public:
    static pthread_mutex_t mutex;
    static singleton* initance();
    int a;
};

pthread_mutex_t singleton::mutex;
singleton* singleton::initance()
{
    pthread_mutex_lock(&mutex);
    static singleton obj;
    pthread_mutex_unlock(&mutex);
    return &obj;
}
*/

#endif // SINGLETON_MODEL_H
