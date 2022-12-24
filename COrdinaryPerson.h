//
// Created by YuKung on 2022/12/24.
//
#include "CPeople.h"

#ifndef FINALEXAM_CORDINARYPERSON_H
#define FINALEXAM_CORDINARYPERSON_H


class COrdinaryPerson: public CPeople{
public:
    COrdinaryPerson(int idNumber, bool gender, int age);
    ~COrdinaryPerson();
};


#endif //FINALEXAM_CORDINARYPERSON_H
