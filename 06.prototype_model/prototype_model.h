#ifndef PROTOTYPE_MODEL_H
#define PROTOTYPE_MODEL_H


#include <QString>
#include <QDebug>

//为演示深度复制 将工作经历单独设计为一个类
class WorkExperience
{
public:
    WorkExperience(){}

    //设置工作经历
    void SetWorkExperience(QString ttimeArea, QString tcompany)
    {
        timeArea = ttimeArea;
        company  = tcompany;
    }

    QString gettimeArea(){ return timeArea; }
    QString getcompany(){ return company; }

    WorkExperience* Clone()
    {
        return new WorkExperience(*this);
    }
private:
    WorkExperience(WorkExperience &workex)
    {
        qDebug()<<"WorkExperience拷贝构造函数被调用"<<endl;
        SetWorkExperience(workex.gettimeArea(),workex.getcompany());
    }
    QString timeArea;
    QString company;
};

class Resume
{
public:
    Resume(QString tname=""):name(tname){
        workex = new WorkExperience();
    }

    //设置个人信息
    void SetPersonalInfo(QString tsex, QString tage)
    {
        sex = tsex;
        age = tage;
    }

    void SetName(QString tname)
    {
        name = tname;
    }

    //设置工作经历
    void SetWorkExperience(QString ttimeArea, QString tcompany)
    {
        workex->SetWorkExperience(ttimeArea, tcompany);
    }

    //显示
    void Display()
    {
        qDebug()<<QString("姓名：%1 ， 年龄： %2 ， 性别： %3").arg(name).arg(age).arg(sex)<<endl;
        qDebug()<<QString("工作经历：  时间： %1， 公司： %2").arg(workex->gettimeArea()).arg(workex->getcompany())<<endl;
    }

    QString getname(){ return name; }
    QString getsex(){ return sex; }
    QString getage(){ return age; }
    QString gettimeArea(){ return workex->gettimeArea(); }
    QString getcompany(){ return workex->getcompany(); }
    WorkExperience*  getWorkEx(){ return workex; }

    Resume* Clone()
    {
        return new Resume(*this);
    }
private:
    Resume(Resume& r)
    {
        qDebug()<<"Resume拷贝构造函数被调用"<<endl;
        SetName(r.getname());
        SetPersonalInfo(r.getsex(),r.getage());
        workex = r.getWorkEx()->Clone();
    }
    QString name;
    QString sex;
    QString age;
    WorkExperience* workex;
};


#endif // PROTOTYPE_MODEL_H
