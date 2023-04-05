//
// Created by YuKung on 2022/12/24.
//

/* 该头文件包含表示警察的CPolice类和表示普通人的COrdinaryPerson类，以及他们的基类CPeople*/

#ifndef FINALEXAM_CPEOPLE_H
#define FINALEXAM_CPEOPLE_H

#include <string>

class CPeople{         // 基类
private:
public:
    int IDNumber;
    bool gender;                    // 1 代表男，0 代表女
    int age;
    CPeople(int IDNumber, bool gender, int age);
    ~CPeople();
    virtual std::string GetClassType();     // 返回类类型, 运用到了虚函数多态
    virtual int getPoliceNumber();       // 只是为CPolice提供让我们访问Cpolice类中警号的接口，基类中不做具体实现
};


// 以Cpeople为基类派生出COrdinaryPerson和CPolice两个类
class COrdinaryPerson: public CPeople{
public:
    COrdinaryPerson(int idNumber, bool gender, int age);
    ~COrdinaryPerson();
    std::string GetClassType() override;    // 返回类对象的身份
};


class CPolice :public CPeople {
public:
    int policeNumber;
    CPolice(int idNumber, bool gender, int age, int policeNumber);
    ~CPolice();
    std::string GetClassType() override;
    int getPoliceNumber()  override;       // 返回警号 因为所有的对象都存储在基类指针数组中，这种情况下基类没有的成员变量只能通过虚函数访问
};

#endif //FINALEXAM_CPEOPLE_H

