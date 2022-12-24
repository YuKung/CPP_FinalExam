//
// Created by YuKung on 2022/12/24.
//

#ifndef FINALEXAM_CCOLLECTIONSTATION_H
#define FINALEXAM_CCOLLECTIONSTATION_H

#include <queue>
#include "CPeople.h"

template<class T>
class CCollectionStation {
public:
    CCollectionStation();
    ~CCollectionStation();
    std::queue<T> queue;              // 从模板类继承 提高代码可重用性 比如以后还能方便地继承得到更多类型的检测点！！！！
private:

};

class COrdinaryPoint:public CCollectionStation<COrdinaryPerson>{

};

class CDedicatedPoint:public CCollectionStation<CPolice>{


};

#endif //FINALEXAM_CCOLLECTIONSTATION_H
