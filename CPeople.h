//
// Created by YuKung on 2022/12/24.
//

#ifndef FINALEXAM_CPEOPLE_H
#define FINALEXAM_CPEOPLE_H

#include <string>

class CPeople{
private:
    int IDNumber;
    bool gender;                    // 1代表男，0代表女


public:
    int age;
    CPeople(int IDNumber, bool gender, int age);
    ~CPeople();
   /* virtual void GetTypeid();   // 纯虚函数只是为了使typeid关键字能够区分派生类*/
    virtual std::string GetClassType();     // 返回类类型, 运用到了虚函数多态
};


// 以Cpeople为基类派生出COrdinaryPerson和CPolice两个类
class COrdinaryPerson: public CPeople{
public:
    COrdinaryPerson(int idNumber, bool gender, int age);
    ~COrdinaryPerson();
    std::string GetClassType() override;
};


class CPolice :public CPeople {
private:
    int policeNumber;

public:
    CPolice(int idNumber, bool gender, int age, int policeNumber);
    ~CPolice();
    std::string GetClassType() override;
};

#endif //FINALEXAM_CPEOPLE_H

