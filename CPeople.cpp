//
// Created by YuKung on 2022/12/24.
//

#include "CPeople.h"

CPeople::CPeople(int IDNumber, bool gender, int age):IDNumber(IDNumber), gender(gender), age(age) {};
CPeople::~CPeople() {};

COrdinaryPerson::COrdinaryPerson(int idNumber, bool gender, int age): CPeople(idNumber,gender,age){};
COrdinaryPerson::~COrdinaryPerson() {};

CPolice::CPolice(int idNumber, bool gender, int age, int policeNumber) : CPeople(idNumber, gender, age),policeNumber(policeNumber) {};
CPolice::~CPolice() {};