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


#endif //FINALEXAM_CPEOPLE_H
