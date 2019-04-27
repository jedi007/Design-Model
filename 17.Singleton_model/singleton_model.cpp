#include "singleton_model.h"

//懒汉
Singleton* Singleton::p = NULL;

//饿汉
singleton* singleton::p = new singleton;
singleton* singleton::initance()
{
    return p;
}

//线程安全的懒汉实现
safe_singleton* safe_singleton::p = NULL;
QMutex safe_singleton::mutex;
safe_singleton* safe_singleton::initance()
{
    if (p == NULL)
    {
        mutex.lock();
        if (p == NULL)
            p = new safe_singleton();
        mutex.unlock();
    }
    return p;
}
