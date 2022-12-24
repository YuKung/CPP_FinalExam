//
// Created by YuKung on 2022/12/24.
//

#ifndef FINALEXAM_CPEOPLE_H
#define FINALEXAM_CPEOPLE_H

#include <string>

class CPeople{
private:
public:
    int IDNumber;
    bool gender;                    // 1代表男，0代表女
    int age;
    CPeople(int IDNumber, bool gender, int age);
    ~CPeople();
   /* virtual void GetTypeid();         // 纯虚函数只是为了使typeid关键字能够区分派生类*/
    virtual std::string GetClassType();     // 返回类类型, 运用到了虚函数多态
    virtual int getPoliceNumber();       // 只是在基类中提供让我们访问Cpolice类中警号的借口，并不做具体实现！！！
};


// 以Cpeople为基类派生出COrdinaryPerson和CPolice两个类
class COrdinaryPerson: public CPeople{
public:
    COrdinaryPerson(int idNumber, bool gender, int age);
    ~COrdinaryPerson();
    std::string GetClassType() override;
};


class CPolice :public CPeople {
public:
    CPolice(int idNumber, bool gender, int age, int policeNumber);
    ~CPolice();
    int policeNumber;
    std::string GetClassType() override;
    int getPoliceNumber()  override;
};

#endif //FINALEXAM_CPEOPLE_H

