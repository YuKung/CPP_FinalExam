//
// Created by YuKung on 2022/12/24.
//

#include "CCollectionStation.h"
#include <iostream>
#include <string>
#include <iomanip>

CCollectionStation::CCollectionStation() {};
CCollectionStation::~CCollectionStation() {};

void CCollectionStation::printfInfo(int index) {};

void COrdinaryPoint::printfInfo(int index){                       // 重写虚函数
    std::cout << "\nThis is ordinary point " << index <<std::endl;
    std::cout << "Now there are" << " " <<queue.size() << " " << "ordinary people queuing" << std::endl;
    std::cout << "-----------------------------------------------------------------"<< std::endl;
    std::cout << "Their information is as follows:" << std::endl;

    std::cout << std::setw(5) <<"ID" << std::setw(9)<< "sex" <<std::setw(6) <<"age" << std::endl;
    for (int i = 0; i < queue.size(); ++i) {
        std::string sex;
        auto memberPtr =  queue.front();
        queue.push(memberPtr);
        queue.pop();
        if (memberPtr->gender == 1){
             sex = "male";
        }  // 性别布尔值为1代表男性
        else if(memberPtr->gender == 0){
             sex = "female";
        }
        std::cout <<std::setw(7) << memberPtr->IDNumber <<std::setw(8)<< sex << std::setw(5) << memberPtr->age <<std::endl;   // 打印第一个成员的信息
    };
};

void CDedicatedPoint::printfInfo(int index){
    std::cout << "\nThis is dedicated police " << index <<std::endl;
    std::cout << "Now there are" << " " <<queue.size() << " " << "polices queuing" << std::endl;
    std::cout << "-----------------------------------------------------------------"<< std::endl;
    std::cout << "Their information is as follows:" << std::endl;

    std::cout << std::setw(5) <<"ID" << std::setw(9)<< "sex" <<std::setw(6) <<"age" << std::setw(16) << "police number" <<std::endl;
    for (int i = 0; i < queue.size(); ++i) {
        std::string sex;
        auto memberPtr =  queue.front();
        queue.push(memberPtr);
        queue.pop();
        if (memberPtr->gender == 1){
            sex = "male";
        }  // 性别布尔值为1代表男性
        else if(memberPtr->gender == 0){
            sex = "female";
        }
        std::cout <<std::setw(7) << memberPtr->IDNumber <<std::setw(8)<< sex << std::setw(5) << memberPtr->age << std::setw(10) << memberPtr->getPoliceNumber() <<std::endl;   // 打印第一个成员的信息
    };

};