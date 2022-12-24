//
// Created by YuKung on 2022/12/24.
//

#ifndef FINALEXAM_CPEOPLE_H
#define FINALEXAM_CPEOPLE_H

class CPeople{
private:
    int IDNumber;
    bool gender;                    // 0代表男，1代表女
    int age;

public:
    CPeople(int IDNumber, bool gender, int age);
    ~CPeople();
};


// 以Cpeople为基类派生出COrdinaryPerson和CPolice两个类
class COrdinaryPerson: public CPeople{
public:
    COrdinaryPerson(int idNumber, bool gender, int age);
    ~COrdinaryPerson();
};


class CPolice :public CPeople {
private:
    int policeNumber;

public:
    CPolice(int idNumber, bool gender, int age, int policeNumber);
    ~CPolice();
};

#endif //FINALEXAM_CPEOPLE_H
