//
// Created by YuKung on 2022/12/24.
//

#include "CPeople.h"

CPeople::CPeople(int IDNumber, bool gender, int age):IDNumber(IDNumber), gender(gender), age(age) {};
CPeople::~CPeople() {};
//void CPeople::GetTypeid() {};
std::string CPeople::GetClassType() {};
int CPeople::getPoliceNumber() {};

COrdinaryPerson::COrdinaryPerson(int idNumber, bool gender, int age): CPeople(idNumber,gender,age){};
COrdinaryPerson::~COrdinaryPerson() {};
std::string COrdinaryPerson::GetClassType() { return "Ordinary Person";};

CPolice::CPolice(int idNumber, bool gender, int age, int policeNumber) : CPeople(idNumber, gender, age),policeNumber(policeNumber) {};
CPolice::~CPolice() {};
std::string CPolice::GetClassType() { return "Police";};
int CPolice::getPoliceNumber(){ return this->policeNumber; };